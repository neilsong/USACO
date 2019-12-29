#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{

	ofstream fout("helpcross.out");
	ifstream fin("helpcross.in");

	vector<long> chik;
	vector<pair<long, long>> cows;
	vector <bool> cowsb;
	

	long c, n;
	long count = 0;
	fin >> c >> n;

	for (long i = 0; i < c; i++) {
		long b;
		fin >> b;
		chik.push_back(b);
	}

	for (long i = 0; i < n; i++) {
		long b, h;
		fin >> b >> h;
		cows.push_back(make_pair(b, h));
		cowsb.push_back(1);
	}

	for (long i = 0; i < c; i++) {
		long a = chik[i];
		for (int j = 0; j < n; j++) {
			if (!cowsb[j]) {
				continue;
			}
			else {
				long b = cows[j].first;
				long c = cows[j].second;
				if (a >= b && a <= c) {
					count++;
					cowsb[j] = 0;
					break;
				}
			}
		}
	}

	fout << count << endl;

	return 0;
}