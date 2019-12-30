#include <bits/stdc++.h>
using namespace std;

priority_queue<double, vector<double>, std::greater<double>> tpq, dpq;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c; double a;
		cin >> c >> a;
		if (c == 'T') {
			tpq.push(a);
		}
		else {
			dpq.push(a);
		}
	}
	double d = 0, t = 0, v = 1, ncg = 2;
	while (d < 1000) {
		double dmin;
		if (tpq.empty() && dpq.empty()) {
			cout << (int)((double)(1000.0 - d) / v + t + 0.5) << endl;
			return 0;
		}
		if (tpq.empty()) dmin = dpq.top() - d;
		else if (dpq.empty()) dmin = (tpq.top()-t) * v ;
		else dmin = min((tpq.top()-t) * v, dpq.top() - d);
		if (d + dmin > 1000.0) {
			cout << (int)((double)(1000.0 - d) / v + t + 0.5) << endl;
			return 0;
		}
		if (!dpq.empty() && dmin == dpq.top() - d) { dpq.pop(); t += (dmin) / v; }
		else if(!tpq.empty()){ t = tpq.top(); tpq.pop(); }
		d += dmin;
		v = 1 / ncg;
		ncg++;
	}
	cout << (int)(t+0.5) << endl;
}