#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "scan.h"
#include "cscan.h"

using namespace std;

vector<int> readFile(const string& fileName) {
  int request;
  ifstream file(fileName);
  vector<int> ans;
  if(file.is_open()) {
    while (file >> request)
      ans.push_back(request);
    file.close();
  } else {
    cout << "Could not open the file.\n";
  }
  return ans;
}

int main() {
    Scan scan;
    Cscan cscan;
    string fileName;
    int start, maxTrack, moveTime;
    vector<int> requests;

    cout << "Enter the request file name: ";
    cin >> fileName;
    cout << "Enter the initial track position: ";
    cin >> start;
    cout << "Enter the maximum track on the disk: ";
    cin >> maxTrack;
    cout << "Enter the movement time:";
    cin >> moveTime;

    requests = readFile(fileName);

    cout << "\nSCAN and C-SCAN Simulation:\n";
    
    scan.simulation(start, maxTrack, requests, moveTime);
    cscan.simulation(start, maxTrack, requests, moveTime);

    return 0;
}