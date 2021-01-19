#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> W, H, prev, next;
int n;

int main(void) {
	cin >> n;
	W.resize(n+2); H.resize(n+2);
	W[0] = INF; H[0] = INF;

	int x = INF;
	
	for (int i = 0; i < n; i++) {		
		cin >> W[i+1] >> H[i+1];
		x = min(x, H[i+1]);
	}
	fill(x);
}