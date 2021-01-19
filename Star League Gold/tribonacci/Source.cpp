#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long n; cin >> n;
	long a = 0, b = 0, c = 1, d;
	for (int i = 4; i <= n; i++) {
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	cout << d << endl;
}