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
int n;

bool sortbyw(Edge a, Edge b) {
	return a.w < b.w;
}

int main(void) {
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");

	fin >> n;
	vector<int> x(n), y(n);
	
	for (int i = 0; i < n; i++) {
		fin >> x[i] >> y[i];
	}
	parent.resize(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		for (int j = 0; j < i; j++) {
			int distance = pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2);
			edges.push_back(Edge(i,j,distance));
		}
	}
	sort(edges.begin(), edges.end(), sortbyw);
	int lastweight = 0, numcomp = n;
	for (auto curr : edges) {
		if (find(curr.i) != find(curr.j)) {
			merge(curr.i, curr.j);
			lastweight = curr.w;
			if (--numcomp == 1) {
				break;
			}
		}
	}
	fout << lastweight << endl;

}