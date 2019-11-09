#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	stack<char> cstack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
				cstack.push('(');
		}
		if (str[i] == ')') {
			if (cstack.empty()) {
				cout << "Not valid" << endl;
				return 0;
			}
			if (cstack.top() == '(') {
				cstack.pop();
			}
			else {
				cout << "Not valid" << endl;
				return 0;
			}
		}
		if (str[i] == '{') {
			cstack.push('{');
		}
		if (str[i] == '}') {
			if (cstack.empty()) {
				cout << "Not valid" << endl;
				return 0;
			}
			if (cstack.top() == '{') {
				cstack.pop();
			}
			else {
				cout << "Not valid" << endl;
				return 0;
			}
		}
		if (str[i] == '[') {
			cstack.push('[');
		}
		if (str[i] == ']') {
			if (cstack.empty()) {
				cout << "Not valid" << endl;
				return 0;
			}
			if (cstack.top() == '[') {
				cstack.pop();
			}
			else {
				cout << "Not valid" << endl;
				return 0;
			}
		}
	}
	cout << "Valid" << endl;
}