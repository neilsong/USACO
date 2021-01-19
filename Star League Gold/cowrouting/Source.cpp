#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>> >  nbrs[1001];

vector<long long> dist(1001);
vector <pair<int, int>> parent(1001, { -1,0 });
vector<bool> visited(1001); vector <int> op;
bool changed = 0;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


void dijkstra(int source)
{
	fill(dist.begin(), dist.end(), INT_MAX);	
	dist[source] = 0;
	visited[source] = 0;
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		long long i = pq.top().second;
		pq.pop();
		if (visited[i]) continue;
		visited[i] = 1;
		for (auto j : nbrs[i]) {
			if (dist[i] + j.second.first < dist[j.first]) {
				dist[j.first] = dist[i] + j.second.first;
				parent[j.first] = { i, j.second.second };
				changed = 1;
				pq.push(make_pair(dist[j.first], j.first));
			}
		}
	}
}


int main(void) {
	long long S, D, M;
	cin >> S >> D >> M;
	for (int i = 0; i < M; i++) {
		int c, n;
		cin >> c >> n;
		for (int j = 0; j < n; j++) {
			int b;
			cin >> b;
			op.push_back(b-1);
		}
		for (int j = 0; j < op.size(); j++) {
		int dis = 1; 
			for (int g = j + 1; g < op.size(); g++) {
				nbrs[op[j]].push_back(make_pair(op[g], make_pair(c, dis )));
				dis++;
			}
		}
		op.clear();
	}
	dijkstra(S-1);
	int numflights = 0;
	if (!changed) {
		cout << "-1 -1" << endl;
		return 0;
	}
	pair<int, int> i = { D - 1,0 };
	while (i.first != -1) {
		numflights += i.second;
		i = parent[i.first];
	}
	if (numflights == 0) {
		cout << "-1 -1" << endl;
	}
	else {
		cout << dist[D - 1] << " " << numflights << endl;
	}
	return 0;
}