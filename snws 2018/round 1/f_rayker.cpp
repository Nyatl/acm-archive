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

#ifdef _DEBUG
#define LOCAL
#endif

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

vector<string> convert(string s, char y, char x) {
	vector<string> res;

	fi(0, sz(s) - 1) {
		if (s[i] == x) break;
		if (s[i] == y) {
			string s2 = s;
			s2[i] = x;
			res.pb(s2);
		}
	}
	
	bool shouldbe = false;
	fi(0, sz(s) - 1) {
		if (s[i] == x) {
			shouldbe = true;
		}
	}
	if (!shouldbe) res.pb(s);
	
	return res;
}

void solve(string s) {
	set<string> cur = {s}, nxt;
	
	fdi('z', 'b') {
		for (string z : cur) {
			auto tmp = convert(z, (char)(i - 1), (char)i);
			nxt.insert(all(tmp));
		}
		cur = nxt;
		nxt.clear();
	}
	
	
	printf("%d\n", sz(cur));
	
	if (sz(cur) <= 10) {
		for (string z : cur) {
			printf("%s\n", z.c_str());
		}
		return;
	}
	
	
	vector<string> ans;
	for (string z : cur) {
		ans.pb(z);
	}
	fi(0, 4) {
		printf("%s\n", ans[i].c_str());
	}
	
	fi(sz(ans) - 5, sz(ans) - 1) {
		printf("%s\n", ans[i].c_str());
	}
	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char tmp[25];
	while(true) {
		scanf(" %s", tmp);
		string s = tmp;
		if (s == "#") break;
		solve(s);
	}
	
	return 0;
}
