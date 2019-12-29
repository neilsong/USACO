//MIN RANGE SEGMENT TREE: range/point (queries, updates)
struct node {
	int l, r;
	long long m;
}tree[4 * n];

void build(int x, int l, int r) {
	tree[x].l = l;
	tree[x].r = r;
	if (l != r) {
		build(2 * x, l, (l + r) / 2);
		build(2 * x + 1, (l + r) / 2 + 1, r);
		tree[x].m = min(tree[2 * x].m, tree[2 * x + 1].m);
	}
	else tree[x].m = INT_MAX;
}

void update(int x, int y, long long v) {
	if (tree[x].r < y || tree[x].l > y) return;
	if (tree[x].l == tree[x].r) {
		tree[x].m = min(tree[x].m, v);
		return;
	}
	update(2 * x, y, v);
	update(2 * x + 1, y, v);
	tree[x].m = min(tree[2 * x].m, tree[2 * x + 1].m);

}

long long query(int x, int ql, int qr) {
	if (tree[x].r < ql || tree[x].l  > qr) return INT_MAX;
	if (tree[x].l >= ql && tree[x].r <= qr) return tree[x].m;
	return min(query(2 * x, ql, qr), query(2 * x + 1, ql, qr));
}