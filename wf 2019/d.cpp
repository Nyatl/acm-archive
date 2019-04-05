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
#define sz(x) (int)x.size()
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

#define INF 1000000000

struct Node {
	int x;
	int val;	
};

struct Queue {
	int mdf;
	vector<Node> v1;
	vector<Node> v2;
	void add(int x) {
//		errln("add %d", x);
		Node t;
		x -= mdf;
		t.x = x;
		if (sz(v1)) {
			t.val = min(x, v1.back().val);
		} else {
			t.val = x;
		}		
		v1.pb(t);		
	}
	void del() {
//		errln("del");
		if (sz(v2)) {
			v2.pop_back();
		} else {
			while (sz(v1)) {
				int val;
				if (sz(v2)) {
					val = min(v1.back().x, v2.back().val);
				} else {
					val = v1.back().x;
				}
				v2.pb(v1.back());
				v2.back().val = val;
				v1.pop_back();
			}
			v2.pop_back();
		}
	}
	int get_min() {		
		if (sz(v1) && sz(v2)) {
			return min(v1.back().val, v2.back().val) + mdf;
		}
		if (sz(v1)) {
			return v1.back().val + mdf;
		}
		if (sz(v2)) {
			return v2.back().val + mdf;
		}
		return INF;
	}
	void modify(int x) {
//		errln("modify %d", x);
		mdf += x;
	}
	void print() {
		fdi(sz(v1) - 1, 0) {
			err("%d (%d) ", v1[i].x + mdf, v1[i].val + mdf);
		}
		err(" | ");
		fi(0, sz(v2) - 1) {
			err("%d ", v2[i].x + mdf);
		}
		errln();
	}
};

const int MAX = 1000005;

int sgn(char t) {
	return (t == 'e') ? -1 : 1;
}

int n;
int a[MAX];
char type[MAX];
int bal[MAX];

string seq[MAX];

Queue qu[MAX];

int b = 1;
int bv = 0;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	fi(1, n) {
		scanf(" %c%d", &type[i], &a[i]);
		bal[a[i]] += sgn(type[i]);
	}
	fi(1, n) {
		if (bal[a[i]] == 0) {
			seq[a[i]].pb(type[i]);
		}
	}
	fi(1, 1000000) {
		if (sz(seq[i])) {
			int cur = 0;
			//dbg(i);
			for (char z : seq[i]) {
				cur += sgn(z);
				//dbg(cur);
				qu[i].add(cur);
			}
		}
	}
	int cur = 0;
	fi(1, 1000000) {
		if (sz(seq[i]) && qu[i].get_min() >= 0) {
			cur++;
		}
	}
	fi(1, n) {
		if (cur > bv) {
			bv = cur;
			b = i;
		}
		dbg(i);
		dbg(cur);
		//dbg(mp(b, bv));

		if (bal[a[i]] == 0) {
			if (qu[a[i]].get_min() >= 0) {
				cur--;
			}
			qu[a[i]].del();
			qu[a[i]].modify(-sgn(type[i]));
			qu[a[i]].add(0);
			//qu[a[i]].print();
			//dbg(qu[a[i]].get_min());
			if (qu[a[i]].get_min() >= 0) {
				cur++;
			}
		}
	}
	dbg(cur);
	printf("%d %d\n", b, bv);
	exit();
	return 0;
}
