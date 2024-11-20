#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Scan{
  public:
    Scan();
    void simulation(int start, int maxTrack, vector<int>& requests, int moveTime);
};