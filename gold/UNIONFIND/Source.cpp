vector<int> parent, sizes;

//find size of CC of x -> size[root(x)]

//path compression find
int root(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = root(parent[v]);
}

//union by size
void join(int u, int v) {
	int U = root(u); int V = root(v);
	if (U == V) return;
	if (sizes[U] < sizes[V]) {
		parent[U] = V;
		sizes[V] += sizes[U];
	}
	else {
		parent[V] = U;
		sizes[U] += sizes[V];
	}
}