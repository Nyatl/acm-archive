//tested: https://bacs.cs.istu.ru/submit_view.php?id=1387517

int child[MAX];
vi ec[MAX];
int par[MAX];
int root;

void dfs2(int x, int p = -1) {
	child[x] = 1;
	for (int y : e[x]) {
		if (y == p) continue;
		if (par[y] != 0) continue;
		dfs2(y, x);
		child[x] += child[y];
	}
}

int getcentroid(int x, int size = 0, int p = -1) {
	int b = -1;
	int bv = 0;
	for (int y : e[x]) {
		if (y == p) continue;
		if (par[y] != 0) continue;
		if (child[y] > bv) {
			bv = child[y];
			b = y;
		}
	}
	int all = child[x] + size;
	if (max(size, bv) * 2 <= all) {
		return x;
	}
	return getcentroid(b, size + child[x] - bv, x);
}

void buildcentroid(int x, int p = -1) {	
	dfs2(x);
	int centroid = getcentroid(x);
	par[centroid] = p;
	if (p != -1) {
		ec[p].pb(centroid);
	} else {
		root = centroid;
	}
	for (int y : e[centroid]) {
		if (par[y] != 0) continue;
		buildcentroid(y, centroid);
	}
}