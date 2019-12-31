#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
vector<ll> dx{ 1,-1,0,0 }, dy{ 0,0,-1,1 };
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpair;
typedef vector<vector<pair<ll, ll>>> vvpair;
vvpair adj, radj;
unsigned long long n, m, k, q;
vector<vector<unsigned long long>> dist;
vector<vector<unsigned long long>> rdist;


#define ullmax 18446744073709551615

void dijkstra(int s) {
	dist[s].assign(n, ullmax);
	priority_queue<pair<unsigned long long, unsigned long long>, std::vector<pair<unsigned long long, unsigned long long>>, std::greater<pair<unsigned long long, unsigned long long>>> pq;
	dist[s][s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int v = pq.top().second; int vw = pq.top().first; pq.pop();
		if (vw > dist[s][v]) continue;
		for (auto u : adj[v]) {
			if (dist[s][v] + u.second < dist[s][u.first]) {
				dist[s][u.first] = dist[s][v] + u.second;
				pq.push({ dist[s][u.first], u.first });
			}
		}
	}
}

void rdijkstra(int s) {
	rdist[s].assign(n, ullmax);
	priority_queue<pair<unsigned long long, unsigned long long>, std::vector<pair<unsigned long long, unsigned long long>>, std::greater<pair<unsigned long long, unsigned long long>>> pq;
	rdist[s][s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int v = pq.top().second; int vw = pq.top().first; pq.pop();
		if (vw > rdist[s][v]) continue;
		for (auto u : radj[v]) {
			if (rdist[s][v] + u.second < rdist[s][u.first]) {
				rdist[s][u.first] = rdist[s][v] + u.second;
				pq.push({ rdist[s][u.first], u.first });
			}
		}
	}
}



int main() {
	std::cin >> n >> m >> k >> q;
	adj.resize(n); radj.resize(n);
	for (int i = 0; i < n; ++i) {
		unsigned long long a, b, w;
		std::cin >> a >> b >> w; --a; --b;
		adj[a].push_back({ b,w });
		if (b > n - 1) continue;
		radj[b].push_back({ a,w });
	}
	dist.resize(k);
	rdist.resize(k);
	for (int i = 0; i < k; ++i) {
		dijkstra(i);
		rdijkstra(i);
	}
	unsigned long long num = 0, fans = 0;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		if (a > n - 1 || b > n - 1) continue;
		unsigned long long tans = ullmax;
		for (int j = 0; j < k; j++) {
			unsigned long long sum = 0;
			if (rdist[j][a] == ullmax || dist[j][b] == ullmax) continue;
			sum = rdist[j][a] + dist[j][b];
			tans = min(sum, tans);
		}
		if (tans == ullmax) continue;
		++num;
		fans += tans;
	}
	cout << num << endl << fans << endl;
	return 0;
}

