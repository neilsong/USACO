#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> mat;
string orig = "";



int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char add;
		cin >> add;
		orig += add;
	}
	int i = 0, j = n - 1;
	string final = "";
	while (i < j) {
		if (orig[i] < orig[j]) {
			final += orig[i];
			i++;
		}
		else if (orig[i] == orig[j]) {
			int ti = i+1, tj = j-1;
			while (ti < tj && orig[ti] == orig[tj]) {
				ti++;
				if (orig[ti] != orig[tj]) break;
				ti--;
				tj--;
				if (orig[ti] != orig[tj]) break;
				ti++;
			}
			if (orig[ti] < orig[tj]) {
				final += orig[i];
				i++;
			}
			else {
				final += orig[j];
				j--;
			}
		}
		else {
			final += orig[j];
			j--;
		}
	}
	final += orig[i];
	cout << final;
}