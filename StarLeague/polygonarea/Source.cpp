#include <bits/stdc++.h>
using namespace std;

double polygonArea(vector<double> X, vector<double> Y, int n)
{	double area = 0.0;

	int j = n - 1;
	for (int i = 0; i < n; i++) {
		area += (X[j] + X[i]) * (Y[j] - Y[i]);
		j = i;  
	}

	return abs(area / 2.0);
}

int main(void) {
	int n;
	cin >> n;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		vector<double> X, Y;
		for (int j = 0; j < p; j++) {
			double x, y;
			cin >> x >> y;
			X.push_back(x);
			Y.push_back(y);
		}
		ans = max(ans, polygonArea(X, Y, p));
	}
	cout << ans << endl;
}