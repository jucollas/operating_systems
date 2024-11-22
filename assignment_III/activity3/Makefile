# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall
SOURCES = main.cpp scan.cpp cscan.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = app

# Regla principal
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJECTS) $(TARGET)
