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
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fo(a, b) for(int o=a; o<b; o++)
#define fdi(a, b) for(int i=a-1; i>=b; i--)
#define fdj(a, b) for(int j=a-1; j>=b; j--)
#define fdo(a, b) for(int o=a-1; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef set<pii> spii;

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

#define MAX 30

int n;
int p[MAX];

#define INF 1000000000

struct Rec {
	int l;
	vi v;
	Rec(int l, vi v): l(l), v(v) {};
	Rec() {};
};

vector<Rec> r[MAX];

int d[(1 << 21)];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fi(0, n) {
		scanf("%d", &p[i]);
		fj(0, p[i]) {
			int l;
			scanf("%d", &l);
			vi v;
			int q;
			scanf("%d", &q);
			fo(0, q) {
				int x;
				scanf("%d", &x);
				v.pb(x);
			}
			r[i].pb(Rec(l, v));
		}
	}

	int ans = INF;

	fi(0, (1 << n)) {
		d[i] = INF;
	}
	
	d[0] = 0;

	fi(0, (1 << n)) {
		if (d[i] == INF) continue;
		if (i & 1) ans = min(ans, d[i]);
		fj(0, n) {
			if ((1 << j) & i) continue;
			fo(0, sz(r[j])) {
				int f = 1;
				for (int u = 0; u < sz(r[j][o].v); u++) {
					if (!((1 << r[j][o].v[u]) & i)) {
						f = 0;
						break;
					}
				}
				if (f) {
					d[i | (1 << j)] = min(d[i | (1 << j)], d[i] + r[j][o].l);
				}
			}
		}
	}	
	
	if (ans == INF) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
