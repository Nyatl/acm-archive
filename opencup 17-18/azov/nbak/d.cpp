#include <iostream>

#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <cstdio>
#include <ctime>



using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, set<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif 

const int MAX = 100000 + 5;

int n, m, t;

vi e[MAX];

int a[MAX];

bool f[MAX];

set<int> susp;

bool checkAdj(int x) {
	for (auto z : e[x]) {
		if (f[z]) {
			return true;
		}
	}
	return false;
}

void solve() {
	susp.insert(all(e[a[1]]));
	f[a[1]] = true;
	int day = 1;
	for (int i = 2; i <= t && sz(susp) > 1; ++i) {
		f[a[i]] = true;
		day++;
		if (susp.find(a[i]) != susp.end()) {
			susp.erase(a[i]);
		} else if (checkAdj(a[i])) {
		} else {
			set<int> suspUpd;
			for (auto z : e[a[i]]) {
				if (susp.find(z) != susp.end()) {
					suspUpd.insert(z);
				}
			}
			
			susp = suspUpd;
		}
	}
	dbg(susp);
	if (sz(susp) != 1) {
		printf("-1\n");
		return;
	}
	printf("%d %d\n", day, *susp.begin());
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	fi(1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	scanf("%d", &t);
	fi(1, t) {
		scanf("%d", &a[i]);
	}
	solve();
	return 0;
}