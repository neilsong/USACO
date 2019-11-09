#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> adj;

void solve()
{
	// Floyd-Warshall all shortest path
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (adj[j][i])
				for (int k = 0; k < N; k++)
					if (adj[i][k] && (!adj[j][k] || adj[j][k] > adj[j][i] + adj[i][k]))
						adj[j][k] = 1;
}

int main(void) {
	
	cin >> N >> M;
	adj.resize(N);
	for (int i = 0; i < N; i++) {
		adj[i].resize(N);
	}
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		adj[v1][v2] = 1;
	}
	solve();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool idk = 1;
		for (int j = 0; j < N; j++) {
			if (!adj[i][j] && !adj[j][i]) {
				idk = 0;
			}
		}
		if (idk) ans++;
	}
	
	cout << ans << endl;
}