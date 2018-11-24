struct Edge {
	int x, y, f, c, w;
	Edge *rev;
	Edge () {};
	Edge (int x, int y, int f, int c, int w) : x(x), y(y), f(f), c(c), w(w) {};
};

vector<Edge*> e[MAX];

void addedge(int x, int y, int c, int w) {
	Edge * e1 = new Edge(x, y, 0, c, w);
	Edge * e2 = new Edge(y, x, 0, 0, -w);	
	e1->rev = e2;
	e2->rev = e1;
	e[x].pb(e1);
	e[y].pb(e2);
}

map<pii, int> num;

int getnum(pii x) {
	if (!num.count(x)) {
		int g = k + 1;
		num[x] = g;
		k++;
	}
	return num[x];
}

int S, T;

int dist[MAX];
Edge *by[MAX];

bool bellmanford() {
	fill_n(&dist[0], n + 1, INF);
	fi(1, n) {
		by[i] = NULL;
	}

	dist[S] = 0;
	
	bool f = 1;
	while (f) {
		f = false;
		fi(1, n) {
			if (dist[i] == INF) continue;
			for (auto z : e[i]) {
				if (z->f == z->c) continue;
				if (dist[z->y] > dist[i] + z->w) {
					dist[z->y] = dist[i] + z->w;
					by[z->y] = z;
					f = 1;
				}
			}
		}
	}

	return (by[T] != NULL);
}

pii relax() {
	int flow = INF;
	int x = T;
	while (x != S) {
		flow = min(flow, by[x]->c - by[x]->f);
		x = by[x]->x;
	}

	x = T;
	while (x != S) {
		by[x]->f += flow;
		by[x]->rev->f -= flow;
		x = by[x]->x;
	}

	return mp(flow, flow * dist[T]);
}

pii operator+(const pii &a, const pii &b) {
	return mp(a.first + b.first, a.second + b.second);
};

pii mincostmaxflow() {
	pii res = mp(0, 0);
	while (bellmanford()) {
		pii resp = relax();
		res = res + resp;
	}
	return res;
}
