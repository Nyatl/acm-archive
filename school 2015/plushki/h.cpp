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
set<int> t[N];
int a[N];
int n, m;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

vii ch;
int f[N];
int sum;

int getsum() {
	set<pii> t;
	fi(0, sz(ch)) {
		fj(1, sz(ch[i])) {
			t.insert(mp(ch[i][j - 1], ch[i][j]));
		}
	}
	return sz(t);
}

void solve() {
	fi(1, m+1) {
		if (i == 1 || a[i] == a[1]) {
			vi nc;
			nc.pb(a[i]);
			ch.pb(nc);
		} else {
			ch.back().pb(a[i]);
		}
	}
	/*fi(0, sz(ch)) {
		fj(0, sz(ch[i])) {
			printf("%d ", ch[i][j]);
		}
		printf("\n");
	}*/

	sum = getsum();
	fi(0, sz(ch)) {
		fj(1, sz(ch[i])) {
			int cur = ch[i][j];
			int bef = ch[i][j-1];
			t[cur].insert(bef);
		}
	}

	int id1 = a[1];
	int id2 = -1;
	fi(1, n + 1) {
		if (i == id1) {
			continue;
		}
		if (id2 == -1 || sz(t[i]) > sz(t[id2])) {
			id2 = i;
		}
	}
	
	set<pii> pt;
	fi(0, sz(ch)) {
		fj(1, sz(ch[i])) {
			int cur = ch[i][j];
			int bef = ch[i][j - 1];
			if (cur == id1 || cur == id2) continue;
			pt.insert(mp(bef, cur));
		}
	}

	int sum = getsum();
	int pans = sum - sz(t[id1]) - sz(t[id2]);
	assert(sz(pt) == pans);
	printf("%d\n", pans);
	for (auto it : pt) {
		printf("%d %d\n", it.second, it.first);
	}
}

#define FILENAME "log"

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	fi(1, m+1) scanf("%d", &a[i]);
	solve();

	return 0;
}