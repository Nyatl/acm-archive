//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381184
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381186
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381188
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381187
//tested: https://codeforces.com/contest/1061/submission/46169776

struct Edge {
	int v;
	int f;
	int c;
	int w;
	int w0;
	Edge *rev;
};

vector<Edge*> e[MAX];

void insert(int x, int v, int c, int w) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->f = 0;
	temp->c = c;
	temp->w = w;
	temp->w0 = w;		

	Edge *temp2 = new Edge;
	temp2->v = x;
	temp2->f = 0;
	temp2->c = 0;
	temp2->w = -w;
	temp2->w0 = 0;
	
	temp->rev = temp2;
	temp2->rev = temp;

	e[x].pb(temp);
	e[v].pb(temp2);
}

int S;
int T;
int k;

map<pii, int> num;

int getnum(pii x) {
	if (!num.count(x)) {
		int g = k + 1;
		num[x] = g;
		k++;
	}
	return num[x];
}

int d[MAX];
Edge *p[MAX];
int color[MAX];

int potential[MAX];

bool bellman() {
	fill_n(&potential[0], k + 1, INF);
	fi(1, k) {
		p[i] = NULL;
	}
	potential[S] = 0;
	bool f = 1;

	while (f) {
		f = 0;
		fi(1, k) {
			if (potential[i] == INF) continue;
			for (auto z : e[i]) {
				if (z->f == z->c) continue;
				if (potential[z->v] > potential[i] + z->w) {
					potential[z->v] = potential[i] + z->w;
					f = 1;
					p[z->v] = z;
				}
			}
		}
	}
	fi(1, k) {
		d[i] = potential[i];
	}
	return (p[T] != NULL);
}

bool dij() {
	fi(1, k) {
		d[i] = INF;
		p[i] = NULL;
		color[i] = 0;
	}
	set <pair<int, int> > t;
	t.insert(mp(0, S));
	d[S] = 0;
	while (sz(t)) {		
		int x = t.begin()->second;
		t.erase(t.begin());
		if (color[x]) continue;
		if (d[x] >= INF) continue;
		color[x] = 1;
		for (auto z : e[x]) {
			if (z->f == z->c) continue;			
			if (d[x] + potential[x] - potential[z->v] + z->w < d[z->v]) {
				d[z->v] = d[x] + potential[x] - potential[z->v] + z->w;
				p[z->v] = z;			
				t.insert(mp(d[z->v], z->v));
			}
		}
	}
	if (p[T] == NULL) return false;	
	fi(1, k) {
		potential[i] += d[i];
	}
	return true;
}

int update() {	
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
	return flow;
}

pii mincostmaxflow() {	
	pii res = mp(0, 0);
	if (!bellman()) return res;	
	dbg1(potential, k);
	while(1) {		
		res.first += update();		
		if (!dij()) break;		
	}	
	fi(1, k) {
		for (auto z : e[i]) {
			res.second += z->w0 * z->f;
		}
	}
	return res;
}
