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

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef LOCAL	
	fprintf(stderr, "\n");
#endif	
}

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
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

const int MAX = 100005;

struct Room {
	int p;
	int c;
	int num;
	Room() {}
	Room(int p, int c, int num) : p(p), c(c), num(num) {}
	bool operator<(const Room &r) const {
		if (p != r.p) {
			return p < r.p;
		}
		if (c != r.c) {
			return c < r.c;
		}
		return num < r.num;
	}
};

struct Employee {
	int a, b;
	int num;
	Employee() {}
	Employee(int a, int b, int num) : a(a), b(b), num(num) {}
	bool operator<(const Employee & e) const {
		if (b - a != e.b - e.a) {
			return b - a < e.b - e.a;
		}
		if (a != e.a) {
			return a < e.a;
		}
		return num < e.num;
	}
};

ostream& operator<<(ostream& os, Employee t) {
	os << '{' << t.num << ':' << t.a << ' ' << t.b << '}';
	return os;
}

int n, m, l;

Room rooms[MAX];
Employee es[MAX];
Employee emps[MAX];
int ps[MAX];
vi ans[MAX];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif
	scanf("%d %d %d", &n, &m, &l);
	fi(1, n) {
		int p, c;
		scanf("%d %d", &p, &c);
		rooms[i] = Room(p, c, i);
		ps[i] = p;
	}
	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		emps[i] = Employee(a, b, i);
		es[i] = Employee(a, b, i);
	}
	sort(rooms + 1, rooms + 1 + n);
	sort(emps + 1, emps + 1 + m);
	dbg1(emps, m);
	int c1 = 1;
	int c2 = n;
	fi(1, m) {
		if (emps[i].a > emps[i].b) {
			ans[rooms[c1].num].pb(emps[i].num);
			if (sz(ans[rooms[c1].num]) == rooms[c1].c) {
				c1++;
			}
		}
	}
	fdi(m, 1) {
		if (emps[i].a <= emps[i].b) {
			ans[rooms[c2].num].pb(emps[i].num);
			if (sz(ans[rooms[c2].num]) == rooms[c2].c) {
				c2--;
			}
		}
	}
	ll sum = 0;
	fi(1, n) {
		for (int z : ans[i]) {
			sum += 2LL * (ps[i] * (ll)es[z].a + (l - ps[i]) * (ll)es[z].b);
		}
	}
	printf("%lld\n", sum);
	fi(1, n) {
		printf("%d", sz(ans[i]));
		for (int z : ans[i]) {
			printf(" %d", z);
		}
		printf("\n");
	}
	exit();
	return 0;
}
