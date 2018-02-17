#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef _DEBUG
#define LOCAL
#endif

#define fi(a, b) for (int i=a; i<=b; i++)
#define fj(a, b) for (int j=a; j<=b; j++)
#define fo(a, b) for (int o=a; o<=b; o++)
#define fdi(a, b) for (int i=a; i>=b; i--)
#define fdj(a, b) for (int j=a; j>=b; j--)
#define fdo(a, b) for (int o=a; o>=b; o--)
#define cpy(a, b) memcpy(a, b, sizeof(b))
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
typedef pair<int,int> pii;

template<class T>
ostream& operator <<(ostream &s, vector<T> &v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

template<class T>
ostream& operator <<(ostream &s, set<T> &v) {
	for (auto it = v.begin(); it != v.end(); it++) {
		cerr << *it << " ";
	}
	return s;
}

template<class A, class B>
ostream& operator <<(ostream &s, pair<A, B> &p) {	
	cerr << "(" << p.first << ", " << p.second << ")";	
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x,n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl
#define dbg1(x,n) cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl
#else
#define dbg(x) while(0) {}
#define dbg0(x,n) while(0) {}
#define dbg1(x,n) while(0) {}
#endif

const int MAX = 100 * 1000 + 41;
int n, k, m;

set<string> a[MAX];
vector<string> v;
map<string, set<int>> c;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r" ,stdin);
	freopen("output.txt", "w" ,stdout);
#endif

	scanf("%d", &n);
	scanf("%d", &k);
	
	fi(1, k) {
		char tmp[20];
		int C;
		scanf("%d %s", &C, tmp);
		a[C].insert(tmp);
		c[tmp].insert(C);
	}
	
	scanf("%d", &m);
	
	fi(1, m) {
		char tmp[20];
		scanf(" %s", tmp);
		v.pb(tmp);
	}
	
	set<pair<int, bool>> cur, next;
	cur.insert(mp(-1, true));
	
	for (string z : v) {
		if (cur.empty()) break;
		
		for (int C : c[z]) {
			auto first = *(cur.begin());
			if (first.first > C) continue;
			if (sz(cur) == 1) {
				// first.first <= C
				next.insert(mp(C, first.second));
			} else {
				auto it = cur.begin();
				advance(it, 1);
				auto second = *it;
				bool uni = first.second;
				uni &= second.first > C;
				next.insert(mp(C, uni));
			}
		}
		
		cur = next;
		next.clear();
	}
	
	if (cur.empty()) {
		printf("impossible\n");
	} else if (sz(cur) > 1 || !(*(cur.begin())).second) {
		printf("ambiguous\n");
	} else {
		printf("unique\n");
	}
	
	return 0;
}