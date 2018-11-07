//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381136
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381137
//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381141


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
}

map<pii, int> num;

int getnum(pii x) {
	if (!num.count(x)) {
		int g = sz(num);
		num[x] = g;
	}
	return num[x];
}


int dist[MAX];

bool bfs() {
	fi(1, n) {
		dist[i] = -1;
	}
	dist[S] = 0;
	queue<int> qu;
	qu.push(S);
	while (sz(qu)) {
		int x = qu.front();
		qu.pop();
		for (auto z : e[x]) {
			if (z->f == z->c) continue;
			if (dist[z->v] != -1) continue;
			dist[z->v] = dist[x] + 1;
			qu.push(z->v);
		}
	}
	return (dist[T] != -1);
}

int dfs(int x, int f) {
	if (x == T) return f;
	fi(0, sz(e[x]) - 1) {
		auto z = e[x][i];

		if (z->f == z->c) continue;		
		if (dist[x] + 1 != dist[z->v]) continue;
		int res = dfs(z->v, min(f, z->c - z->f)); 
		if (res) {			
			z->f += res;
			if (z->f == z->c) {
				swap(e[x][i], e[x].back());
				e[x].pop_back();
			}
			if (z->rev->f == z->rev->c) {										
				e[z->v].pb(z->rev);
			}
			z->rev->f -= res;
			return res;
		}
	}
	return 0;
}

const int INF = 1000 * 1000 * 1000 + 41;

int maxflow() {
	int res = 0;
	while (1) {
		if (!bfs()) break;	
		while (1) {
			int resp = dfs(S, INF);
			if (!resp) break;
			res += resp;
		}		
	}	
	return res;
}
