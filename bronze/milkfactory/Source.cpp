#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ocur;
void dfs(int start) {
	vector<int> visited(n);
	stack<int> stk;
	stk.push(start);
	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		if (visited[top]) continue;
		visited[top] = 1;
		ocur[top]++;
		for (auto i : adj[top]) {
			stk.push(i);
		}
	}
}

int main(void) {
	ifstream cin("factory.in");
	ofstream cout("factory.out");
	cin >> n;
	adj.resize(n);
	ocur.resize(n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	bool output = 0;
	for (int i = 0; i < ocur.size(); i++) {
		if(ocur[i] == n){
			cout << ++i << endl;
			output = 1;
			break;
		}
	}
	if (!output) {
		cout << -1 << endl;
	}
	return 0;
}