#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Cscan{
  public:
    Cscan();
    void simulation(int start, int maxTrack, vector<int>& requests, int moveTime);
};