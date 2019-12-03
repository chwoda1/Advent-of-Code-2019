#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

void buildVectors(vector<pair<int,int>>& l1, vector<string>& line1);
int manhattanDistance(pair<int,int>,pair<int,int>);

int main() {

	string tmp;
	
	fstream file1("./line1.txt");
	fstream file2("./line2.txt");

	vector<string> line1;
	vector<string> line2;

	while (file1 >> tmp) {
		line1.push_back(tmp);
		tmp.clear();
	}

	while (file2 >> tmp) {
		line2.push_back(tmp);
		tmp.clear();
	}

	vector<pair<int,int>> l1 {{0,0}};
	vector<pair<int,int>> l2 {{0,0}};

	buildVectors(l1, line1);
	buildVectors(l2, line2);

	map<pair<int,int>, bool> seen;

	int min = INT_MAX;

	for (int i = 0; i < l1.size(); i++)
		seen[l1[i]] = true;

	for (int i = 1; i < l2.size(); i++) {
		if (seen.find(l2[i]) != seen.end()) {
			min = std::min(min, manhattanDistance({0,0}, l2[i]));
		}
	}

	cout << "MIN: " << min << endl;

	return 0;
}

void buildVectors(vector<pair<int,int>>& l1, vector<string>& line1) {

	for (int j = 0; j < line1.size(); j++) {
		
		auto curr = line1[j];
		string num = string(curr.begin() + 1, curr.end());

		for (int i = 0; i < stoi(num); i++) {
		
			if (curr[0] == 'R') {
				l1.push_back({l1.back().first + 1, l1.back().second});
			} else if (curr[0] == 'L') {
				l1.push_back({l1.back().first - 1, l1.back().second});
			} else if (curr[0] == 'U') {
				l1.push_back({l1.back().first, l1.back().second + 1});
			} else {
				l1.push_back({l1.back().first, l1.back().second - 1});
			}

		}
	}
	
}

int manhattanDistance(pair<int,int> p1, pair<int,int> p2) {
	int tmp = abs(p1.first - p2.first) + abs(p1.second - p2.second);
	return tmp;
}
