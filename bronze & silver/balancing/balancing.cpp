#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int tam(vector<pair<long, long>> cows, int med) {
	sort(cows.begin(), cows.end());
	return cows[med].first;
}

int main(void)
{
	long n, b;
	cin >> n >> b;

	vector <pair<long, long>> cows;

	for (long i = 0; i < n; i++) {
		long x, y;
		cin >> x >> y;
		cows.push_back(make_pair(x, y));
	}

	if (n % 2 == 0) {

	}


	return 0;
}