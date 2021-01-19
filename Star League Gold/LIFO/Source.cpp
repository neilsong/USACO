#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> stak;
		int k = 0;
		cin >> k;
		bool legal = 1;
		string y;
		cin >> y;
		for (int j = 0; j < k; j++) {
			 if (y[j] == '>') {
				 stak.push(y[j]);
			 }
			 else {
				 if (stak.empty()) {
					 cout << "illegal" << endl;
					 legal = 0;
					 break;
				 }
				 else {
					 stak.pop();
				 }
			 }
		}
		if(legal) {
			if (!stak.empty())cout << "illegal" << endl;
			else cout << "legal" << endl;
		}
	}
	
}