#include <bits/stdc++.h>
using namespace std;
vector<int> parent, sizes;



//path compression find
int root(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = root(parent[v]);
}

//union by size
void join(int u, int v) {
	int U = root(u); int V = root(v);
	if (U == V) return;
	if (sizes[U] < sizes[V]) {
		parent[U] = V;
		sizes[V] += sizes[U];
	}
	else {
		parent[V] = U;
		sizes[U] += sizes[V];
	}
}
int main() {

	int n, m;
	cin >> n >> m;
	parent.resize(2 * n); sizes.assign(2 * n,1);
	iota(parent.begin(), parent.end(), 0);
	set<int> nodes;
	for (int i = 0; i < m; i++) {
		int a, b; char c;
		cin >> a >> b >> c; a--; b--;
		nodes.insert(a); nodes.insert(b);
		if (c == 'T') {
			join(2 * a, 2 * b);
			join(2 * a+1, 2 * b+1);
		}
		else {
			join(2 * a + 1, 2 * b);
			join(2 * a, 2 * b + 1);
		}
		for (auto j : nodes) {
			if (root(2 * j) == root(2 * j + 1)) { 
				cout << i << endl; return 0; 
			}
		}
	}
	cout << m << endl;



	return 0;
}