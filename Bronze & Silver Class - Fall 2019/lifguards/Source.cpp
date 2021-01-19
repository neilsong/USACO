//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("shell.in");
ofstream fout("shell.out");


int n;
vector<pair<int, int>> lfgds;

int covered(vector<pair<int, int>> life) {
	vector<int> time(1001);
	int ans = 0;
	for (auto i : life) {
		for (auto j = i.first; j <= i.second; j++) {
			if (time[j]) {
				ans++;
			}
			time[j] |= 1;
		}
	}
	return ans;
}

int main(void) {
	fin >> n;
	lfgds.resize(n);
	for (int i = 0; i <= n; i++) {
		fin >> lfgds[i].first >> lfgds[i].second;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> temp = lfgds;
		temp.erase(temp.begin() + i);
		ans = min(ans, covered(temp));
	}
	fout << ans << endl;
	return 0;
}