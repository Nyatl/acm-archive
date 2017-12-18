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
#define all(x) (x).being(), (x).end()

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

#ifdef _DEBUG
#define LOCAL
#endif
 
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define ass(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x,n) while(0){}
#define dbg1(x,n) while(0){}
#define ass(x) assert(x)
#endif

char s[500];
char f[500];
 
ll Abs(ll x) {
	return x < 0 ? -x : x;
}

struct Point {
	ll l;
	ll x;
	Point() {
		l = 0;
		x = 0;
	}
	Point (ll l, ll x) : l(l), x(x) {}
};

ll p3[40];

ll N(ll x, ll l) {
	return (x % p3[l] + p3[l]) % p3[l];
}

ll get_dir(ll x1, ll x2, ll l) {
	if (N(x1 - x2, l) < N(x2 - x1, l)) {
		return -1;
	} else {
		return 1;
	}
}

bool move(Point &p, char d) {
	if (d == 'c') {
		p.l++;
		p.x *= 3;
	} else if (d == 'g') {
		if (p.l == 0 || p.x % 3 != 0) return false;
		p.l--;
		p.x /= 3;
	} else if (d == 'a') {
		p.x++;
	} else if (d == 's') {
		p.x--;
	}
	p.x = N(p.x, p.l);
	return true;
}

void move(Point &p, char *str) {
	ll l = strlen(str);
	fi(0, l - 1) {
		move(p, str[i]);
	}
}

ll dist(ll x1, ll x2, ll l) {
	return min(Abs(x2 - x1), p3[l] - Abs(x2 - x1));
}

ll ansv;
ll ansl;
ll ansd1;
ll ansd2;

void try_move(Point a, Point b, ll lev, ll dir1, ll dir2) {
	ll res = 0;
	while (a.l - lev > 0) {
		if (a.x % 3 == 1) {
			move(a, 's'), res++;
		}
		if (a.x % 3 == 2) {
			move(a, 'a'), res++;
		}
		move(a, 'g'), res++;
	}
	while (b.l - lev > 0) {
		if (b.x % 3 == 1) {
			move(b, 's'), res++;
		}
		if (b.x % 3 == 2) {
			move(b, 'a'), res++;
		}
		move(b, 'g'), res++;
	}

	res += dist(a.x, b.x, lev);
	if (res < ansv) {
		ansv = res;
		ansl = lev;
		ansd1 = dir1;
		ansd2 = dir2;
	}
}

string ans1;
string ans2;
string ans;

void print(Point a, Point b) {
	while (a.l - ansl > 0) {
		if (a.x % 3 == 1) {
			move(a, 's'), ans1 += 's';
		}
		if (a.x % 3 == 2) {
			move(a, 'a'), ans1 += 'a';
		}
		move(a, 'g'), ans1 += 'g';
	}
	while (b.l - ansl > 0) {
		if (b.x % 3 == 1) {
			move(b, 's'), ans2 = 'a' + ans2;
		}
		if (b.x % 3 == 2) {
			move(b, 'a'), ans2 = 's' + ans2;
		}
		move(b, 'g'), ans2 = 'c' + ans2;
	}
	
	dbg(a.x);
	dbg(b.x);
	if (Abs(a.x - b.x) < p3[ansl] - Abs(a.x - b.x)) {
		dbg("Case 1");
		if (a.x < b.x) {
			while (a.x != b.x) {
				move(a, 'a');
				ans1 += 'a';
			}
		} else {
			while (a.x != b.x) {
				move(a, 's');
				ans1 += 's';
			}
		}
	} else {
		dbg("Case 2");
		if (a.x < b.x) {
			while (a.x != b.x) {
				move(a, 's');
				ans1 += 's';
			}
		} else {
			while (a.x != b.x) {
				move(a, 'a');
				ans1 += 'a';
			}
		}
	}
	ans = ans1 + ans2;
	printf("%s\n", ans.c_str());
}

void solve() {
	Point a;
	Point b;
	ansv = 1000000000000LL;
	move(a, s);
	move(b, f);
	fi(0, min(a.l, b.l)) {
		try_move(a, b, i, 0, 0);
		try_move(a, b, i, 1, 0);
		try_move(a, b, i, 0, 1);
		try_move(a, b, i, 1, 1);
	}
	
	dbg(ansv);
	dbg(ansl);
	dbg(ansd1);
	dbg(ansd2);
	print(a, b);
}

void init() {
	p3[0] = 1;
	fi(1, 39) {
		p3[i] = p3[i - 1] * 3;
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%s", s);
    scanf("%s", f);
    init();
    solve();
    r