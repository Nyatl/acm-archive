#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef LOCAL	
	fprintf(stderr, "\n");
#endif	
}

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

///////////////////////////////////////////////////

#define mt make_tuple

const int MAX = 1041;

char name[MAX][41];
int n, k;
vi versions[MAX];
vector<pair<string, int>> conflicts[MAX];
int ans[MAX];

int conflict[MAX][MAX * 2];
//flow

struct Edge {
	int y, f, c;
	Edge *rev;
	Edge () {};
	Edge (int y, int f, int c) : y(y), f(f), c(c) {};
};

map<tuple<int, int, int>, int> num;
int CNT;
int S, T;
vector<Edge*> e[MAX * MAX];

void pushedge(int x, int y) {
	Edge* e1 = new Edge(y, 0, 1);
	Edge* e2 = new Edge(x, 0, 0);
	e1->rev = e2;
	e2->rev = e1;
	e[x].pb(e1);
	e[y].pb(e2);
}

int getnum(tuple<int, int, int> t) {
	if (!num.count(t)) {
		num[t] = CNT++;
	}
	return num[t];
}

void buildnet() {
	S = getnum(mt(0, 0, 1));
	T = getnum(mt(4, 0, 2));

	fi(1, n) {
		if (ans[i] != -1) { 
			continue;
		}	
		int y = getnum(mt(1, i, -1));
		pushedge(S, y);
	}
	fi(1, n) {
		if (ans[i] != -1) { 
			continue;
		}
		int x = getnum(mt(1, i, -1));
		fj(0, sz(versions[i]) - 1) {
			int y = getnum(mt(2, i, j));
			pushedge(x, y);
		}
	}
	fi(1, n) {
		if (ans[i] != -1) { 
			continue;
		}
		fj(0, sz(versions[i]) - 1) {
			int x = getnum(mt(2, i, j));
			int y = getnum(mt(3, conflict[i][j], -1));
			pushedge(x, y);
		}
	}
	fi(1, k) {
		int x = getnum(mt(3, i, -1));
		pushedge(x, T);
	}
}

Edge *by[MAX * MAX];
int from[MAX * MAX];
int C;
int color[MAX * MAX];

bool dfs(int x) {
	color[x] = C;
	if (x == T) return true;
	for (auto z : e[x]) {
		if (z->c <= z->f) continue;
		if (color[z->y] == C) continue;
		if (dfs(z->y)) {
			by[z->y] = z;
			from[z->y] = x;
			return true;
		}
	}
	return false;
}

void relax() {
	int x = T;
	while (x != S) {
		by[x]->f++;
		by[x]->rev->f--;
		x = from[x];
	}
}

int maxflow() {
	int res = 0;
	C++;
	while (dfs(S)) {
		relax();
		C++;
		res++;
	}
	return res;
}

//end flow

map<pii, pii> num2;

bool restoreanswer() {
	fi(0, CNT - 1) {
		for (auto z : e[i]) {
			if (z->f < z->c) continue;
			if (num2.count(mp(i, z->y))) {
				pii p = num2[mp(i, z->y)];
				ans[p.first] = p.second;
			}
		}
	}
	fi(1, n) {
		if (ans[i] == -1) return false;
	}
	return true;
}

void solve() {
	buildnet();	
	fi(1, n) {
		if (ans[i] != -1) { 
			continue;
		}
		fj(0, sz(versions[i]) - 1) {
			int x = getnum(mt(2, i, j));
			int y = getnum(mt(3, conflict[i][j], -1));
			num2[mp(x, y)] = mp(i, j);
		}
	}
	maxflow();
	if (!restoreanswer()) {
		printf("No\n");
		return;
	} 
	printf("Yes\n");
	fi(1, n) {
		printf("%d ", versions[i][ans[i]]);
	}
}

void init() {
	memset(ans, -1, sizeof(ans));
	map<pair<string, int>, pii> pos;
	fi(1, n) {
		fj(0, sz(versions[i]) - 1) {
			pos[mp(name[i], versions[i][j])] = mp(i, j);
		}
	}
	fi(1, k) {
		for (auto z : conflicts[i]) {
			ass(pos.count(z));
			conflict[pos[z].first][pos[z].second] = i;
		}
	}
	//
	fi(1, n) {
		dbg0(conflict[i], sz(versions[i]));
	}
	//
	fi(1, n) {
		int x = -1;
		fj(0, sz(versions[i]) - 1) {
			if (conflict[i][j] == 0) {
				x = j;
				break;
			} 
		}
		if (x != -1) {
			ans[i] = x;
		}
	}
	dbg1(ans, n);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	fi(1, n) {
		scanf("%s", name[i]);
		int k;
		scanf("%d", &k);
		fj(1, k) {
			int x;
			scanf("%d", &x);
			versions[i].pb(x);
		}
	}
	scanf("%d", &k);
	fi(1, k) {
		int q;
		scanf("%d", &q);
		fj(1, q) {
			char str[41];
			int x;
			scanf("%s %d", str, &x);
			conflicts[i].pb(mp(str, x));
		}
	}

	init();
	solve();

	exit();
	return 0;
}



