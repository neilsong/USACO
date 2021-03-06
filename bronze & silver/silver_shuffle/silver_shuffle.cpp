#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <queue>
using namespace std;

int main(void)
{
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");

	int n;
	fin >> n;

	vector <int> to(n), toroots(n);

	for (int i = 0; i < n; i++) {
		int x;
		fin >> x;
		to[i] = x - 1;
		toroots[to[i]]++;
	}

	queue<int>zeroz;
	int ret = n;

	for (int i = 0; i < n; i++) {
		if (toroots[i] == 0) {
			zeroz.push(i);
			ret--;
		}
	}

	while (!zeroz.empty()) {
		int c = zeroz.front();
		zeroz.pop();
		if (--toroots[to[c]] == 0) {
			zeroz.push(to[c]);
			ret--;
		}

	}

	fout << ret << endl;


	return 0;
}