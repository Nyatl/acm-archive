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
int const INF = 2e9 + 41;
ll const LINF = 2e18 + 41;

struct P {
	ll x, y;
	P() {};
	P(ll x, ll y) : x(x), y(y) {};
};

ll x[N], y[N], n, T;
P p[N];

int m;
string ans;
ll mini[N], maxi[N];

ll getprog(ll st, ll en, ll n) {
	ll ret = (st + en) * n / 2;
	return ret;
}

bool can(P p1, P p2) {
	if (p1.x > p2.x) return false;
	ll d = p2.x - p1.x;
	ll maxy = p1.y + d;
	ll miny = p1.y - d;
	return (miny <= p2.y && p2.y <= maxy);
}

ll getmin(P p1, P p2) {
	assert(can(p1, p2));
	ll l = -1;
	ll r = p1.y + 1;
	while (r - l > 1) {
		ll h = (l + r) / 2;
		P np = P(p1.x + h, p1.y - h);
		if (can(np, p2)) l = h;
		else r = h;
	}
	assert(l != -1);
	P np = P(p1.x + l, p1.y - l);
	ll res = getprog(p1.y, np.y, l + 1) - p1.y;
	P npr = P(np.x + 1, np.y);
	if (can(npr, p2)) {
		res += np.y;
		++np.x;
	}
	ll diag = getprog(np.y + 1, p2.y, p2.x - np.x);
	res += diag;
	return res;
}

ll getmax(P p1, P p2) {
	assert(can(p1, p2));
	ll l = -1;
	ll r = p1.y + 1;
	while (r - l > 1) {
		ll h = (l + r) / 2;
		P np = P(p1.x + h, p1.y + h);
		if (can(np, p2)) l = h;
		else r = h;
	}
	assert(l != -1);
	P np = P(p1.x + l, p1.y + l);
	ll res = getprog(p1.y, np.y, l + 1) - p1.y;
	P npr = P(np.x + 1, np.y);
	if (can(npr, p2)) {
		res += np.y;
		++np.x;
	}
	ll diag = getprog(np.y - 1, p2.y, p2.x - np.x);
	res += diag;
	return res;
}

void bad() {
	printf("No\n");
	exit(0);
}

void solve() {
	/*fi(1, 5) fj(0, 5) {
		P p1 = P(0, 2);
		P p2 = P(i, j);
		printf("%d %d", i, j);
		if (can(p1, p2)) {
			ll maxi = getmax(p1, p2);
			ll mini = getmin(p1, p2);
			printf(" mini = %lld maxi = %lld\n", mini,maxi);
		} else {
			printf(" no\n");
		}
	}*/
	fi(0, m-1) {
		if (!can(p[i], p[i+1])) bad();
		mini[i + 1] = mini[i] + getmin(p[i], p[i + 1]);
		maxi[i + 1] = maxi[i] + getmax(p[i], p[i + 1]);
	}
	
	ll cntlmin = min(p[0].x, p[0].y);
	mini[m - 1] += getprog(p[0].y, p[0].y - cntlmin + 1, cntlmin);
	ll cntlmax = p[0].x;
	maxi[m - 1] += getprog(p[0].y, p[0].y + cntlmax - 1, cntlmax);

	ll cntrmin = min(n - p[m-1].x, p[m - 1].y);
	mini[m - 1] += getprog(p[m - 1].y-1, p[m - 1].y - cntrmin, cntrmin);
	ll cntrmax = n - p[m - 1].x;
	maxi[m - 1] += getprog(p[m - 1].y+1, p[m - 1].y + cntrmax, cntrmax);

	//fi(0, m) {
	//	printf("%lld %lld\n", mini[i], maxi[i]);
	//}

	if (mini[m - 1] <= T && T <= maxi[m - 1]) {
		
	} else {
		bad();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%lld %lld %d", &T, &n, &m);
	fi(0, m) scanf("%lld %lld", &p[i].x, &p[i].y);

	solve();

	printf("Yes\n");

	return 0;
}