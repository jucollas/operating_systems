@echo off
REM Limpia cualquier archivo objeto previo
del /Q *.o

REM Compila cada archivo .cpp en un archivo objeto .o
g++ -c fcfs.cpp
g++ -c main.cpp
g++ -c mlq.cpp
g++ -c mlfq.cpp
g++ -c process.cpp
g++ -c scheduler-al.cpp
g++ -c queue.cpp
g++ -c rr.cpp
g++ -c simulation.cpp

REM Enlaza los archivos objeto para crear el ejecutable
g++ -o simulation fcfs.o main.o mlq.o mlfq.cpp process.o queue.o rr.o scheduler-al.cpp simulation.o

REM Limpia los archivos objeto si se desea
del /Q *.o

echo Compilation complete.
