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

mt19937 generator(41);

int getrandint(int l, int r) {
	ll res = generator();
	return (int) (res % (r - l + 1) + l);
}

ll const SHIFT = 1000 * 1000;

int n;
ll sum;

ll getll(double x) {
	return (ll) (x * SHIFT + 0.5);
}

ll getrealpos(ll x) {
	return (x + sum * SHIFT) % (n * SHIFT);
}

vi prior;
int ptper;

int const MAX = 200 * 1000 + 41;

int getprior() {
	int res = prior[ptper];
	ptper = (ptper + 1) % sz(prior);
	return res;
}

void init() {
	fi(1, MAX) {
		prior.pb(i);
	}
	fi(0, sz(prior) - 1) {
		int x = getrandint(0, sz(prior) - 1);
		swap(prior[i], prior[x]);
	}
}

struct Treap {
	int p;
	ll k;
	ll val, sum, cnt, q;
	Treap *l, *r;

	Treap (ll k, ll val, ll q) {
		this->k = k;
		this->val = val;
		this->sum = val;
		this->q = q;
		this->cnt = q;
		p = getprior();
		l = r = NULL;
	}
};

Treap *root;

void recalc(Treap *t) {
	if (!t) return;
	t->sum = t->val;
	t->cnt = t->q;
	if (t->l) {
		t->sum += t->l->sum;
		t->cnt += t->l->cnt;
	}
	if (t->r) {
		t->sum += t->r->sum;
		t->cnt += t->r->cnt;
	}
}

void merge(Treap *&t, Treap *l, Treap *r) {
	if (!l || !r) {
		t = (l ? l : r);
		recalc(t);
	} else {
		if (l->p > r->p) {
			t = l;
			merge(t->r, l->r, r);
		} else {
			t = r;
			merge(t->l, l, r->l);
		}
		recalc(t);
	}
}

void split(Treap *t, Treap *&l, Treap *&r, ll k) {
	if (!t) {
		l = r = NULL;
	} else {
		if (t->k < k) {
			l = t;
			split(t->r, l->r, r, k);
			recalc(l);
		} else {
			r = t;
			split(t->l, l, r->l, k);
			recalc(r);
		}
	}
}

void insert(Treap *x) {
	Treap *tl, *tr;
	split(root, tl, tr, x->k);
	merge(root, tl, x);
	merge(root, root, tr);
}

ll getcnt(Treap *x, ll k) {
	if (!x) return 0LL;
	ll res = 0;
	if (x->k < k) {
		res += x->q;
		if (x->l) res += x->l->cnt;
		res += getcnt(x->r, k);
	} else {
		res += getcnt(x->l, k);
	}
	return res;
}

ll getsum(Treap *x, ll k) {
	if (!x) return 0LL;
	ll res = 0;
	if (x->k < k) {
		res += x->val;
		if (x->l) res += x->l->sum;
		res += getsum(x->r, k);
	} else {
		res += getsum(x->l, k);
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	init();
//
	scanf("%d", &n);
	int id = 0;
	fi(1, n * 2) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			double c, rd;
			scanf("%lf %lf", &c, &rd);
			ll x = getll(c);
			ll rad = getll(rd);
			x = getrealpos(x);
			
			ll l = x - rad;
			ll r = x + rad;

			insert(new Treap(l, id, 1));
			insert(new Treap(r + 1, -id, -1));

			id++;
		}	else {
			double c;
			scanf("%lf", &c);
			ll x = getll(c);
			x = getrealpos(x);
	
			int ans = getcnt(root, x + 1);
			ll resp = getsum(root, x + 1);
			err("x = %lld ans = %d resp = %lld\n", x, ans, resp);
			sum = (sum + resp) % n;

			printf("%d\n", ans);
		}
	}	

//
	exit();
	return 0;
}



