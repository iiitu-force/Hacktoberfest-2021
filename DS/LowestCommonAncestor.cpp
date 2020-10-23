vector<int> depth(n + 1);
vector<vector<int>> parent(n + 1, vector<int>(level, -1));
function<void(int, int, int)> dfs = [&](int x, int prev, int h) {
	depth[x] = h;
	parent[x][0] = prev;
	for (auto &i : v[x]) {
		if (i != prev) {
			dfs(i, x, h + 1);
		}
	}
};
auto precomputeSparseMatrix = [&](int n) {
	for (int i = 1; i < level; i++) {
		for (int node = 1; node <= n; node++) {
			if (parent[node][i - 1] != -1) {
				parent[node][i] = parent[parent[node][i - 1]][i - 1];
			}
		}
	}
};
auto lca = [&](int u, int v)->int {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}
	int diff = depth[v] - depth[u];
	for (int i = 0; i < level; i++) {
		if ((diff >> i) & 1) {
			v = parent[v][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = level - 1; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
};
