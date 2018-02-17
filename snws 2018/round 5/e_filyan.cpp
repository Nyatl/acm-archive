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
#include <cstdarg>
#include <memory.h>
#include <assert.h>
#include <cstring>
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
typedef set<int> si;
typedef set<pii> spii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef set<pll> spll;

char __buffer[100000];

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void exit() {
	cerr << setprecision(6) << fixed << "TIME: " << (double)clock() / CLOCKS_PER_SEC << endl;
	exit(0);
}

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

template<typename T1, typename T2>
ostream& operator<<(ostream& s, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		cerr << "\t" << z.first << " -> " << z.second << endl;
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define dbg1(x, n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;
#define ass(x) if (!(x)) { cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0); }
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#define ass(x) assert(x)
#endif
        
int const N = 2e5 + 41;
int const K = 26;
char s[N];
int lst, cur, q;
int n;
char c;

struct State {
	int len;
	int nxt[K];
	int link;
	State() {
		memset(nxt, 0, sizeof(nxt));
		len = 0;
		link = -1;
	};		
};

ostream& operator<<(ostream& s, State st) {
	dbg(st.len);
	dbg(st.link);
	dbg0(st.nxt, K);
	return s;
}

State st[N];

int getnode() {	
	q++;
	st[q] = State();
	return q;
}

int getnode(int x) {
	q++;
	st[q].len = st[x].len;
	st[q].link = st[x].link;
	cpy(st[q].nxt, st[x].nxt);
	return q;
}

void expand(int c) {
	int cur = getnode();
	st[cur].len = st[lst].len + 1;
	int x = lst;
	while(x != -1) {
		if (st[x].nxt[c]) {
			break;
		}
		st[x].nxt[c] = cur;
		x = st[x].link;										
	}
	if (x == -1) {
		st[cur].link = 0;
	} else {
		int y = st[x].nxt[c];
		if (st[x].len + 1 == st[y].len) {
			st[cur].link = y;
		} else {//go up
			int z = getnode(y);
			st[z].len = st[x].len + 1;
			st[cur].link = z;
			st[y].link = z;
			while (x != -1) {//go go up
				if (st[x].nxt[c] != y) {
					break;
				}
				st[x].nxt[c] = z;
				x = st[x].link;				
			}		            						  			
		}			
	}
	lst = cur;
}

ll d[N];

ll dfs(int x, bool f) {
	if(d[x] != -1) {
		return d[x];
	}
	ll res = (x ? 1 : 0);
	fi(0, K - 1) {
		int y = st[x].nxt[i];
		if (y){
			if(f || i + 'a' != c) {
				res += dfs(y, f);
			}
		}						
	}
	d[x] = res;
	return res;		
}

void solve() {
	q = -1;
	lst = getnode();
	n = strlen(s + 1);
	fi(1, n) {
		expand(s[i] - 'a');								
	}
//	dbg(c);
//	dbg(s + 1);
/*	fi(0, q) {
		dbg(st[i]);
	}*/
	fi(0, q) {
		d[i] = -1;
	}
	ll ans = dfs(0, 1);
	fi(0, q) {
		d[i] = -1;
	}
	ans -= dfs(0, 0);
//	cerr << ans << endl;
	
//	fi (0, q) cerr << "i = " << i << " " << d[i] << endl;
	printf("%lld\n",ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf(" %c", &c);
  	scanf(" %s", s + 1);
  	solve();
  }

	exit();
	return 0;
}
