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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fy(a) for(auto &y : a)
#define fz(a) for(auto &z : a)
#define fdi(a, b) for(auto i=a; i>=b; i--)
#define fdj(a, b) for(auto j=a; j>=b; j--)
#define fdo(a, b) for(auto o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

#ifdef LOCAL
void err(const char *format, ... ) {
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
}
#else
#define err(...) {}
#endif

#ifdef LOCAL
void errln(const char *format, ... ) {
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
}
#else
#define errln(...) {}
#endif

#ifdef LOCAL
void errln() {
	fprintf(stderr, "\n");
}
#endif

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#else
#define dbg(x) {}
#define dbg0(x, n) {}
#define dbg1(x, n) {}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

#define MAX 500100

int n, k;

vi e[MAX];
int nxt[MAX];

int a[MAX];

int N[MAX];
int *MDF[MAX];

int *mdf;

int get_sum(int p, int tl, int tr, int x) {
    if (tl == tr) {
        return mdf[x];
    }
    int h = (tl + tr) / 2;
    if (p <= h) {
        return get_sum(p, tl, h, 2 * x) + mdf[x];
    } else {
        return get_sum(p, h + 1, tr, 2 * x + 1) + mdf[x];
    }
}

void update(int l, int r, int v, int tl, int tr, int x) {
    if (l == tl && r == tr) {
        mdf[x] += v;
        return;
    }
    int h = (tl + tr) / 2;    
    if (r <= h) {
        update(l, r, v, tl, h, 2 * x);
    } else if (l >= h + 1) {
        update(l, r, v, h + 1, tr, 2 * x + 1);
    } else {
        update(l, h, v, tl, h, 2 * x);
        update(h + 1, r, v, h + 1, tr, 2 * x + 1);
    }            
}

int get_sum(int num, int p) {
	mdf = MDF[num];
	return get_sum(p, 1, N[num], 1);
}

void update(int num, int l, int r) {
	if (r - l + 1 > N[num]) {
		update(num, 1, N[num]);
		return;
	}
	if (r - l + 1 == N[num]) {
		l = 1;
		r = N[num];
	}
	if (r > N[num]) {
		r -= N[num];
	}
	if (l > r) {
		update(num, l, N[num]);
		update(num, 1, r);
		return;
	}
	mdf = MDF[num];	
	errln("%d %d", l, r);	
	update(l, r, 1, 1, N[num], 1);
}

int num[MAX];
int cycle[MAX];
int pos[MAX];
int tq;
int h[MAX];
int h_max[MAX];
int cq;
int cycle_num[MAX];
int to_num[MAX];
int to_pos[MAX];
int cycle_len[MAX];

int fun(int x) {
	if (h[x] != -1) return h[x];
	if (cycle[nxt[x]]) {
		return h[x] = 0;
	}
	int res = fun(nxt[x]) + 1;
	h_max[num[x]] = max(h_max[num[x]], res);
	return h[x] = res;
}

int fun2(int x) {
	if (to_num[x] != -1) return to_num[x];
	if (cycle[nxt[x]]) {
		return to_num[x] = cycle_num[nxt[x]];		
	}
	int res = fun2(nxt[x]);
	return to_num[x] = res;
}

int fun3(int x) {
	if (to_pos[x] != -1) return to_pos[x];
	if (cycle[nxt[x]]) {
		return to_pos[x] = pos[nxt[x]];		
	}
	int res = fun3(nxt[x]);
	return to_pos[x] = res;
}

int ans[MAX];

set<pii>* dfs3(int x) {
	set<pii>* s;
	vector<set<pii>*> v;
	fy(e[x]) {
		v.pb(dfs3(y));
	}
	sort(all(v), [](auto s1, auto s2) {
		return sz(*s1) > sz(*s2);
	});
	if (!sz(v)) {
		s = new set<pii>();
		s->insert(mp(h[x], x));
		ans[x]++;
		return s;
	} else {
		s = v[0];
	}
	s->insert(mp(h[x], x));
	fi(1, sz(v) - 1) {
		fz(*v[i]) {
			s->insert(z);
		}
	}
	while (s->rbegin()->first - h[x] > k) {
		s->erase(*(s->rbegin()));
	}
	ans[x] += sz(*s);
	return s;
}

void solve() {
	memset(h, -1, sizeof(h));
	memset(to_pos, -1, sizeof(to_pos));
	memset(to_num, -1, sizeof(to_num));
	fi(1, n) {
		if (cycle[i]) continue;
		fun(i);
		fun2(i);
		fun3(i);
	}
	
	dbg1(h, n);
	dbg1(to_num, n);
	dbg1(to_pos, n);
	
	fi(1, n) {
		if (cycle[i]) continue;
		if (h[i] == 0) {
			errln("dfs3 %d", i);
			dfs3(i);
		}
	}	
	
	errln("dfs3 done");
	
	fi(1, n) {
		if (!cycle[i]) continue;
		ans[i] += min(k + 1, cycle_len[cycle_num[i]]);
	}
	
	fi(1, cq) {
		N[i] = cycle_len[i];
		MDF[i] = new int[4 * N[i]];
		memset(MDF[i], 0, sizeof(int) * 4 * N[i]);
	}

	dbg1(ans, n);
	
	fi(1, n) {
		if (cycle[i]) continue;
		if (h[i] >= k) continue;
		errln("+1 %d: %d %d %d", i, to_num[i], to_pos[i], to_pos[i] + k - h[i] - 1);
		update(to_num[i], to_pos[i], to_pos[i] + k - h[i] - 1);
	}
	
	fi(1, n) {
		if (!cycle[i]) continue;
		ans[i] += get_sum(cycle_num[i], pos[i]);
	}
}

int color[MAX];

void dfs(int x) {
	if (color[x]) return;
	color[x] = 2;
	if (color[nxt[x]] == 2) {
		int y = x;
		int c = 0;
		cycle[y] = 1;
		pos[y] = c;
		cq++;
		cycle_num[x] = cq;
		int len = 1;		
		dbg(x);	
		while (1) {
			c++;
			pos[y] = c;			
			y = nxt[y];		
			if (y == x) break;
			len++;
			cycle[y] = 1;
			cycle_num[y] = cq;
		}
		cycle_len[cq] = len;
	} else {
		dfs(nxt[x]);
	}
	color[x] = 1;
}


void dfs2(int x) {
	if (color[x]) return;
	if (cycle[x]) return;
	color[x] = 1;
	num[x] = tq;
	fy(e[x]) {
		dfs2(y);
	}
	dfs2(nxt[x]);
}

void init() {
	fi(1, n) {
		if (color[i]) continue;
		dfs(i);
	}
	clr(color);

	errln("dfs done");
	
	fi(1, n) {
		if (color[i]) continue;
		if (cycle[i]) continue;
		tq++;
		dfs2(tq);
	}
	
	dbg1(cycle, n);
	dbg(cq);
	dbg1(cycle_len, cq);
	dbg1(pos, n);		
	dbg1(cycle_num, n);	
	dbg(tq);
	dbg1(num, n);		
	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %d", &n, &k);
	
	fi(1, n) {
		int x;
		scanf("%d", &x);
		nxt[i] = x;
		e[x].pb(i);
	}

	init();

	solve();

	fi(1, n) {
		printf("%d\n", ans[i]);
	}	
	
	exit();
	return 0;
}
