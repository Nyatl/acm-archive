#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef _DEBUG
#define LOCAL
#endif

#define fi(a, b) for (int i=a; i<=b; i++)
#define fj(a, b) for (int j=a; j<=b; j++)
#define fo(a, b) for (int o=a; o<=b; o++)
#define fdi(a, b) for (int i=a; i>=b; i--)
#define fdj(a, b) for (int j=a; j>=b; j--)
#define fdo(a, b) for (int o=a; o>=b; o--)
#define cpy(a, b) memcpy(a, b, sizeof(b))
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
typedef pair<int,int> pii;

template<class T>
ostream& operator <<(ostream &s, vector<T> &v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

template<class T>
ostream& operator <<(ostream &s, set<T> &v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cerr << *it << " ";
	}
	return s;
}

template<class A, class B>
ostream& operator <<(ostream &s, pair<A, B> &p) {	
	cerr << "(" << p.first << ", " << p.second << ")";	
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x,n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl
#define dbg1(x,n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl
#else
#define dbg(x) while(0) {}
#define dbg0(x,n) while(0) {}
#define dbg1(x,n) while(0) {}
#endif

const int MAX = 100 * 1000 + 41;

int n, m;
ll t[4 * MAX];
ll a[MAX];
ll ans[MAX];
vector<pair<pair<ll, ll>, pii>> q;


void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

ll sum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum(v*2, tl, tm, l, min(r ,tm))
		+ sum(v*2+1, tm+1, tr, max(l ,tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

ll sum(int l, int r) {
	return sum(1, 1, n, l, r);
}

ll update(int x) {
	ll v = sum(x, x);
	v /= 2;
	update(1, 1, n, x, v);
	return v;
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r" ,stdin);
	freopen("output.txt", "w" ,stdout);
#endif

	fi(0, MAX - 1) ans[i] = -1;

	scanf("%d", &n);
	fi(1, n) {
		int t;
		scanf("%d", &t);
		a[i] = t;
	}
	
	scanf("%d", &m);
	fi(1, m) {
		int l, r;
		ll k;
		scanf("%d%d%lld", &l, &r, &k);
		q.pb(mp(mp(k, i * 1LL), mp(l, r)));
	}
	
	sort(q.begin(), q.end());
	
	build(1, 1, n);
	
	
	set<pii> s;
	fi(1, n) {
		s.insert(mp(-a[i], i));
	}
	int cur = 0;
	for (auto z : q) {
		ll k = z.first.first;
		if (k > MAX * 40) {
			ans[z.first.second] = 0;
			continue;
		}
		while (cur < k) {
			auto it = s.begin();
			int x = (*it).second;
			int v2 = update(x);
			s.erase(it);
			s.insert(mp(-v2, x));
			cur++;
		}
		ans[z.first.second] = sum(z.second.first, z.second.second);
	}
	fi(1, m) printf("%lld\n", ans[i]);

	return 0;
}
