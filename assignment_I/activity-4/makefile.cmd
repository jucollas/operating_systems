@echo off
REM Configura el directorio del proyecto
set PROJECT_DIR=%~dp0

REM Navega al directorio del proyecto
cd /d "%PROJECT_DIR%"

REM Compila los archivos fuente en archivos objeto
g++ processor.cpp control-unit.cpp register-file.cpp memory.cpp alu.cpp address-register.cpp string-register.cpp main.cpp -o processor-simulation