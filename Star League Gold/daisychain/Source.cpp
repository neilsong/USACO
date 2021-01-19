#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> adj;
void addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int V;



vector <int>  DFS(int s) {
	stack<int>tovisit1;
	vector <int> visited1(V);
	tovisit1.push(s);
	while (tovisit1.size() != 0) {
		int v = tovisit1.top();
		if (visited1[v]) {
			tovisit1.pop();
			continue;
		}
		visited1[v] = 1;
		tovisit1.pop();
		for (auto i : adj[v]) {
			tovisit1.push(i);
		}
	}
	return visited1;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	V = n;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		addEdge(v1-1, v2-1);
	}
	vector <int> behaved = DFS(0);
	int ind = 0;
	bool hasans = 0;
	for (auto i : behaved) {
		if (!i) {
			cout << ind + 1 << endl; hasans = 1;
		}
		ind++;
	}
	if (!hasans) cout << 0 << endl;
}