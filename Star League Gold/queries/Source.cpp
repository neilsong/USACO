#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	std::set<int> set;
	for (int i = 0; i < n; i++) {
		int action, ele;
		cin >> action >> ele;
		if (action == 1) {
			set.insert(ele);
		}
		else if (action == 2) {
			set.erase(ele);
		}
		else {
			if (set.find(ele) != set.end()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
}