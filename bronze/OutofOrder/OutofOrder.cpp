#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	vector <pair<int, int>> ts;
	vector <pair<int, int>> shifts;

	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");

	for (int i = 0; i < 1000000; i++) {
		ts.push_back(make_pair(i, 0));
	}

	int n;
	fin >> n;

	int m = 0;

	for (int i = 0; i < n; i++) {
		int a, b;
		fin >> a >> b;
		shifts.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++) {
		for (int j = shifts[i].first; j < shifts[i].second; j++) {
			ts[j].second++;
		}
	}

	for (int i = 0; i < n; i++) {
		int l = 0;
		vector <pair<int, int>> test;
		test = ts;
		for (int j = shifts[i].first; j < shifts[i].second; j++) {
			test[j].second--;
		}
		for (int h = 0; h < 999; h++) {
			if (test[h].second > 1) {
				l++;
			}
			else {
				l += test[h].second;
			}
		}
		m = std::max(m, l);
	}

	fout << m << endl;

	return 0;
}