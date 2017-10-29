#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

int const N = 1e5 + 41;
ll const INF = 1e18 + 41;

int n;
ll c[N], f[N], d[N], g[N], e[N];
ll suf[N];

struct Node {
	ll mini, maxi, cnt;
	int pos, rpos;
	Node() {};
	Node(ll mini, ll maxi, ll cnt, int pos, int rpos) :
		mini(mini), maxi(maxi), cnt(cnt), pos(pos), rpos(rpos) {};
	bool operator<(const Node &a) const {
		return mini < a.mini;
	};
};

Node a[N], b[N];

Node EMP = Node(INF, -INF, 0, -1, -1);

Node t[N * 4];

Node getmax(int v, int tl, int tr) {
	if (tl == tr) {
		return t[v];
	} else {
		int tm = (tl + tr) / 2;
		if (t[v * 2 + 1].maxi >= t[v * 2 + 2].maxi) return getmax(v * 2 + 1, tl, tm);
		else return getmax(v * 2 + 2, tm + 1, tr);
	}
}

Node getmin(int v, int tl, int tr) {
	if (tl == tr) {
		return t[v];
	} else {
		int tm = (tl + tr) / 2;
		if (t[v * 2 + 1].mini <= t[v * 2 + 2].mini) return getmin(v * 2 + 1, tl, tm);
		else return getmin(v * 2 + 2, tm + 1, tr);
	}
}

Node getmax() {
	return getmax(0, 0, n - 1);
}

Node getmin() {
	return getmin(0, 0, n - 1);
}

void refresh(int v) {
	t[v].mini = min(t[v * 2 + 1].mini, t[v * 2 + 2].mini);
	t[v].maxi = max(t[v * 2 + 1].maxi, t[v * 2 + 2].maxi);
	t[v].cnt = t[v * 2 + 1].cnt + t[v * 2 + 2].cnt;
}

void remove(int v, int tl, int tr, int p) {
	if (tl == tr) {
		t[v] = EMP;
	} else {
		int tm = (tl + tr) / 2;
		if (p <= tm) remove(v * 2 + 1, tl, tm, p);
		else remove(v * 2 + 2, tm + 1, tr, p);
		refresh(v);
	}
}

void remove(int p) {
	remove(0, 0, n - 1, p);
}

void bad() {
	printf("-1\n");
	exit(0);
}

ll ans;

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = EMP;
	} else {
		int tm = (tl + tr) / 2;
		build(v * 2 + 1, tl, tm);
		build(v * 2 + 2, tm + 1, tr);
		refresh(v);
	}
}

void upd(int v, int tl, int tr, Node val) {
	if (tl == tr) {
		t[v] = val;
	} else {
		int tm = (tl + tr) / 2;
		if (val.pos <= tm) upd(v * 2 + 1, tl, tm, val);
		else upd(v * 2 + 2, tm + 1, tr, val);
		refresh(v);
	}
}

void upd(Node val) {
	upd(0, 0, n - 1, val);
}

void solve() {
	fdi(n, 0) {
		suf[i] = e[i];
		if (i + 1 < n) suf[i] += suf[i + 1];
	}
	fi(0, n) {
		a[i] = Node(f[i] + suf[i], f[i] + suf[i], c[i], -1, i);
	}
	sort(a, a + n);	
	fi(0, n) a[i].pos = i;
	fi(0, n) b[a[i].rpos] = a[i];
	build(0, 0, n - 1);
	fi(0, n) {
		//upd
		upd(0, 0, n - 1, b[i]);
		//answer
		ll rem = d[i];
		while (rem > 0) {
			Node mini = getmin();
			if (mini.cnt == 0) bad();
			ll c = min(mini.cnt, rem);
			ans += (mini.mini - suf[i]) * c;
			mini.cnt -= c;
			rem -= c;
			if (mini.cnt > 0) {
				upd(mini);
			} else {
				remove(mini.pos);
			}
		}
		//reduce
		while (t[0].cnt > g[i]) {
			Node maxi = getmax();
			if (t[0].cnt - maxi.cnt >= g[i]) {
				remove(maxi.pos);
			} else {
				maxi.cnt -= (t[0].cnt - g[i]);
				upd(maxi);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	fi(0, n) {
		scanf("%lld %lld %lld", &c[i], &f[i], &d[i]);
	}
	fi(0, n - 1) {
		scanf("%lld %lld", &g[i], &e[i]);
	}
	solve();

	printf("%lld\n", ans);

	return 0;
}