#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	queue<int>line;
	vector <vector <int>> desk(n);
	char place;
	cin >> place;
	int x;
	cin >> x;
	line.push(x);
	while (!line.empty()) {
		char action;
		int num;
		cin >> action >> num;
		if (action == 'C') {
			line.push(num);
		}
		else {
			desk[num-1].push_back(line.front());
			line.pop();
		}
	}
	for (auto i : desk) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}