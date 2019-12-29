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
	for (int i = 0; i < m; i++) {
		int a, b; char c;
		cin >> a >> b >> c;
		bool torl;
		c == 'T' ? torl = 1: torl = 0;
	}



	return 0;
}