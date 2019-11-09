#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> mat;
string orig = "";

		//mat[i][j] += min(orig[i] + f(i + 1, j), orig[j] + f(i, j - 1));


int main(void) {
	int n;
	cin >> n;
	mat.resize(2);
	mat[0].resize(n);
	mat[1].resize(n);
	for (int i = 0; i < n; i++) {
		char add;
		cin >> add;
		orig += add;
		mat[0][i] += add;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			mat[i % 2][j] = min(orig[j] + mat[abs(i - 1) % 2][j+1], orig[orig.length() - j-1] + mat[abs(i - 1) % 2][j]);
		}
	}
	cout << mat[n-1%2][0] << endl;
}
