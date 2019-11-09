#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> G;

struct cow {
	float x, y;
	float radius;
};

int main(void) {
	int n;
	cin >> n;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		G[i].resize(n);
	}
	vector<cow>cows;
	for (int i = 0; i < n; i++) {
		float x, y;
		float rad;
		cin >> x >> y >> rad;
		cows.push_back({ x,y,rad });
	}
	for (int i = 0; i < n; i++) {
		cow cow1 = cows[i];
		for (int j = 0; j < n; j++) {
			cow cow2 = cows[j];
			float dist = (float)sqrt(((cow2.x - cow1.x)* (cow2.x - cow1.x)) + ((cow2.y - cow1.y)* (cow2.y - cow1.y)));
			if ( dist <= cow1.radius) {
				G[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int s = 0; s < n; s++) {
			for (int d = 0; d < n; d++) {
				G[s][d] = G[s][d] || (G[s][i] && G[i][d]);
			}
		}
	}
	int mcows = 0;
	for (auto i : G) {
		int rcows = 0;
		for (auto j : i) {
			if (j) {
				rcows++;
			}
		}
		mcows = max(rcows, mcows);
	}
	cout << mcows << endl;
}