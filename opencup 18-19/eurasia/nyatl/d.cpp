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

#define MAX 100010

int n, k, m;

set<pii> fb;
int cnt[MAX];

void rename(int from, int to) {
	errln("%d -> %d", from, to);
	vpii to_del, to_add;
	auto it = fb.lower_bound(mp(from, -1));
	while (it != fb.end() && it->first == from) {
		to_del.pb(mp(it->first, it->second));
		to_del.pb(mp(it->second, it->first));
		to_add.pb(mp(to, it->second));
		to_add.pb(mp(it->second, to));
		it++;
	}
	for (auto z : to_del) {
		assert(fb.count(z));
		fb.erase(z);
	}
	for (auto z : to_add) {
		fb.insert(z);
	}
	dbg(fb);
}

struct Node {
	int c;
	Node *p; 
};

Node *node[MAX];

Node *find(Node *x) {
	if (x->p == x) return x;
	return x->p = find(x->p);
}

int color(int a) {
	return find(node[a])->c;
}

void unite(int a, int b) {
	int c1 = color(a);
	int c2 = color(b);
	if (cnt[c1] < cnt[c2]) {
		rename(c1, c2);
		find(node[a])->p = find(node[b]);
		cnt[c2] += cnt[c1];
	} else {
		rename(c2, c1);
		find(node[b])->p = find(node[a]);
		cnt[c1] += cnt[c2];
	}
}

bool check(int a, int b) {
	int c1 = color(a);
	int c2 = color(b);
	if (fb.count(mp(c1, c2)) || fb.count(mp(c2, c1))) return false;
	if (c1 == c2) {
		return true;
	}
	unite(a, b);
	return true;
}

int COLOR[152];
int matr[152][152];

vpii edges;
vpii vfb;

void dfs(int x) {
	if (COLOR[x]) return;
	COLOR[x] = 1;
	fi(1, n) {
		if (!matr[x][i]) continue;
		dfs(i);
	}
}

bool path(int a, int b) {
	clr(COLOR);
	dfs(a);
	return COLOR[b];
}

vector<int> brute() {
	vi res;
	fi(1, m) {
		matr[edges[i].first][edges[i].second] = 1;
		matr[edges[i].second][edges[i].first] = 1;
		int f = 1;
		for (auto z : vfb) {
			if (path(z.first, z.second)) {
				f = 0;
				break;
			}
		}
		if (!f) {
			matr[edges[i].first][edges[i].second] = 0;
			matr[edges[i].second][edges[i].first] = 0;
		} else {
			res.pb(i);
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d %d", &n, &k, &m);
	fi(1, k) {
		int a, b;
		scanf("%d %d", &a, &b);
		fb.insert(mp(a, b));
		fb.insert(mp(b, a));
		cnt[a]++;
		cnt[b]++;
		vfb.pb(mp(a, b));
	}

	fi(1, n) {
		node[i] = new Node();
		node[i]->p = node[i];
		node[i]->c = i;
	}

	vi ans;

	dbg(fb);

	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (check(a, b)) ans.pb(i);
		edges.pb(mp(a, b));
	}

	printf("%d\n", sz(ans));
	fi(0, sz(ans) - 1) {
		printf("%d ", ans[i]);
	}
	printf("\n");

#ifdef LOCAL
	/*vi res = brute();
	printf("-----\n");
	printf("%d\n", sz(res));
	fi(0, sz(res) - 1) {
		printf("%d ", res[i]);
	}
	printf("\n");*/
#endif

	exit();
	return 0;
}