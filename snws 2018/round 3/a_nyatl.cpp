#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <assert.h>

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
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

template<typename A, typename B>
ostream& operator<<(ostream& s, pair<A, B> p) {
	cerr << "(" << p.first << ", " << p.second << ")";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> t) {
	for (auto z : t) {
		cerr << z << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define dbg1(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define ass(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#define ass(x) assert(x)
#endif

#define MAX 100100

int n;
int m;
ll a[MAX];

struct Query {
	int l, r, k, num;
	bool operator<(const Query &q) const {
		if (k != q.k) return k < q.k;
		if (l != q.l) return k < q.l;
		if (r != q.r) return k < q.r;
		return num < q.num;
	}
	Query() {}
	Query(int l, int r, int k, int num): l(l), r(r), k(k), num(num) {}
};

Query query[MAX];

ostream& operator<<(ostream& s, Query q) {
	cerr << "(" << q.l << ", " << q.r << ", " << q.k << ", " << q.num << ")";
	return s;
}


ll st[4 * MAX];

void build(int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = a[tl];
		return;
	}
	int h = (tl + tr) / 2;
	build(tl, h, 2 * x);
	build(h + 1, tr, 2 * x + 1);
	st[x] = st[2 * x] + st[2 * x + 1]; 
}

ll get_sum(int l, int r, int tl = 1, int tr = n, int x = 1) {
	if (l == tl && r == tr) {
		return st[x];
	}
	int h = (tl + tr) / 2;
	if (r <= h) {
		return get_sum(l, r, tl, h, 2 * x);
	} else if (l >= h + 1) {
		return get_sum(l, r, h + 1, tr, 2 * x + 1);
	} else {
		return get_sum(l, h, tl, h, 2 * x) + get_sum(h + 1, r, h + 1, tr, 2 * x + 1); 
	}
}

void update(int p, int v, int tl = 1, int tr = n, int x = 1) {
	if (tl == tr) {
		st[x] = v;
		return;
	}
	int h = (tl + tr) / 2;
	if (p <= h) {
		update(p, v, tl, h, 2 * x);
	} else {
		update(p, v, h + 1, tr, 2 * x + 1);
	}
	st[x] = st[2 * x] + st[2 * x + 1];
}

ll ans[MAX];

set<pair<int, int> > t;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &m);
	fi(1, m) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		query[i] = Query(l, r, k, i);
	}
	sort(query + 1, query + m + 1);

	build();
	
	fi(1, n) {
		t.insert(mp(-a[i], i));
	}
		
	int cur = 1;
	
	fi(0, 33 * n) {
		while (cur <= m && query[cur].k == i) {
			ll sum = get_sum(query[cur].l, query[cur].r);
			ans[query[cur].num] = sum;
			cur++; 
		}
		int x = t.begin()->second;
		t.erase(mp(-a[x], x));
		if (a[x] == 0) break;
		a[x] /= 2;
		update(x, a[x]);
		t.insert(mp(-a[x], x));
	}
	
	fi(1, m) {
		printf("%lld\n", ans[i]);
	}
	
	return 0;
}
