//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381095

int CNT;
vi e[MAX];
int lca[MAX][LOG];
int tin[MAX];
int tout[MAX];

bool isa(int a, int b) {
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int getlca(int a, int b) {
	if (isa(a, b)) return a;
	if (isa(b, a)) return b;
	fdi(LOG - 1, 0) {
		if (lca[a][i] == -1 || isa(lca[a][i], b)) continue;
		a = lca[a][i];
	}
	return lca[a][0];
}

void dfs0(int x, int p = -1) {
	CNT++;
	tin[x] = CNT;
	memset(lca[x], -1, sizeof(lca[x]));
	lca[x][0] = p;
	fi(1, LOG - 1) {
		int pp = lca[x][i - 1];
		if (pp != -1) lca[x][i] = lca[pp][i - 1];
	}
	for (int y : e[x]) {
		if (y == p) continue;
		dfs0(y, x);
	}
	tout[x] = CNT;
}