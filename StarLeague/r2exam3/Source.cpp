#include <bits/stdc++.h>
using namespace std;
int v, m;	float lim;
vector<map<int,float>> mat;
vector <int> visited;
vector<float>dist;
priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;

//adj pair<vertex, weight>
//pq pair<dist, vertex>

void dijkstra(int source) {
	visited.resize(v);
	dist.resize(v);
	fill(dist.begin(), dist.end(), INT_MAX);
	pq.push({ 0,source });
	dist[source] = 0;
	while (!pq.empty()) {
		float cost = pq.top().first;
		float cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto i : mat[cur]) {
			float a = i.first;
			float b = i.second;
			if (dist[a] > cost + b) {
				dist[a] = cost + b;
				pq.push({ dist[a], a });
			}
		}
	}
}

int p;

bool negcycle = 0;
map<int, pair<int, int>> trans;
//adj pair<vertex, weight>
//pq pair<dist, vertex>




float distance(pair<int, int> p1, pair<int, int> p2) {
	float treturn = (float)sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
	if (treturn > lim) {
			return -1;
	}
	else {
		return treturn;
	}
}

int main(void) {
	
	cin >> v >> m;
	mat.resize(v);
	cin >> lim;
	p = v;
	for (int i = 0; i < v; i++) {
		int x, y;
		cin >> x >> y;
		trans[i] = make_pair(x, y);
	}
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) 
		{
			float weight = distance(trans[i], trans[j]);
			if (weight > 0) {
				mat[i][j] =  weight;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		mat[v1][v2] = 0;
		mat[v2][v1] = 0;
	}
	dijkstra(0);
	if (dist[v - 1] == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	string toprint = to_string(dist[v - 1] * 1000);
	
	for (int i = 0; i < toprint.size(); i++) {
		if (toprint[i] == '.') {
			break;
		}
		cout << toprint[i];
	}
	cout << endl;
}