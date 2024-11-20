#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime> 
#include <set>

void generateRandomNumbersFile(const std::string& filename, int count, int max) {
  std::ofstream outFile(filename);
  std::set<int> unique;
  std::set<int>::iterator it;

  if (!outFile) {
    std::cerr << "Error opening file for writing\n";
    return;
  }

  std::srand(std::time(nullptr));

  while (unique.size() < count){
    int randomNumber = std::rand() % (max + 1);
    unique.insert(randomNumber);
  }

  for(it = unique.begin(); it != unique.end(); it++){
    outFile << *it << "\n";
  }

  outFile.close();
  std::cout << "File generated successfully: " << filename << "\n";
}

int main() {
  std::string filename;
  int count, max;

  std::cout << "Enter name file:";
  std::cin >> filename; 
  std::cout << "Enter size";
  std::cin >> count;
  std::cout << "Enter maximun value:";
  std::cin >> max;

  generateRandomNumbersFile(filename, count, max);

  return 0;
}
