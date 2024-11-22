import ray
from PIL import Image
import cv2
import os
import numpy as np

@ray.remote
def process_image(image_path, target_size=None):
  """
  Convierte una imagen a escala de grises y la redimensiona a un tamaño objetivo.
  :param image_path: Ruta de la imagen.
  :param target_size: Tamaño objetivo (width, height). Si es None, no se redimensiona.
  :return: Imagen en escala de grises como un array.
  """
  try:
    node_ip = ray._private.services.get_node_ip_address()  # Obtén la IP del nodo
    print(f"Procesando {image_path} en nodo {node_ip}")

    # Abrir la imagen
    image = Image.open(image_path)

    # Convertir a escala de grises
    grayscale_image = image.convert("L")

    # Redimensionar si se especifica un tamaño objetivo
    if target_size:
      grayscale_image = grayscale_image.resize(target_size)

    # Convertir de PIL a formato compatible con OpenCV (BGR)
    grayscale_cv2 = cv2.cvtColor(np.array(grayscale_image), cv2.COLOR_GRAY2BGR)

    return grayscale_cv2
  except Exception as e:
    raise ValueError(f"Error procesando la imagen {image_path}: {e}")

def create_video_from_images(image_paths, video_path, fps=1):
  """
  Genera un video a partir de una lista de imágenes procesadas en paralelo.
  :param image_paths: Lista de rutas de las imágenes.
  :param video_path: Ruta del archivo de video de salida.
  :param fps: Fotogramas por segundo.
  """
  if not image_paths:
    raise ValueError("No hay imágenes para crear el video.")

  # Determinar el tamaño objetivo de las imágenes basado en la primera imagen
  first_image = Image.open(image_paths[0])
  target_size = first_image.size  # (width, height)

  # Procesar imágenes en paralelo con Ray
  image_refs = [process_image.remote(img_path, target_size) for img_path in image_paths]
  images = ray.get(image_refs)

  # Configuración del video
  height, width = target_size[1], target_size[0]  # Invertir porque PIL usa (width, height)
  fourcc = cv2.VideoWriter_fourcc(*"XVID")
  video_writer = cv2.VideoWriter(video_path, fourcc, fps, (width, height))

  # Escribir imágenes en el video
  for idx, image in enumerate(images):
    try:
      video_writer.write(image)
      print(f"Imagen {idx + 1}/{len(images)} agregada al video.")
    except Exception as e:
      print(f"Error al agregar la imagen {idx + 1}: {e}")
      continue

  video_writer.release()
  print(f"Video creado exitosamente: {video_path}")

def get_image_paths_from_directory(directory, extensions=("jpg", "png", "jpeg")):
  """
  Obtiene todas las rutas de las imágenes en un directorio dado.
  :param directory: Directorio donde buscar imágenes.
  :param extensions: Extensiones de archivo a considerar como imágenes.
  :return: Lista de rutas de imágenes.
  """
  return [os.path.join(directory, file) for file in os.listdir(directory) if file.lower().endswith(extensions)]

# Ejemplo de uso
if __name__ == "__main__":
  ray.init()

  try:
    # Directorio de imágenes
    image_directory = "input_images"  # Cambia esta ruta al directorio que contiene las imágenes
    output_video_path = "output_video.avi"

    # Obtener y ordenar las imágenes
    image_paths = get_image_paths_from_directory(image_directory)
    image_paths.sort()
    print(f"Rutas de imágenes procesadas: {image_paths}")

    # Crear el video
    create_video_from_images(image_paths, output_video_path, fps=0.5)
  finally:
      ray.shutdown()