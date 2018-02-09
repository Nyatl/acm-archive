struct Edge {
	int v;
	int f;
	int c;
	int w;
	int w0;
	Edge *next, *rev;
};

Edge *e[MAX];

void insert(int x, int v, int c, int w) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->f = 0;
	temp->c = c;
	temp->w = w;
	temp->w0 = w;
	temp->next = e[x];
	e[x] = temp;

	Edge *temp2 = new Edge;
	temp2->v = x;
	temp2->f = 0;
	temp2->c = 0;
	temp2->w = -w;
	temp2->w0 = 0;
	temp2->next = e[v];
	e[v] = temp2;

	temp->rev = temp2;
	temp2->rev = temp;
}

int S = 1;
int T = 2;
int _num1[MAX];
int _num2[MAX];
int k = 2;

int num1(int x) {
	if (_num1[x] == 0) {
		k++;
		_num1[x] = k;
	}
	return _num1[x];
}

int num2(int x) {
	if (_num2[x] == 0) {
		k++;
		_num2[x] = k;
	}
	return _num2[x];
}

int d[MAX];
Edge *p[MAX];
int color[MAX];

bool dij() {
	fi(1, k) {
		d[i] = INF;
		p[i] = NULL;
		color[i] = 0;
	}
	set <pair<double, int> > t;
	t.insert(mp(0, S));
	d[S] = 0;
	while (sz(t)) {
		int x = t.begin()->second;
		t.erase(t.begin());
		if (color[x]) continue;
		color[x] = 1;

		for (Edge *y=e[x]; y; y=y->next) {
			if (y->f == y->c) continue;
			if (d[x] + y->w < d[y->v]) {
				d[y->v] = d[x] + y->w;
				p[y->v] = y;
				t.insert(mp(d[y->v], y->v));
			}
		}
	}
	return p[T] != NULL;
}

void update() {
	int flow = INF;
	int x = T;
	while (x != S) {
		flow = min(flow, p[x]->c - p[x]->f);
		x = p[x]->rev->v;
	}
	x = T;
	while (x != S) {
		p[x]->f += flow;
		p[x]->rev->f -= flow;
		x = p[x]->rev->v;
	}

	fi(1, k) {
		for (Edge *y=e[i]; y; y=y->next) {
			y->w += d[i] - d[y->v];
		}
	}
}

int mincostmaxflow() {
	while(dij()) {
		update();
	}
	int res = 0;
	fi(1, k) {
		for (Edge *y=e[i]; y; y=y->next) {
			res += y->w0 * y->f;
		}
	}
	return res;
}
