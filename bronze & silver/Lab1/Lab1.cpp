#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cin >> a;
	a[2] = '0' + 22;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a[i])) {
			cout << a[i] - '0' << endl;
		}
	}
	return 0;
}