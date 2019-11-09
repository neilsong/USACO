#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	priority_queue<int> fighters;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int fighter;
		cin >> fighter;
		fighters.push(0-fighter);
	}
	int ans = 0;
	while (fighters.size() > 1) {
		int f1 = fighters.top(), f2;
		fighters.pop();
		f2 = fighters.top();
		fighters.pop();
		fighters.push(f1 + f2);
		ans += f1 + f2;
	}
	cout << 0-ans << endl;
}