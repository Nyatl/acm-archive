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

typedef long long ll;
typedef vector<int> vi;
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
#define as(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define as(x) assert(x)
#endif

#define MAX 100100

int n;
int p[MAX];
int pi[MAX];
vector<int> e[MAX];
vector<int> e2[MAX];

set<int> t;
int rem;
int cnt;
int deg[MAX];

void turn_on(int x) {
	rem--;	
	fi(0, sz(e2[x]) - 1) {
		int y = e2[x][i]; 		
		deg[y]--;
		if (deg[y] == 0) {
			t.insert(pi[y]);
		}
	}
	t.erase(pi[x]);
}

int cur;

void step() {
	turn_on(p[cur]);
	auto it = t.lower_bound(cur + 1);
	if (it == t.end()) {
		it = t.lower_bound(1);
		cnt++;
	}
	if (it == t.end()) return;
	cur = *it;
}

void solve() {
	rem = n;
	if (sz(t) == 0) {
		printf("-1\n");
		return;
	}
	cur = *t.lower_bound(1);
	while (sz(t)) {
		//dbg(cur);
		step();
		//dbg(t);		
	}
	if (rem > 0) {
		printf("-1\n");
		return;
	}	
	printf("%d\n", cnt);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &p[i]);
	}
	fi(1, n) {
		pi[p[i]] = i;
	}
	fi(1, n) {
		int q;
		scanf("%d", &q);
		fj(1, q) {
			int x;
			scanf("%d", &x);
			e[i].pb(x);
			e2[x].pb(i);
			deg[i]++;
		}
	}
	fi(1, n) {
		if (sz(e[i]) == 0) {
			t.insert(pi[i]);
		}
	}
	dbg(t);
	solve();
	return 0;
}
