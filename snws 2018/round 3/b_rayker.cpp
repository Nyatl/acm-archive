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

const int MAX = 1000 * 1000 + 41;

bool k1[MAX], k2[MAX];

int main() {
#ifdef LOCAL
	dbg("LOCAL");
	freopen("input.txt", "r" ,stdin);
	freopen("output.txt", "w" ,stdout);
#endif

	dbg(1);
	int c1, c2;
	scanf("%d", &c1);
	fi(1, c1) {
		int t;
		scanf("%d", &t);
		k1[t] = true;
	}
	
	scanf("%d", &c2);
	fi(1, c2) {
		int t;
		scanf("%d", &t);
		k2[t] = true;
	}
	
	dbg(c1);
	dbg(c2);
	
	dbg1(k1, 10);
	dbg1(k2, 10);
	
	bool o1 = true;
	bool o2 = true;
	
	int ans = 0;
	fi(0, MAX - 1) {
		if (k1[i] && k2[i]) {
			ans++;
			o1 = true;
			o2 = true;
			continue;
		}
		if (k1[i] && o2) {
			ans++;
			o1 = true;
			o2 = false;
			continue;
		}
		if (k2[i] && o1) {
			ans++;
			o1 = false;
			o2 = true;
			continue;
		}
	}

	printf("%d\n", ans);

	return 0;
}
