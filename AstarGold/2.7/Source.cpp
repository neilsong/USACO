#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizes;

//find size of CC of x -> size[root(x)]

//adding edges
//	Process queries in decreasing order of k


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
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int,int>>> qs;
int main(void) {
	int n, q;
	cin >> n >> q; 
	parent.resize(n); sizes.assign(n,1); //if index is root then size of cc
	iota(parent.begin(), parent.end(), 0);
	for (int i = 0; i < n-1; i++) {
		int a, b, w;
		cin >> a >> b >> w; a--; b--;
		edges.push_back({ w,{a,b} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v; v--;
		qs.push_back({ k,{v,i} });
	}
	sort(qs.begin(), qs.end());
	int ind = edges.size() - 1;
	vector<int> ans(q);
	for (int i = qs.size() - 1; i >= 0; i--) {
		int k = qs[i].first, v = qs[i].second.first, id = qs[i].second.second;
		for (ind; ind >= 0 && edges[ind].first >= k; ind--) {
			join(edges[ind].second.first, edges[ind].second.second);
		}
		ans[id] = sizes[root(v)];
	}
	for (auto i : ans) {
		cout << --i << endl;
	}
}