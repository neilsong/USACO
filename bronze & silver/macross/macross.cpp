#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream fout("maxcross.out");
	ifstream fin("maxcross.in");

	vector <long> lites;
	

	long n, k, m;
	fin >> n >> k >> m;

	long count = m;

	lites.push_back(0);
	lites.push_back(n+1);

	for (long i = 0; i < m; i++) {
		long b;
		fin >> b;
		lites.push_back(b);
	}

	sort(lites.begin(), lites.end());

	bool f = 0;

	long h = lites[lites.size() - 1] - lites[0];

	for (long i = 0; i < m; i++) {
		for (long j = 0; j < lites.size()-i-1; j++) {
			long  a = lites[j];
			long b = lites[j + i+1];
			if (b - a-1 >= k) {
				count = i;
				f = 1;
				break;
			}
		}
		if (f) {
			break;
		}
	}

	fout << count << endl;

	return 0;
}