#include <bits/stdc++.h>
using namespace std;
int n;



vector<map<int,pair<int,int>>>adj;
int ans = INT_MAX;
vector<int> btimes;
vector<int> etimes;


void printAllPathsUtil(int u, int d, vector <bool> visited,
	vector <int> path, int& path_index)
{
	visited[u] = true;
	path[path_index] = u;
	path_index++;

	if (u == d)
	{
		int btime = 0, etime = 0;
		for (int i = 0; i < path_index - 1; i++) {
			if (path[i] == -1) {
				break;
			}
			pair<int,int> V = adj[path[i]][path[i+1]];
			btime += V.first;
			etime += V.second;
		}
		btimes.push_back(btime);
		etimes.push_back(etime);
		
	}
	else
	{
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[i->first])
				printAllPathsUtil(i->first, d, visited, path, path_index);
	}


	path_index--;
	visited[u] = false;
}

void printAllPaths(int s, int d)
{
	// Mark all the vertices as not visited 
	vector <bool> visited(n);

	// Create an array to store paths 
	vector <int> path(n,-1);
	int path_index = 0; // Initialize path[] as empty 

	// Initialize all vertices as not visited 
	for (int i = 0; i < n; i++)
		visited[i] = false;

	printAllPathsUtil(s, d, visited, path, path_index);
}


int main(void) {
	int m; cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int v1, v2, w1, w2;
		cin >> v1 >> v2 >> w1 >> w2;
		adj[v1-1].insert(make_pair(v2-1,make_pair(w1,w2)));
	}
	printAllPaths(0, n-1);
	set<int>::iterator ls;
	sort(btimes.begin(), btimes.end());
	sort(etimes.begin(), etimes.end());
	vector<int>ans;
	set_intersection(btimes.begin(), btimes.end(), etimes.begin(), etimes.end(), back_inserter(ans));
	if (ans.empty()) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans[0] << endl;
	}
	
}