#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> swap(vector <long long> yet, int x, int y) {
	long long a, b;
	a = yet[x];
	b = yet[y];
	yet[x] = b;
	yet[y] = a;
	return yet;
}

int main(void)
{
	ifstream fin("outofplace.in");
	ofstream fout("outofplace.out");

	int n;
	fin >> n;

	vector <long long > yet;

	for (int i = 0; i < n; i++) {
		long long b;
		fin >> b;
		yet.push_back(b);
	}

	vector <long long> syet;
	syet = yet;
	sort(syet.begin(), syet.end());

	int c = -1;

	for (int i = 0; i < yet.size(); i++) {
		if (syet[i] != yet[i]) {
			c++;
		}
	}

	fout << c << endl;

	return 0;
}