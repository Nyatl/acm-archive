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

#define INF 100000000000LL

int n;

struct Node {
	Node() {
		sum = 0;
		left = NULL;
		right = NULL;
	}
	ll sum;
	Node *left, *right;
};

Node mem[10000000];
int mem_cur;

Node* create() {
	return &mem[mem_cur++];
}

ll get_sum(ll l, ll r, Node *x, ll tl = -1, ll tr = INF) {
	if (x == NULL) return 0;
	if (l == tl && r == tr) return x->sum;
	ll h = (tl + tr) >> 1;
	if (r <= h) {
		return get_sum(l, r, x->left, tl, h);
	} else if (l >= h + 1) {
		return get_sum(l, r, x->right, h + 1, tr);
	} else {
		return get_sum(l, h, x->left, tl, h) + get_sum(h + 1, r, x->right, h + 1, tr);
	}
}

void update(ll p, ll v, Node *x, ll tl = -1, ll tr = INF) {
	if (tl == tr) {
		x->sum += v;
		return;
	}
	ll h = (tl + tr) >> 1;
	if (p <= h) {
		if (x->left == NULL) {
			Node *g = create();
			x->left = g;
		}
		update(p, v, x->left, tl, h);
	} else {
		if (x->right == NULL) {
			Node *g = create();
			x->right = g;
		}
		update(p, v, x->right, h + 1, tr);
	}
	x->sum = (x->left != NULL ? x->left->sum : 0) + (x->right != NULL ? x->right->sum : 0);
}

Node *pref_cnt, *pref_sum, *suff_cnt, *suff_sum;

void init() {
	pref_cnt = create();
	pref_sum = create();
	suff_cnt = create();
	suff_sum = create();
}

ll read() {
	ll a, b;
	char g[20];
	scanf("%lld.%s", &a, g);
	while (strlen(g) < 6) strcat(g, "0");
	sscanf(g, "%lld", &b);
	return a * 1000000 + b;
}

int main() {
#ifdef LOCAL
	freopen("i.in", "r", stdin);
	freopen("i.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	init();

	scanf("%d", &n);

	ll s = 0;
	ll q = 0;
	ll ALL = 0;

	fi(1, 2 * n) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			ll c, r;
			c = read();
			r = read();
			c = (c + s * 1000000) % (n * 1000000LL);
			ll x1 = c - r;
			ll x2 = c + r;
			x1 = max(x1, -1LL);
			dbg(x1);
			dbg(x2);
			update(x2, 1, pref_cnt);
			update(x1, 1, suff_cnt);
			update(x2, q, pref_sum);
			update(x1, q, suff_sum);
			ALL += q;
			q++;
		} else if (type == 1) {
			ll p = read();
			p = (p + s * 1000000) % (n * 1000000LL);

			ll cnt = q - get_sum(-INF, p - 1, pref_cnt) - get_sum(p + 1, INF, suff_cnt);
			ll sum = ALL - get_sum(-INF, p - 1, pref_sum) - get_sum(p + 1, INF, suff_sum);

			errln();
			printf("%lld\n", cnt);
			s += sum;
		}
	}

	exit();
	return 0;
}