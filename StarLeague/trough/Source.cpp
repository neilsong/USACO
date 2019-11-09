#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector <pair<bitset<20>, int>> questions;
	for (int i = 0; i < m; i++) {
		string a;
		int b;
		cin >> a >> b;
		bitset<20> bits(a);
		questions.push_back(make_pair(bits, b));
	}
	int deter = -1;
	for (int i = 0; i <= (1 << n); i++) {
		bool works = 1;
		for (auto j : questions) {
			bitset<20>bitsi(i);
			bitsi &= j.first;
			int check = bitsi.count();
			if (check != j.second) {
				works = 0;
				break;
			}
		}
		if (works) {
			if (deter < 0)
				deter = i;
			else { cout << "NOT UNIQUE"; return 0; }
		}
	}
	if (deter < 0) cout << "IMPOSSIBLE";
	else {
		bitset<20> tobin(deter);
		string toprint = tobin.to_string<char, std::string::traits_type, std::string::allocator_type>();
		for (int i = 20 - n; i < toprint.length(); i++) {
			cout << toprint[i];
		}
		cout << endl;
	}
}