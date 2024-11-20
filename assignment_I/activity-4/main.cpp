#include "processor.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::vector<std::string> readFile(std::string& filename){
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Could not open file: " << filename << std::endl;
  }

  std::vector<std::string> program;
  std::string line;

  while (std::getline(file, line)) {
    program.push_back(line);
  }

  file.close();
  return program;
}

int main(int argc, char *argv[]) {
  if (argc < 2) return 1;

  Processor processor(100, 100); // Tamaños de ejemplo: 100 para texto y 100 para datos
  std::string namefile = argv[1];
  std::vector<std::string> program = readFile(namefile);

  processor.loadProgram(program);
  processor.execute();

  return 0;
}
