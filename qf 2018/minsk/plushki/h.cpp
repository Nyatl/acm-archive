#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++) 
#define fj(a, b) for (int j = a; j <= b; j++) 
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--) 
#define fdj(a, b) for (int j = a; j >= b; j--) 
#define fdo(a, b) for (int o = a; o >= b; o--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<typename A, typename B>
ostream& operator<<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")" << endl;
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}
/*
template<typename A, typename B>
ostream& operator<<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}*/

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": " << x << endl; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": " << x << endl; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define err(...) while (0) {}
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif 

//////////////////////

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif

const int MAX = 205;

struct Edge {
	int u, v;
	int b, c;
	int num;
	Edge() {}
	Edge(int u, int v, int b, int c, int num) : u(u), v(v), b(b), c(c), num(num) {}
	ll wcut(ll x) {
		return x * b + c;
	}
};

int n, m;
Edge edges[MAX];
int T;

lll sum2[1000005];

//mst

int par[MAX];

void build() {
	fi(1, n) {
		par[i] = i;
	}
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	par[b] = a;
	return true;
}

ll TIME;

bool cmp(Edge &a, Edge &b) {
	return a.wcut(TIME) < b.wcut(TIME);
}

vi mst(ll t) {
	TIME = t;
	build();
	vector<Edge> ve;
	fi(1, m) {
		ve.pb(edges[i]);
	}
	sort(ve.begin(), ve.end(), cmp);
	vi res;
	ll ans = 0;
	for (auto z : ve) {
		if (uni(z.u, z.v)) {
			res.pb(z.num);
			ans += z.wcut(TIME);
		}
	}
	//err("MST W = %lld\n", ans);
	return res;
}

//mst end

lll getSum(ll x1, ll x2, const vector<int> &v) {
	if (x1 > x2) return 0;
	x1--;
	lll res = 0;
	lll bsum = 0;
	lll csum = 0;
//	dbg(v);
	for (int z : v) {
		bsum += edges[z].b;
		csum += edges[z].c;
	}
	if (x1 == -1) {
		res += (sum2[x2] - sum2[0]) * sz(v);
	} else {
		res += (sum2[x2] - sum2[x1]) * sz(v);
	}
	res += bsum * ((x2 * (x2 + 1) / 2) - (x1 * (x1 + 1) / 2));
	res += (x2 - x1) * csum;
	return res;
}

void print(lll C) {
		if (C == 0) {
			printf("0\n");
			return;
		}
		string s;
		bool f = false;
		if (C < 0) {
			f = true;
			C = -C;
		}
		while (C) {
			s += (char)('0' + (C % 10));
			C /= 10;
		}
		reverse(all(s));
		if (f) {
			s = "-" + s;
		}
		printf("%s", s.c_str());
}

set<int> t;

void add(int C, int B) {
	if (B == 0) return;
	if (B < 0) {
		B = -B;
		C = -C;
	}
	if (C < 0) return;
	int x = C / B;
	if (x > T) {
		return;
	}
	if (C % B == 0) {
		t.insert(x);
		if (x + 1 < T) {
			t.insert(x + 1);
		}
		if (x) {
			t.insert(x - 1);
		}
	} else {
		t.insert(x);
		if (x + 1 < T) {
			t.insert(x + 1);
		}
	}
}

void solve() {
	lll ans = 0;
	fi(1, m) {
		fj(i + 1, m) {
			add(edges[j].c - edges[i].c, edges[i].b - edges[j].b);
		}
	}
	t.insert(T);
	t.insert(T + 1);
	int last = 0;
	for (int z : t) {
		vi v = mst(last);
//		dbg(mp(last, z - 1));
		ans += getSum(last, z - 1, v);
		last = z;
	}
	/*fi(0, T) {
		vector<int> v = mst(i);
		ans += getSum(i, i, v);
		dbg(ans);
	}*/
	print(ans);
}

void init() {
	fi(1, 1000004) {
		sum2[i] = sum2[i - 1] + (lll)i * i;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	scanf("%d %d", &n, &m);
	fi(1, m) {
		int u, v, b, c;
		scanf("%d %d %d %d", &u, &v, &b, &c);
		edges[i] = Edge(u, v, b, c, i);
	}
	scanf("%d", &T);
	solve();
	return 0;
}
