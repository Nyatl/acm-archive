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

map<ll, vector<ll>> a, ar;
vector<pair<ll, ll>> v;
int height;

int check(int c) {	
	int res = 0;
	for (auto e : a) {
		ll p = e.first;
		for (ll x : e.second) {
			if (x > c) continue;
			if ((c - x) % p == 0) {
				res++;
		 	}
	 	}
	}
	return res;
}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	
	unsigned long long et = clock();
	unsigned long long st = clock();

	int n;
	scanf("%d", &n);
	fi(1, n) {
		ll x, p;
		scanf("%lld%lld", &x, &p);
		a[p].pb(x);
		v.pb({x, p});
	}
	
	for (auto e : a) {
		ll p = e.first;
		vector<ll> xs = e.second;
		map<ll, int> bmd;
		for (ll x : xs) {
			bmd[x % p]++;
		}
		
		int bv = 0;
		for (auto m : bmd) {
			if (m.second > bv) { // if ==
				bv = m.second;
			}
		}
		
		height += bv;
	}

	pair<ll, ll> M = {-1, -1};
	
	for (auto e : a) {
		ar[-e.first] = e.second;
	}
	
	for (auto e : ar) {
		et = clock();
		if (et - st > 1.5 * CLOCKS_PER_SEC) break;
		
		ll p = -e.first;
		vector<ll> xs = e.second;
		for (ll x : xs) {
			et = clock();
			if (et - st > 1.5 * CLOCKS_PER_SEC) break;
			fi(0, 500 * 1000) {
				ll X = x + p * i;
				ll h = check(X);
				pair<ll, ll> pos = {h, -X};
				M = max(pos, M); 
			}
		}
	}
	
	printf("%lld %lld\n", -M.second, M.first);
		
		

	return 0;
}
