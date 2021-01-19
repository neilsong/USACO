#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int B = 0;
int main(void) {
	int ans = 0;
	int n, m, p;
	cin >> n >> m >> p;
	double A = p * m / 2,
	B = p + 1;
	B += gcd(m, n);
	B += gcd(abs(p - n), m);
	if (A - (int)(A) == 0 && (double)(B / 2) == B / 2) {
		A++;
	}
	cout << (int)(A - (B / 2) + 1) << endl;
}