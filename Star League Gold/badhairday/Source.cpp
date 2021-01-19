#include <bits/stdc++.h>
using namespace std;

int main(void) {
	//Count during input using stack
	int n;
	cin >> n;
	stack <long> stak;
	int count = 0;
	for (int i = 0; i < n; i++) {
		long h;
		cin >> h;
		while (!stak.empty() && stak.top() <= h) {
			stak.pop();
		}
		if (stak.empty()) {
			stak.push(h);
		}
		if (stak.top() > h) {
			stak.push(h);
			count += stak.size() - 1;
		}
	}
	cout << count << endl;
}