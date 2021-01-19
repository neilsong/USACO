#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
int find(int curr) {
	return parent[curr] == curr ? curr : (parent[curr] = find(parent[curr]));
}

void merge(int x, int y) {
	parent[find(x)] = find(y);
}


struct Edge {
	int i, j, w;
public:Edge(int a, int b, int c) {
	i = a;
	j = b;
	w = c;

}
};
vector<Edge> edges;
int n,m;

bool sortbyw(Edge a, Edge b) {
	return a.w < b.w;
}

vector<pair<long long,long long>> coords;
vector<set<long long>> ansx, ansy;
vector<int> roots;

int main(void) {
	ifstream cin("fenceplan.in");
	ofstream cout("fenceplan.out");
	cin >> n >> m;
	parent.resize(n+1);
	ansx.resize(n + 1);
	ansy.resize(n + 1);
	coords.resize(1);
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		coords.push_back({ x,y });
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		if(parent[s] == 0)parent[s] = s;
		if(parent[e] == 0)parent[e] = e;
		if (find(s) != find(e)) {
			merge(s, e);
			merge(e, s);
		}
	}

	for (int i = 1; i <= n; i++) {
		int caches = find(i);
		ansx[caches].insert(coords[i].first);
		ansy[caches].insert(coords[i].second);
	}

	long long ans = INT_MAX;

	for (int i = 0; i < ansx.size(); i++) {
		if (ansx[i].empty())continue;
		long long minx = *ansx[i].begin(), miny = *ansy[i].begin(), maxx = *ansx[i].rbegin(), maxy = *ansy[i].rbegin();
		long long peri = ((maxx - minx) * 2) + ((maxy - miny) * 2);
		ans = min(ans, peri);
	}

	cout << ans << endl;
}