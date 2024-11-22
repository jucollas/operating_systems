import os
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

def download_image(image_url, save_folder):
    """
    Descarga una imagen desde la URL proporcionada.
    :param image_url: URL de la imagen.
    :param save_folder: Carpeta donde se guardará la imagen.
    """
    try:
        # Hacer una solicitud GET para obtener el contenido de la imagen
        img_data = requests.get(image_url).content
        
        # Extraer el nombre del archivo desde la URL
        img_name = os.path.basename(image_url)
        
        # Crear la ruta de la imagen
        img_path = os.path.join(save_folder, img_name)
        
        # Guardar la imagen
        with open(img_path, 'wb') as file:
            file.write(img_data)
        
        print(f"Imagen guardada: {img_path}")
    except Exception as e:
        print(f"Error al descargar la imagen {image_url}: {e}")

def fetch_images_from_page(url, save_folder):
    """
    Obtiene todas las imágenes de una página web y las descarga.
    :param url: URL de la página web.
    :param save_folder: Carpeta donde se guardarán las imágenes.
    """
    # Hacer una solicitud GET para obtener el contenido de la página
    response = requests.get(url)
    print(response)
    
    # Parsear el contenido HTML de la página con BeautifulSoup
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # Buscar todas las etiquetas <img>
    img_tags = soup.find_all('img')
    
    # Crear la carpeta si no existe
    if not os.path.exists(save_folder):
    	os.makedirs(save_folder)
    
    # Descargar todas las imágenes
    for img_tag in img_tags:
        img_url = img_tag.get('src')
        if img_url:
            # Resolver la URL completa de la imagen (en caso de que sea relativa)
            full_img_url = urljoin(url, img_url)
            
            # Filtrar por extensiones .jpg y .png
            if full_img_url.lower().endswith(('.jpg', '.jpeg', '.png')):
                download_image(full_img_url, save_folder)

if __name__ == "__main__":
    # URL de la página web de la cual descargar las imágenes
    website_url = 'https://www.freeimages.com/search/dog'  # Cambia esto a la URL que desees
    
    # Carpeta donde se guardarán las imágenes
    save_folder = 'input_images'  # Cambia esto si lo deseas
    
    fetch_images_from_page(website_url, save_folder)