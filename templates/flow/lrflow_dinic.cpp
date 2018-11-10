
int S, T;
int S1, T1;
int WANT;

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
	if (!c) return;
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

void insert(int x, int y, int l, int r) {		
	WANT += l;
	insert(x, T1, l);
	insert(S1, y, l);
	insert(x, y, r - l);		
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
	fi(0, sz(num) - 1) {
		dist[i] = -1;
	}
	dist[S1] = 0;
	queue<int> qu;
	qu.push(S1);
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
	return (dist[T1] != -1);
}

int dfs(int x, int f) {
	if (x == T1) return f;
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

void buildnet(int INF) {
	WANT = 0;
	fi(0, MAX - 1) {
		e[i].clear();
	}
	num.clear();
	S = getnum(mp(0, 0));
	T = getnum(mp(2, 0));

	S1 = getnum(mp(0, 1));
	T1 = getnum(mp(2, 1));	

	insert(T, S, INF);

	fi(1, n) {
		int x = getnum(mp(1, i));
		insert(S, x, 0, n * n);
	}

	fi(1, n) {
		int x = getnum(mp(1, i));
		insert(x, T, 0, n * n);
	}
  
  for (auto z : edges) {
  	int x = getnum(mp(1, z.first));
  	int y = getnum(mp(1, z.second));
  	insert(x, y, 1, n * n);
  }
}

bool checkflow(int INF) {
	buildnet(INF);
	int res = 0;
	while (bfs()) {		
		while (res < WANT) {
			int resp = dfs(S1, ::INF);
			if (!resp) break;			
			res += resp;			
		}
	}		
	return (res == WANT);
}
