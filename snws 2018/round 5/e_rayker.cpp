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

struct Node {
	int len;
	int link;
	map<char, int> next;
	
	Node(int len, int link) : len(len), link(link) {}
};


ostream& operator<<(ostream& s, Node t) {
	s << "{link=" << t.link << ",len=" << t.len;
	s << ",next=[";
	for (auto& e : t.next) s << "{" << e.first << "," << e.second << "}"; 
	s << "]}";
	return s;
}

vector<Node> a;
char tmp[100 * 1000 + 41];

vector<ll> d;
vector<bool> used;

ll calc(int x) {
	if (used[x]) return d[x];
	ll res = 1;
	
	for (auto &e : a[x].next) {
		res += calc(e.second);
	}
	
	used[x] = true;
	return d[x] = res;
}

ll calc() {
	d.assign(sz(a), 0LL);
	used.assign(sz(a), false);
	return calc(0);
}

void solve() {
	char req;
	scanf(" %c", &req);
	scanf(" %s", tmp);
	string s(tmp);
	
	a.clear();
	
	int last = 0;
	int cur = -1;
	a.pb(Node(0, -1));
	
	fi(0, sz(s) - 1) {
		char c = s[i];
		int x = last;
		a.pb(Node(i + 1, -1));
		cur = sz(a) - 1;
		last = cur;
		
		dbg(last);
		for(;x != -1;x = a[x].link) {
			dbg(x);
			if (a[x].next.find(c) == a[x].next.end()) {
				dbg("added");
				dbg(c);
				a[x].next[c] = cur;
			} else {
				break;
			}
		}
		
		if (x == -1) {
			a[cur].link = 0;
			a[0].next[c] = cur;
			continue;
		}
		
		int y = a[x].next[c];
		if (a[y].len == a[x].len + 1) {
			a[cur].link = y;
			continue;
		}
		
		a.pb(Node(-2, -2));
		int clone = sz(a) - 1;
		
		a[clone].len = a[x].len + 1; 
		a[clone].link = a[y].link;
		a[clone].next = a[y].next;
			
		for(;x != -1 ;x = a[x].link) {
			if (a[x].next[c] != y) break;
			a[x].next[c] = clone;
		}
		dbg(cur);
		dbg(clone);
		a[cur].link = clone;
		a[y].link = clone;
	}
	dbg(a);
	
	ll all = calc();
	dbg(d);
	for (Node &z : a) {
		z.next.erase(req);
	}
	
	ll w = calc();
	dbg(d);
	
	ll ans = all - w;
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int ntest;
	scanf("%d", &ntest);
	fi(1, ntest) {
		solve();
	}
	
	return 0;
}
