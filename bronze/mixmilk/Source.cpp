#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

	int A[4];
	int B[4];

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		B[i] = a;
		A[i] = b;
	}

	int cf = 0, ct = 1;

	for (int i = 0; i < 100; i++) {
		if (cf == 3) {
			cf -= 3;
		}
		if (ct == 3) {
			ct -= 3;
		}
		int m;
		m = min(A[cf], B[ct] - A[ct]);
		A[cf] -= m;
		A[ct] += m;
		ct++;
		cf++;
	}

	for (auto i : A) {
		cout << i << endl;
	}

	return 0;
}