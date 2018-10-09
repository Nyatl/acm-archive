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

#define MAX 1010

int n, k;

map<string, int> num;

vpii conflict[MAX];
map<int, int> version[MAX];
set<pair<int, int> > avl;

int ans[MAX];

struct Edge {
	int v;
	int f;
	int c;
	int ver;
	Edge *inv;
	Edge *next;
};

Edge *e[101000];

void insert(int x, int v, int c, int ver = 0) {
	Edge *temp = new Edge;
	temp->v = v;
	temp->f = 0;
	temp->c = c;
	temp->ver = ver;
	temp->next = e[x];
	e[x] = temp;

	Edge *temp2 = new Edge;
	temp2->v = x;
	temp2->f = 0;
	temp2->c = 0;
	temp2->ver = -1;
	temp2->next = e[v];
	e[v] = temp2;
	temp->inv = temp2;
	temp2->inv = temp;
}

int N, M;

int S = 1;
int T = 2;

map<int, int> L1;
map<int, int> L2;

int layer1(int x) {
	if (!L1.count(x)) {
		N++;
		L1[x] = N;
	}
	return L1[x];
}

int layer2(int x) {
	if (!L2.count(x)) {
		N++;
		L2[x] = N;
	}
	return L2[x];
}

int color[101000];
int C;

bool dfs(int x) {
	if (color[x] == C) return false;
	color[x] = C;
	if (x == T) {
		errln("+");
		return true;
	}
	for (Edge *y = e[x]; y; y=y->next) {
		if (y->f == y->c) continue;
		if (dfs(y->v)) {
			y->f++;
			y->inv->f--;
			return true;
		}
	}
	return false;
}

void solve() {
	N = 2;
	fi(1, n) {
		if (ans[i]) continue;
		insert(S, layer1(i), 1);
		errln("S -> %d (L1)", i);
	}
	fi(1, k) {
		insert(layer2(i), T, 1);	
		errln("%d (L2) -> T", i);
	}

	fi(1, k) {
		for (auto &z : conflict[i]) {
			insert(layer1(z.first), layer2(z.second), 1, version[i][z.first]);
			errln("%d (L1) -> %d (L2)", z.first, z.second);
		}
	}

	dbg(N);

	while (1) {
		C++;
		if (!dfs(S)) break;
	}

	fi(1, n) {
		if (ans[i]) continue;
		for (Edge *y = e[layer1(i)]; y; y=y->next) {
			if (y->f && y->ver > 0) {
				ans[i] = y->ver;
				break;
			}
		}
	}
	fi(1, n) {
		if (ans[i] == 0) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
	fi(1, n) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	fi(1, n) {
		char g[20];
		scanf("%s", g);
		num[g] = i;
		int q;
		scanf("%d", &q);
		fj(1, q) {
			int x;
			scanf("%d", &x);
			avl.insert(mp(i, x));
		}
	}

	scanf("%d", &k);

	fi(1, k) {
		int q;
		scanf("%d", &q);
		fj(1, q) {
			char g[20];
			scanf("%s", g);
			int x;
			scanf("%d", &x);
			avl.erase(mp(num[g], x));
			conflict[i].pb(mp(num[g], i));
			version[i][num[g]] = x;			
		}
	}

	dbg(avl);
	fi(1, k) {
		dbg(conflict[i]);
		dbg(version[i]);
	}

	for (auto z : avl) {
		ans[z.first] = z.second;
	}

	solve();

	exit();
	return 0;
}