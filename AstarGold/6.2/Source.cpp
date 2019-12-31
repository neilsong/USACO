#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
vector<ll> dx{ 1,-1,0,0 }, dy{ 0,0,-1,1 };
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpair;
typedef vector<vector<pair<ll, ll>>> vvpair;

vvpair adj;
ll n, m, k, q;
vll dist;
int main() {
	cin >> n >> m >> k >> q;
	for (int i = 0; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w; a--; b--;
		adj[a].push_back({ b,w });
	}
	dist.resize(k);
	for (int i = 0; i < k; i++) {
		dijkstsra(i);
	}
	return 0;
}