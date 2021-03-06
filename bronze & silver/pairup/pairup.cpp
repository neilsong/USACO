#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ofstream fout("pairup.out");
	ifstream fin("pairup.in");

	vector<pair<long long, long long>> cows;

	long long time = 0;
	int n;
	int i = 0;
	int j;
	fin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		fin >> a >> b;
		cows.push_back(make_pair(b, a));
	}

	sort(cows.begin(), cows.end());

	j = cows.size() - 1;

	while (true) {
		if (i == j && cows[i].second == 0) {
			break;
		}
		if (cows[i].second == 0) {
			i++;
			continue;
		}
		if (cows[j].second == 0) {
			j--;
			continue;
		}
		time = max(time, cows[i].first + cows[j].first);
		cows[i].second--;
		cows[j].second--;
	}

	fout << time << endl;

	return 0;
}