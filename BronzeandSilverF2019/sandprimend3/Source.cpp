#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	if (n % 2 == 0) return 0;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main(void) {
	long long s = 0, p = 1;
	for (int i = 3; i <= 10000; i+=10) {
		if (prime(i)) {
			s += i;
			p *= i;
		}
	}
	cout << s << " " << p << endl;
}