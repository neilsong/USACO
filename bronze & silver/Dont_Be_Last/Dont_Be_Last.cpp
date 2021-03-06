#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ofstream fout("notlast.out");
	ifstream fin("notlast.in");

	vector <pair<string, int>> A;
	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		string b;
		int a;
		bool c = 1;
		fin >> b >> a;
		for (int j = 0; j < A.size(); j++) {
			if (A[j].first == b) {
				A[j].second += a;
				c = 0;
			}
		}
		if (c) {
			A.push_back(make_pair(b, a));
		}
	}

	int m = A[0].second;
	vector<string> seven;

	for (int i = 0; i < A.size(); i++) {
		if (A[i].first == "Bessie" || A[i].first == "Elsie" || A[i].first == "Daisy" || A[i].first == "Gertie" || A[i].first == "Annabelle" || A[i].first == "Maggie" || A[i].first == "Henrietta") {
			bool t = 0;
			if (seven.size() == 0) {
				seven.push_back(A[i].first);
			}
			else {
				for (int j = 0; j < seven.size(); j++) {
					if (j == seven.size() - 1 && !t && seven[j] != A[i].first) {
						seven.push_back(A[i].first);
					}
					else if (seven[j] == A[i].first) {
						t = 1;
					}
				}
			}
		}
	}

	if (seven.size() < 7) {
		m = 0;
	}

	for (int i = 0; i < A.size(); i++) {
		if (m == 0) {
			break;
		}
		m = min(m, A[i].second);
	}


	int nm = 0;
	string nameof;
	int k = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i].second > m && k == 0) {
			nm = A[i].second;
			k = 1;
			nameof = A[i].first;
		}
		else if (k > 0 && A[i].second > m) {
			if (A[i].second == nm) {
				fout << "Tie" << endl;
				return 0;
			}
			else if (A[i].second < nm) {
				nm = A[i].second;
				nameof = A[i].first;
				k = 1;
			}
		}
	}

	if (k == 0) {
		fout << "Tie" << endl;
	}
	else {
		fout << nameof << endl;
	}


	return 0;
}