#include "cscan.h"

void Cscan::simulation(int start, int maxTrack, vector<int>& requests, int moveTime) {
	int distance = 0;
	vector<int> left, right;

	for (int request : requests) {
		if (request < start) left.push_back(request);
		else right.push_back(request);
	}

	sort(left.begin(), left.end());  
	sort(right.begin(), right.end());

	cout << "\nC-SCAN Path: ";
	int currentTrack = start;

	for (int track : right) {
		cout << currentTrack << " -> " << track << " ";
		distance += abs(track - currentTrack);
		currentTrack = track;
	}

	if (!left.empty()) {
		distance += abs(maxTrack - currentTrack);
		currentTrack = 0;
		cout << maxTrack << " -> " << currentTrack << " ";

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