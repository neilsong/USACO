#include <bits/stdc++.h>
using namespace std;

struct edge {
	int a, b, w;
};
int changes = 0;
vector<int> parent, sizes, table, rtable;
vector<bool> tocon;

vector<set<int>> h;

//find size of CC of x -> size[root(x)]

//path compression find
int root(int v) {
	if (v == parent[v]) {
		if (v == parent[table[v]]) { 
			if (tocon[v] == 0) {
				tocon[v] = 1;
				changes++;
			}
		}
		return v;
	}
	return parent[v] = root(parent[v]);
}

//union by size
void join(int u, int v) {
	int U = root(u); int V = root(v);
	if (U == V) return;
	if (sizes[U] < sizes[V]) {
		parent[U] = V;
		sizes[V] += sizes[U];
		for (auto i : h[U]) {
			if (tocon[i] == 0 && h[V].find(table[i]) != h[V].end()) { 
				tocon[i] = 1;
				changes++;
			}
			if (tocon[rtable[i]] == 0 && h[V].find(rtable[i]) != h[V].end()) {
				tocon[rtable[i]] = 1;
				changes++;
			}
			h[V].insert(i);
		}
	}
	else {
		parent[V] = U;
		sizes[U] += sizes[V];
		for (auto i : h[V]) {
			if (tocon[i] == 0 && h[U].find(table[i]) != h[U].end()) {
				tocon[i] = 1;
				changes++;
			}
			if (tocon[rtable[i]] == 0 && h[U].find(rtable[i]) != h[U].end()) {
				tocon[rtable[i]] = 1;
				changes++;
			}
			h[U].insert(i);
		}
	}
}

vector<edge> edges;
int n, m;


bool sortbyw(edge a, edge b) {
	return a.w > b.w;
}

int main() {
	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");
	cin >> n >> m;
	table.resize(n);
	tocon.resize(n);
	parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
	sizes.assign(n, 1);
	h.resize(n);
	rtable.resize(n);
	for (int i = 0; i < n; i++) {
		h[i].insert(i);
	}
	vector<int> arr(n+1), vec(n+1);
	int fin = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; x--;
		table[x] = i;
		rtable[i] = x;
		if (x == i) { tocon[i] = 1; continue; }
		fin++;
	}
	if (fin == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w; a--; b--;
		edges.push_back({ a,b,w });
	}
	sort(edges.begin(), edges.end(), sortbyw);
	bool changed = 0;
	for (auto i : edges) {
		join(i.a, i.b);
		if (changes == fin) {
			cout << i.w << endl;
			break;
		}
	}
	return 0;
}