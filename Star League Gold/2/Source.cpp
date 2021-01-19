#include <bits/stdc++.h> 
using namespace std;
vector<vector <int>> adj;
vector <int> trav;
vector<int> wells;
int n;

//matrix
long MST() {
	vector <int> visited(n, 0), dist;
	dist = wells;
	int count = 0;
	long ans = 0;
	while (count < n) {
		pair<int, int> minv = { 0,INT_MAX };
		int ind = 0;
		for (auto i : dist) {
			if (!visited[ind]) {
				if (minv.second > i) {
					minv.first = ind;
					minv.second = i;
				}
			}
			ind++;
		}
		visited[minv.first] = 1;
		ans += minv.second;
		count++;
		int distind = 0;
		for (int j = 0; j < n; j++) {
			if (adj[minv.first][j] != 0 && !visited[j] && dist[j] > adj[minv.first][j]) {
				dist[j] = adj[minv.first][j];
			}
		}
	}
	return ans;
}

// Driver code 
int main()
{
	
	cin >> n;
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		int well;
		cin >> well;
		wells.push_back(well);
		adj[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ele;
			cin >> ele;
			adj[i][j] = ele;
		}
	}
	cout << MST() << endl;
	

	return 0;
}