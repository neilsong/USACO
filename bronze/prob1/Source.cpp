#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	ifstream fin("convention.in");
	ofstream fout("convention.out");

	vector <int> c;
	vector <int> ds;
	map <int, int> fdss;
	int maxt = 0;
	int a, b, q;
	cin >> a >> b >> q;

	for (int i = 0; i < a; i++) {
		float w;
		cin >> w;
		c.push_back(w);
	}

	if (a <= b) {
		cout << 0 << endl;
		return 0;
	}

	sort(c.begin(), c.end());

	if (b == 1) {
		cout << c[a - 1] - c[0] << endl;
		return 0;
	}

	if (b == 2) {
		cout << max(c[a / 2-1] - c[0], c[a-1]-c[a/2-1]) << endl;
	}
	

	for (int i = 1; i < a; i++) {
		ds.push_back(c[i] - c[i - 1]);
	}
	vector <int> dss = ds;
	sort(dss.begin(), dss.end());

	for (int i = dss.size() - 1; i > dss.size()-1-b+2; i--) {
		fdss[dss[i]] = 1;
	}

	int C = 1;
	int t = 0;
	int B = 0;

	for (int i = 0; i < c.size(); i++) {
		if (C <= q) {
			if (i!= c.size()-1 && fdss.count(ds[i]) == 0) {
				t = c[i] - c[B];
			}
			else {
				t = c[i] - c[B];
				maxt = max(t, maxt);
				t = 0;
				C = 0;
				B = i+1;
			}
		}
		else {
			maxt = max(t, maxt);
			t = 0;
			C = 1;
			B = i;
		}
		C++;
	}
	

	cout << maxt << endl;

	return 0;
}