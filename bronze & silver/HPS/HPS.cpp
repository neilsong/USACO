#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 0 = hoof
// 1 = paper
// 2 = scissors

vector <pair<int, int>> swap(vector <pair<int, int>> nums) {
	int a = nums[1].second;
	nums[1].second = nums[2].second;
	nums[2].second = a;
	return nums;
}

int v(vector <pair<int, int>> nums, vector <pair<int, int>> matches) {
	int vict = 0;
	vector <pair<int, int>> ms;
	ms = matches;
	for (int i = 0; i < ms.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (ms[i].first == nums[j].first) {
				ms[i].first = nums[j].second;
			}
		}
	}

	for (int i = 0; i < ms.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (ms[i].second == nums[j].first) {
				ms[i].second = nums[j].second;
			}
		}
	}

	for (int i = 0; i < ms.size(); i++) {
		if (ms[i].first == 0) {
			if (ms[i].second == 2) {
				vict++;
			}
		}
		else if (ms[i].first == 1) {
			if (ms[i].second == 0) {
				vict++;
			}
		}
		else {
			if (ms[i].second == 1) {
				vict++;
			}
		}
	}
	return vict;
}

int main(void)
{

	ofstream fout("hps.out");
	ifstream fin("hps.in");

	vector <pair<int, int>> ones;
	vector <pair<int, int>> twos;
	vector <pair<int, int>> threes;
	vector <int> Vs;
	vector <pair<int, int>> matches;

	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		fin >> a >> b;
		matches.push_back(make_pair(a, b));
	}

	for (int i = 1; i < 4; i++) {
		if (i == 1) {
			ones.push_back(make_pair(i, 0));
			ones.push_back(make_pair(1+i, 1));
			ones.push_back(make_pair(2+i, 2));
			Vs.push_back(v(ones, matches));
			ones = swap(ones);
			Vs.push_back(v(ones, matches));
		}
		else if(i == 2) {
			twos.push_back(make_pair(i, 0));
			twos.push_back(make_pair(1+i, 1));
			twos.push_back(make_pair(i - 1, 2));
			Vs.push_back(v(twos, matches));
			twos = swap(twos);
			Vs.push_back(v(twos, matches));
		}
		else {
			threes.push_back(make_pair(i, 0));
			threes.push_back(make_pair(i-1, 1));
			threes.push_back(make_pair(i-2, 2));
			Vs.push_back(v(threes, matches));
			threes = swap(threes);
			Vs.push_back(v(threes, matches));

		}
	}

	int mx = Vs[0];

	for (int i = 1; i < Vs.size(); i++) {
		mx = max(mx, Vs[i]);
	}

	fout << mx;

	return 0;
}