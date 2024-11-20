#include "scan.h"

void Scan::simulation(int start, int maxTrack, vector<int>& requests, int moveTime) {
  int distance = 0;
  vector<int> left, right;

  for (int request : requests) {
    if (request < start) left.push_back(request);
    else right.push_back(request);
  }

  sort(left.rbegin(), left.rend()); // descending order
  sort(right.begin(), right.end()); // ascending order

  cout << "\nSCAN Path: ";
  int currentTrack = start;

  // Move right
  for (int track : right) {
    cout << currentTrack << " -> " << track << " ";
    distance += abs(track - currentTrack);
    currentTrack = track;
  }

  // Move to end and then back
  if (!left.empty()) {
    distance += abs(maxTrack - currentTrack);
    currentTrack = maxTrack;
    cout << currentTrack << " ";
    for (int track : left) {
      cout << currentTrack << " -> " << track << " ";
      distance += abs(track - currentTrack);
      currentTrack = track;
    }
  }

  int totalTime = distance * moveTime;
  cout << "\nTotal Distance: " << distance << " tracks";
  cout << "\nTotal Time: " << totalTime << " ms\n";
}
