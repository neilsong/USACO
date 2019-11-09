#include <bits/stdc++.h>
using namespace std;

vector <int> indegree, es, et, t;

vector<vector <int>> adj;
void addEdge(int u, int v)
{
	adj[u].push_back(v);
}

int toposort() {
	queue <int> q;
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	int tor = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		et[cur] = es[cur] + t[cur];
		tor = max(tor, et[cur]);
		for (auto w : adj[cur]) {
			es[w] = max(es[w], et[cur]);
			indegree[w]--;
			if (indegree[w] == 0) {
				q.push(w);
			}
		}
	}
	return tor;
}


int main(void) {
	int n, m; cin >> n >> m;
	t.resize(n+1);
	indegree.resize(n+1);
	adj.resize(n + 1);
	es.resize(n + 1);
	et.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		t[i] = a;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		addEdge(a, b);
		indegree[b]++;
	}
	cout << toposort() << endl;
}