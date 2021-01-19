#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;    // No. of vertices 
	vector<vector<int>> adj;    // Pointer to an array containing adjacency lists 
public:
	Graph(int V);  // Constructor 
	void addEdge(int v, int w); // function to add an edge to graph 
	bool isReachable(int s, int d);
	void removeEdge(int v, int w);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = vector<vector <int> >(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}		

void Graph::removeEdge(int v, int w) {
	adj[v].erase(find(adj[v].begin(), adj[v].end(), w));
	adj[w].erase(find(adj[w].begin(), adj[w].end(), v));
}

// A BFS based function to check whether d is reachable from s. 
bool Graph::isReachable(int s, int d)
{
	// Base case 
	if (s == d)
		return true;

	// Mark all the vertices as not visited 
	vector<bool>visited(V,0);

	// Create a queue for BFS 
	stack<int> queue;

	// Mark the current node as visited and enqueue it 
	queue.push(s);

	while (true)
	{
		if (queue.empty()) {
			break;
		}
		s = queue.top();
		queue.pop();
		if (visited[s]) {
			continue;
		}
		visited[s] = 1;

		for (auto i : adj[s])
		{
			if (i == d) {
				return true;
			}
			if (!visited[i])
			{
				queue.push(i);
			}
		}
	}
	return false;
}

// Driver program to test methods of graph class 
int main()
{
	// Create a graph given in the above diagram 
	
	int n, k, r;
	cin >> n >> k >> r;
	Graph g((n+1)*(n+1));

	map<pair<int, int>, pair<int, int>>f1;

	
	int v = 0;
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			if (i > 0) {
				g.addEdge(v, v - n-1);
			}
			if (i < n) {
				g.addEdge(v, v + n+1);
			}
			if (j > 0) {
				g.addEdge(v, v - 1);
			}
			if (j < n) {
				g.addEdge(v, v + 1);
			}
			v++;
		}
	}
	
	for (int i = 0; i < k; i++) {
		int l, j, i1, j1;
		cin >> l >> j >> i1 >> j1;
		g.removeEdge((l * (n+1)) + j, (i1 * (n+1)) + j1);
	}
	vector<int> testverts;
	for (int i = 0; i < r; i++) {
		int q, j;
		cin >> q >> j;
		int cv = (q * (n+1)) + j;
		testverts.push_back(cv);
	}
	int ccount = r;
	for (int i = 0; i < r; i++) {
		for (int j = i+1; j < r; j++) {
			if (g.isReachable(testverts[i], testverts[j])) {
				ccount--;
			}
		}
	}
	cout << ccount << endl;
	return 0;
}