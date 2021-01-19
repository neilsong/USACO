#include<bits/stdc++.h>
using namespace std;

int n, m, q;

int main() {
	cin >> n >> m >> q;
	vector<int> p(n), deck(n);
	for (int i = 0; i < n; i++) {
		int a;
		if (i < m) { cin >> a; a--;  p[a] = i; }
		deck[i] = i+1;
	}
	for (int i = 0; i < q; i++) {
		int size, pos = 0;
		cin >> size;
		if (size < m) { pos = m - size; size = m; }
		while (size < n) {
			if(pos < m) pos = p[pos];
			size++;
			pos++;
		}
		if (pos < m)  pos = p[pos];
		cout << deck[pos] << endl;
	}
}