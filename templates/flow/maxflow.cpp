//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381115

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
int k;

int getnum(pii x) {
	if (!num.count(x)) {
		int g = k + 1;
		num[x] = g;
		k++;
	}
	return num[x];
}

int color[MAX];
int C;

int dfs(int x, int f, int want = 0) {
	if (x == T) return f;
	if (color[x] == C) return 0;
	color[x] = C;
	for (auto z : e[x]) {
		if (z->f == z->c) continue;
		if (z->c - z->f < want) continue;
		int res = dfs(z->v, min(f, z->c - z->f)); 
		if (res) {
			z->f += res;
			z->rev->f -= res;
			return res;
		}
	}
	return 0;
}

const int INF = 1000 * 1000 * 1000 + 41;

int maxflow() {
	int res = 0;
	int flow = INF;
	while(flow > 0) {
		C++;
		int f = dfs(S, flow, flow);
		if (f == 0) {
			flow /= 2;
		} else {
			res += f;
		}		
	}
	return res;
}
