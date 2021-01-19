#include <bits/stdc++.h>
using namespace std;


bool isUgly(long n) {
	while (n % 5) n /= 5;
	while (n % 3) n /= 3;
	while (n % 2)n /= 2;
	return n == 1;
}
int main(void) {
	vector<int> seq;
	int m;
	cin >> m;
	seq.resize(m+1);
	seq[0] = 1;
	int i2 =0, i3 = 0, i5 = 0;
	int nm2, nm3, nm5;
	for (int i = 1; i <= m; i++) {
		nm2 = seq[i2] * 2;
		nm3 = seq[i3] * 3;
		nm5 = seq[i5] * 5;
		seq[i] = min(nm2, nm3);
		seq[i] = min(seq[i], nm5);
		if (seq[i] == nm2) i2++;
		if (seq[i] == nm3) i3++;
		if (seq[i] == nm5) i5++;
	}
	cout << seq[m - 1] << endl;
}