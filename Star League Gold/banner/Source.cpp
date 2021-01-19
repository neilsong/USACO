#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int dist(int x1, int y1, int x2, int y2) {
	return (pow(x1 - x2, 2) + pow(y2 - y1, 2));
}
int w, h, l1, l2;

int main(void) {
	cin >> w >> h >> l1 >> l2;
	long ans = 0;
	if (l1 == 1) {
		ans += w * (h + 1);
		ans += h * (w + 1);
	}
	l1 *= l1;
	l2 *= l2;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			int dista = dist(i, 0, 0, j);
			if (dista >= l1 && dista <= l2) {
				if (gcd(i, j) == 1) {
					ans += ((w - i) + 1) * ((h - j) + 1) * 2;
				}
			}
		}
	}
	cout << ans << endl;
}