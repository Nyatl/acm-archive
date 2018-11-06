//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381100

//tree

vi st[MAX];

void build(vi &st, vi &a, int tl, int tr, int x = 1) {
	if (tl == tr) {
		st[x] = a[tl];
		return;
	}
	int h = (tl + tr) / 2;
	build(st, a, tl, h, 2 * x);
	build(st, a, h + 1, tr, 2 * x + 1);
	st[x] = max(st[2 * x], st[2 * x + 1]); 
}

int get_max(vi &st, int l, int r, int tl, int tr, int x = 1) {
	if (l == tl && r == tr) {
		return st[x];
	}
	int h = (tl + tr) / 2;
	if (r <= h) {
		return get_max(st, l, r, tl, h, 2 * x);
	} else if (l >= h + 1) {
		return get_max(st, l, r, h + 1, tr, 2 * x + 1);
	} else {
		return max(get_max(st, l, h, tl, h, 2 * x), get_max(st, h + 1, r, h + 1, tr, 2 * x + 1)); 
	}
}

void update(vi &st, int p, int v, int tl, int tr, int x = 1) {
	if (tl == tr) {
		st[x] = v;
		return;
	}
	int h = (tl + tr) / 2;
	if (p <= h) {
		update(st, p, v, tl, h, 2 * x);
	} else {
		update(st, p, v, h + 1, tr, 2 * x + 1);
	}
	st[x] = max(st[2 * x], st[2 * x + 1]);
}

//end tree

//lca

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

//end lca

//hld
int sum[MAX];
int in[MAX];
int link[MAX];

int par[MAX];
int cnt[MAX];

vi ver[MAX];
int pos[MAX];

void update(int x, int v) {
	update(st[link[x]], pos[x], v, 1, sz(ver[link[x]]));
}

const int INF = 1000 * 1000 * 1000 + 41;

int get_line_max(int x1, int x2) {
	int start = link[x1];
	int l = in[x2] - in[start] + 1;
	int r = in[x1] - in[start] + 1;
	int res = get_max(st[start], l, r, 1, sz(ver[start]));
	return res;
}

int process(int x, int lca) {
	int res = -INF;
	while (1) {
		int x2 = link[x];
		if (isa(x2, lca)) {			
			res = max(res, get_line_max(x, lca));
			break;
		} else {			
			res = max(res, get_line_max(x, x2));
			x = par[x2];
		}
	}
	return res;
}

int get_max(int x, int y) {
	int lca = getlca(x, y);
	return max(process(x, lca), process(y, lca));
}

int dfs(int x, int p = -1) {
	sum[x]++;
	par[x] = p;
	for (auto y : e[x]) {
		if (y == p) continue;
		sum[x] += dfs(y, x);
	}
	return sum[x];
}

int cur;

void dfs2(int x, int p = -1) {
	int fst = 1;
	cur++;
	in[x] = cur;
	for (auto y : e[x]) {
		if (y == p) continue;
		if (fst) {
			link[y] = link[x];
		} else {
			link[y] = y;
		}
		fst = 0;
		dfs2(y, x);
	}
}

void init() {
	dfs(1);
	fi(1, n) {
		sort(all(e[i]), [](int a, int b) {
			return sum[a] > sum[b];
		});
	}
	link[1] = 1;
	dfs2(1);	
}

//end hld
