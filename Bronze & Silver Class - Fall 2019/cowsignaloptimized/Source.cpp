#include <bits/stdc++.h>
using namespace std;

int m, n, k;

int main(void) {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	fin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		string line = "";
		for (int j = 0; j < n; j++) {
			char c;
			fin >> c;
			for (int l = 0; l < k; l++) {
				line += c;
			}
		}
		for (int l = 0; l < k; l++) {
			fout << line << endl;
		}
	}
	return 0;
}