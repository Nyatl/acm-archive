//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381117
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381133

int S, T;

struct Edge {
	int v;
	int f;
	int c;
	Edge *rev;
	Edge () {};
	Edge (int v, int f, int c) : v(v), f(f), c(c) {};
};

vector<Edge*> e[MAX];

void insert(int x, int v, int c) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->f = 0;
	temp->c = c;	

	Edge *temp2 = new Edge;
	temp2->v = x;
	temp2->f = 0;
	temp2->c = 0;	

	temp->rev = temp2;
	temp2->rev = temp;

	e[x].pb(temp);
	e[v].pb(temp2);
}

map<pii, int> num;

int getnum(pii x) {
	if (!num.count(x)) {
		int g = sz(num);
		num[x] = g;
	}
	return num[x];
}

int color[MAX];
int C;
int from[MAX];
Edge *by[MAX];

const int INF = 1000 * 1000 * 1000 + 41;

int bfs(int want = 1) {
	C++;
	queue<int> qu;
	qu.push(S);
	color[S] = C;

	while (sz(qu)) {
		int x = qu.front();
		qu.pop();
		if (x == T) {
			break;
		}
		for (auto z : e[x]) {
			if (z->c - z->f < want) continue;
			if (color[z->v] == C) continue;
			color[z->v] = C;
			qu.push(z->v);
			from[z->v] = x;
			by[z->v] = z;
		}
	}
	if (color[T] != C) return 0;

	int x = T;
	int res = INF;
	while (x != S) {
		res = min(res, by[x]->c - by[x]->f);
		x = from[x];
	}

	x = T;
	while (x != S) {
		by[x]->f += res;
		by[x]->rev->f -= res;
		x = from[x];
	}

	return res;
}

int maxflow() {
	int res = 0;
	int flow = INF;
	while(flow > 0) {
		C++;
		int f = bfs(flow);
		if (f == 0) {
			flow /= 2;
		} else {
			res += f;
		}		
	}
	return res;
}