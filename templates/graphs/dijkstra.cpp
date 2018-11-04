struct Edge {
	int v;
	int w;
	Edge *next;
};

Edge *e[MAX];

void insert(int x, int v, int w) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->w = w;
	temp->next = e[x];
	e[x] = temp;
}

int d[MAX];
int p[MAX];
int color[MAX];

vector<int> dij(int a, int b) {
	fi(1, n) {
		d[i] = INF;
		p[i] = 0;
		color[i] = 0;
	}
	set <pair<int, int> > t;
	t.insert(mp(0, a));
	d[a] = 0;
	while (sz(t)) {
		int x = t.begin()->second;
		t.erase(t.begin());
		if (color[x]) continue;
		color[x] = 1;

		for (Edge *y=e[x]; y; y=y->next) {
			if (d[x] + y->w < d[y->v]) {
				d[y->v] = d[x] + y->w;
				p[y->v] = x;
				t.insert(mp(d[y->v], y->v));
			}
		}
	}
	vector<int> res;
	if (p[b] == 0) return res;
	int x = b;
	res.pb(x);
	while (x != a) {
		x = p[x];
		res.pb(x);
	}
	return res;
}