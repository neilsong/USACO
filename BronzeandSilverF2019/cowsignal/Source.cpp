#include <bits/stdc++.h>
using namespace std;

char ans[102][102], arr[11][11];
int m, n, k;

int main(void) {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	fin >> m >> n >> k;

	//input
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fin >> arr[i][j];
		}
	}

	//amplify
	for (int i = 0; i < m * k; i++) {
		for (int j = 0; j < n * k; j++) {
			ans[i][j] = arr[i / k][j / k];
		}
	}

	//output
	for (int i = 0; i < m * k; i++) {
		for (int j = 0; j < n * k; j++) {
			fout << ans[i][j];
		}
		fout << endl;
	}
	return 0;
}