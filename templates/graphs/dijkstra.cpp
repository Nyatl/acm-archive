//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381775

struct Edge {
	int v;
	int w;
	Edge () {};
	Edge (int v, int w) : v(v), w(w) {};
};

vector<Edge*> e[MAX];

void insert(int x, int v, int w) {
	e[x].pb(new Edge(v, w));
	e[v].pb(new Edge(x, w));
}

ll d[MAX];
int p[MAX];
int color[MAX];

vector<int> dij(int a, int b) {
	fi(1, n) {
		d[i] = INF;
		p[i] = 0;
		color[i] = 0;
	}
	set <pair<ll, int> > t;
	t.insert(mp(0LL, a));
	d[a] = 0;
	while (sz(t)) {
		int x = t.begin()->second;
		t.erase(t.begin());
		if (color[x]) continue;
		color[x] = 1;

		for (auto z : e[x]) {
			if (d[x] + z->w < d[z->v]) {
				d[z->v] = d[x] + z->w;
				p[z->v] = x;
				t.insert(mp(d[z->v], z->v));
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


