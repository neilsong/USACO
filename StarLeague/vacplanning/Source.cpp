#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int p, c, k, q;

int V, E;
vector<vector<pair<int, int>>> adj;
vector <int> visited, dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
	cin >> p >> c >> k >> q;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			mat[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < c; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		mat[--a][--b] = d;
	}
	long ans = 0;
	int num = 0;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		long long ccount = 0;
		for (int h = 0; h < k; h++) {
			ccount += mat[a][h];
			ccount += mat[h][b];
		}
		if (ccount < INT_MAX) {
			num++;
			ans += ccount;
		}
	}
	cout << num << endl << ans << endl;
}