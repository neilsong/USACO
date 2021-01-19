#include <bits/stdc++.h>
using namespace std;

int main(void) {
	deque<int>line;
	int n;
	cin >> n;

	int cownum = 1;
	for (int i = 0; i < n; i++) {
		char action, direction;
		cin >> action >> direction;
		if (action == 'A') {
			if (direction == 'R') {
				line.push_back(cownum);
			}
			else {
				line.push_front(cownum);
			}
			cownum++;
		}
		else {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				if (direction == 'R') {
					line.pop_back();
				}
				else {
					line.pop_front();
				}
			}
		}
	}
	for (auto i : line) {
		cout << i << endl;
	}


}