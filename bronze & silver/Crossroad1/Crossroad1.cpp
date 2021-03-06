#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{

	ofstream fout("crossroad.out");
	ifstream fin("crossroad.in");

	vector <pair<int, int>> A;
	vector <pair<int, int>> B;
	int t;
	fin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		fin >> a >> b;
		A.push_back(make_pair(a, b));
	}

	vector <pair<int, int>> ps;
	vector <int> pos;

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < A.size(); j++) {
			bool asdf = 1;
			if (A[j].first == i) {
				for (int h = 0; h < ps.size(); h++) {
					if (A[j].first == ps[h].first) {
						asdf = 0;
					}
				}
				if (asdf) {
					ps.push_back(A[j]);
					//A.erase(A.begin() + j);
				}
			}
		}
	}

	for (int i = 0; i < ps.size(); i++) {
		int po = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j].first == ps[i].first) {
				if (A[j].second != ps[i].second) {
					po++;
					ps[i].second = A[j].second;
				}
			}
		}
		pos.push_back(po);
	}


	int q = 0;

	for (int i = 0; i < pos.size(); i++) {
		q += pos[i];
	}

	fout << q;

	return 0;
}