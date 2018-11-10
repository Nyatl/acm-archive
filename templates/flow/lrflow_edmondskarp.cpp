//tested: https://bacs.cs.istu.ru/submit_view.php?id=1381443
//tested: https://official.contest.yandex.com/ptz-summer-2018/contest/8781/run-report/13889218/

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
int from[MAX];
int pos[MAX];

int bfs() {
	fi(0, sz(num) - 1) {
		dist[i] = -1;
	}
	dist[S1] = 0;
	queue<int> qu;
	qu.push(S1);
	while (sz(qu)) {
		int x = qu.front();
		if (x == T1) break;
		qu.pop();
		fi(0, sz(e[x]) - 1) {
			auto z = e[x][i];
			if (z->f == z->c) continue;
			if (dist[z->v] != -1) continue;
			dist[z->v] = dist[x] + 1;
			qu.push(z->v);
			from[z->v] = x;
			pos[z->v] = i;						
		}
	}

	if (dist[T1] == -1) return 0;
	
	int x = T1;
	int res = INF;
	while (x != S1) {
		auto edge = e[from[x]][pos[x]];
		res = min(res, edge->c - edge->f);
		x = from[x];
	}

	x = T1;	
	while (x != S1) {
		auto edge = e[from[x]][pos[x]];
		edge->f += res;
		if (edge->f == edge->c) {
			swap(e[from[x]][pos[x]], e[from[x]].back());
			e[from[x]].pop_back();
		}
		if (edge->rev->f == edge->rev->c) {
			e[x].pb(edge->rev);
		}
		edge->rev->f -= res;		
		x = from[x];
	}
	
	return res;
}

void buildnet(int INF) {
}

bool checkflow(int INF) {
	buildnet(INF);
	int res = 0;
	while (1) {		
		int resp = bfs();
		if (!resp) break;			
		res += resp;			
	}		
	return (res == WANT);
}