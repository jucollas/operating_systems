@echo off
REM Configura el directorio del proyecto
set PROJECT_DIR=%~dp0

REM Navega al directorio del proyecto
cd /d "%PROJECT_DIR%"

REM Compila los archivos fuente en archivos objeto
g++ -o shapes main.cpp rectangle.cpp square.cpp triangle.cpp circle.cpp shape.cpp
