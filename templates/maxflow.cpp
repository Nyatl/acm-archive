struct Edge {
	int v;
	int f;
	int c;
	Edge *next, *rev;
};

Edge *e[MAX];

void insert(int x, int v, int c) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->f = 0;
	temp->c = c;
	temp->next = e[x];
	e[x] = temp;

	Edge *temp2 = new Edge;
	temp2->v = x;
	temp2->f = 0;
	temp2->c = 0;
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

int color[MAX];
int C;

int dfs(int x, int f) {
	if (x == T) return f;
	if (color[x] == C) return 0;
	C++;
	for (Edge *y=e[x]; y; y=y->next) {
		if (y->f == y->c) continue;
		int res = dfs(y->v, min(f, y->c - y->f)); 
		if (res) {
			y->f += res;
			y->rev->f -= res;
			return res;
		}
	}
	return 0;
}

int maxflow() {
	int res = 0;
	int flow = INF;
	while(flow > 0) {
		C++;
		int f = dfs(S, flow);
		if (f == 0) {
			flow /= 2;
		} else {
			res += f;
		}
	}
	return res;
}
