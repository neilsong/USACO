#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<pair<ll, ll>>> vvpll;

ll n, k;
vvll adj;
vll colors;

int main() {
	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");

	adj.resize(n);
	colors.resize(n);

	for (ll i = 0; i < n-1; i++) {
		ll x, y;
		cin >> x >> y; x--; y--;
		adj[x].push_back(y);
	}

	for (ll i = 0; i < k; i++) {
		ll b, c;
		cin >> b >> c; b--;
		colors[b] = c;
	}




	return 0;
}