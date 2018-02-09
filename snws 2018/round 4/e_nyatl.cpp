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

#define MAX 200100

int n, k;
int m;

vector<pair<int, string> > tmp_v;
vector<pair<int, int> > v;
vs tmp_b;
vi b;  

int f1[MAX];
int f2[MAX];

int q;
map<string, int> to;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", &k);
	fi(1, k) {
		int x;
		char s[20];
		scanf("%d %s", &x, s);
		tmp_v.pb(mp(x, s));
	}

	scanf("%d", &m);
	
	fi(1, m) {
		char s[20];
		scanf("%s", s);
		tmp_b.pb(s);
	}
	
	fi(0, sz(tmp_b) - 1) {
		to[tmp_b[i]] = i + 1;
	}
	
	fi(0, sz(tmp_v) - 1) {
		v.pb(mp(tmp_v[i].first, to[tmp_v[i].second]));
	}
	
	fi(0, sz(tmp_b) - 1) {
		b.pb(to[tmp_b[i]]);
	}

	sort(all(v));
		
	int c;

	dbg(v);
	dbg(b);
		
	c = 0;
	
	fi(0, sz(v) - 1) {
		if (c < sz(b) && v[i].second == b[c]) {
			f1[i] = 1;
			c++;
		}		
	}
	
	dbg(c);
	
	if (c != sz(b)) {
		printf("impossible\n");
		return 0;
	}

	c = sz(b) - 1;
	
	fdi(sz(v) - 1, 0) {
		if (c >= 0 && v[i].second == b[c]) {
			f2[i] = 1;
			c--;
		}		
	}
	
	dbg0(f1, k);
	dbg0(f2, k);
	
	fi(0, sz(v) - 1) {
		if (f1[i] ^ f2[i]) {
			printf("ambiguous\n");
			return 0;
		}
	}
	
	printf("unique\n");
			
	return 0;
}
