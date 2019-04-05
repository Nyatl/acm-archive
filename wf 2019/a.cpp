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
#define sz(x) ((int)(x).size())
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

struct Tile {
	int c, h, num;
	Tile() {};
	Tile(int h) {
		c = -1;
		this->h = h;
		num = -1;
	}
	bool operator<(const Tile &t) const {
		if (h != t.h) return h < t.h;
		return num < t.num;
	}
};

ostream& operator<<(ostream& os, Tile t) {
	os << t.h << "(" << t.num << ")";
	return os;
}

#define MAX 501000

int n;

Tile t1[MAX];
Tile t2[MAX];

Tile ans1[MAX];
Tile ans2[MAX];

void no() {
	printf("impossible\n");
	exit(0);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);
	
	fi(1, n) {
		t1[i].num = i;
		t2[i].num = i;
	}

	fi(1, n) {
		scanf("%d", &t2[i].c);
	}	
	fi(1, n) {
		scanf("%d", &t2[i].h);
	}
	
	fi(1, n) {
		scanf("%d", &t1[i].c);
	}	
	fi(1, n) {
		scanf("%d", &t1[i].h);
	}
	
	
	sort(t1 + 1, t1 + n + 1, [](const Tile &t1, const Tile &t2){
		return t1.c < t2.c;
	});
	
	sort(t2 + 1, t2 + n + 1, [](const Tile &t1, const Tile &t2){
		return t1.c < t2.c;
	});

	set<Tile> s1;
	set<Tile> s2;
	
	int c1 = 0;
	int c2 = 0;
	fi(1, n) {	
		if (!sz(s1)) {
			c1++;
			s1.insert(t1[c1]);
			while (t1[c1 + 1].c == t1[c1].c) {
				c1++;
				s1.insert(t1[c1]);
			}
		}
		if (!sz(s2)) {
			c2++;
			s2.insert(t2[c2]);
			while (t2[c2 + 1].c == t2[c2].c) {
				c2++;
				s2.insert(t2[c2]);
			}
		}
		dbg(i);
		dbg(s1);
		dbg(s2);
		if (sz(s1) < sz(s2)) {
			ans1[i] = *s1.begin();			
			s1.erase(s1.begin());
			auto it = s2.lower_bound(Tile(ans1[i].h + 1));
			if (it == s2.end()) no();
			ans2[i] = *it;
			s2.erase(it);
		} else {
			ans2[i] = *s2.begin();			
			s2.erase(s2.begin());
			auto it = s1.lower_bound(Tile(ans2[i].h));
			if (it == s1.begin()) no();
			it--;
			ans1[i] = *it;
			s1.erase(it);
		}
	}
	
	fi(1, n) {
		printf("%d ", ans2[i].num);
	}
	printf("\n");
	
	fi(1, n) {
		printf("%d ", ans1[i].num);
	}
	printf("\n");
	
	exit();
	return 0;
}
