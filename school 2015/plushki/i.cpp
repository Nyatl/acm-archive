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
ll const INF = 1e9 + 41;

int n, p;
int c[N];

pii ansv, ans;
multiset<pii> t;

ll getf(int idp, int idq) {
	if (idp == -1 || idq == -1) return INF;
	ll a = c[idp];
	ll b = p * 1LL * c[idq];
	return abs(a - b);
}

pii getbest(int cid) {
	int c = ::c[cid];
	int v = (c + p - 1) / p;
	multiset<pii> ::iterator it = t.lower_bound(mp(v, -1));
	int id = -1;

	if (it != t.end()) {
		int id1 = (*it).second;
		if (getf(cid, id1) * ::c[id] < getf(cid, id) * ::c[id1]) {
			id = id1;
		}
	}

	if (it != t.begin()) {
		--it;
		if (it != t.end()) {
			int id1 = (*it).second;
			if (getf(cid, id1) * ::c[id] < getf(cid, id) * ::c[id1]) {
				id = id1;
			}
		}
	}

	return mp(cid, id);
}

bool le(pii a, pii b) {
	return getf(a.first, a.second) * ::c[b.second] < getf(b.first, b.second) * ::c[a.second];
}

void solve() {
	ans = mp(-1, -1);
	fi(0, n) t.insert(mp(c[i], i));
	fi(0, n) {
		multiset<pii> ::iterator it = t.find(mp(c[i], i));
		t.erase(it);

		pii cur = getbest(i);

		if (le(cur, ans)) {
			ans = cur;
		}

		t.insert(mp(c[i], i));
	}
}

#define FILENAME "prices"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif
	scanf("%d %d", &n,&p);
	fi(0, n) scanf("%d", &c[i]);
	solve();
	
	printf("%d %d\n", ans.first + 1, ans.second + 1);

	return 0;
}