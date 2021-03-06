#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;


vector <int> line;

int binsearch(int limit) {
	if (line[0] > limit) {
		return 0;
	}
	int min = 0;
	int max = line.size() - 1;
	while (min != max) {
		int mid = (min + max + 1) / 2;
		if (line[mid] <= limit) {
			min = mid;
		}
		else {
			max = mid - 1;
		}
	}
	return min + 1;
}

int main(void)

{

	ofstream fout("haybales.out");
	ifstream fin("haybales.in");



	vector <pair<long long, long long>> query;

	long long n, q;
	fin >> n >> q;

	for (long long i = 0; i < n; i++) {
		long long b;
		fin >> b;
		line.push_back(b);
	}

	sort(line.begin(), line.end());

	for (long long i = 0; i < q; i++) {
		long long a, b;
		fin >> a >> b;
		fout << binsearch(b) - binsearch(a-1) << endl;
	}


	return 0;
}