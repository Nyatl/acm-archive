#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;

#define N 400000

ll fen[N];

ll a[N];

int n, nn;

ll sum(int x) {
	ll ret = 0;
	for (; x >= 0; x = (x&(x + 1)) - 1) {
		ret += fen[x];
	}
	return ret;
}

ll sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

void inc(int x, ll d) {
	for (; x < nn; x = (x|(x + 1))) {
		fen[x] += d;
	}
}

void init() {
	fi(1, n) {
		inc(i, a[i]);
	}
}

struct Event {
	int l, r;
	ll k;
	ll ans;
	int num;
	Event(){}
	Event(int l, int r, ll k, int num) : l(l), r(r), k(k), num(num) {}
};

int m;

bool comp1(const Event & e1, const Event & e2) {
	if (e1.k != e2.k) {
		return e1.k < e2.k;
	}
	return e1.num < e2.num;
}

bool comp2(const Event & e1, const Event & e2) {
	return e1.num < e2.num;
}

vector<int> ps;

void calcPs() {
	set<pair<int, int> > q;
	fi(1, n) {
		if (a[i]) {
			q.insert({-a[i], i});
		}
	}
	while (sz(q)) {
		auto p = *(q.begin());
		q.erase(q.begin());
		ps.pb(p.second);
		p.first /= 2;
		if (p.first) {
			q.insert(p);
		}
	}
}

vector<Event> es;

void solve() {
	scanf("%d", &n);
	nn = n + 1;
	fi(1, n) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &m);
	fi(0, m - 1) {
		int l, r;
		ll k;
		scanf("%d%d%lld", &l, &r, &k);
		es.pb({l, r, k, i});
	}
	init();
	sort(all(es), comp1);
	calcPs();
	int p = 0;
	fi(0, sz(ps) - 1) {
		while (p < sz(es) && es[p].k <= i) {
			es[p].ans = sum(es[p].l, es[p].r);
			p++;
		}
		int d = a[ps[i]];
		a[ps[i]] /= 2;
		d -= a[ps[i]];
		inc(ps[i], -d);
	}
	while (p < sz(es)) {
		es[p].ans = 0;
		++p;
	}
	sort(all(es), comp2);
	fi(0, m - 1) {
		printf("%lld\n", es[i].ans);
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	solve();
	
	return 0;
}