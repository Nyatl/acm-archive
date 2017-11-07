#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <set>
#include <assert.h>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define fi(a,b) for(int i=a; i<=b; i++)
#define fj(a,b) for(int j=a; j<=b; j++)
#define fo(a,b) for(int o=a; o<=b; o++)
#define fdi(a,b) for(int i=a; i>=b; i--)
#define fdj(a,b) for(int j=a; j>=b; j--)
#define fdo(a,b) for(int o=a; o>=b; o--)
#define sz(x) (int)x.size()
#define clr(x) memset(x, 0, sizeof(x))
#define copy(x, y) memset(x, y, sizeof(x)).
#define pb push_back
#define mp make_pair

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << #x << ": " << x << endl;
#else
#define dbg(x) while(0){}
#endif

typedef long long ll;

#define FILENAME "equal"

#define MAX 1001000
#define INF 1000000000

typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;

#define K 1000000

int n;
int a[MAX];
int ans1[MAX];
int ans2[MAX];
int q[MAX];
int f[MAX];

void init() {
	fi(0, n) {
		ans1[i] = INF;
		ans2[i] = INF;
	}
	fi(1, K) {
		if (!q[i]) continue;
		for (int j = 2 * i; j <= K; j += i) {
			if (q[j]) {
				f[i] = 1;
				break;
			}
		}
	}
}

void solve1() {
	vector<int> v;
	int cur = 0;
	fi(1, K) {
		if (!q[i]) continue;
		cur++;
		if (!f[i]) continue;
		v.pb(q[i]);
	}	
	sort(v.begin(), v.end());
	dbg(v);
	int p = 0;
	ans1[p] = cur;
	fi(0, sz(v) - 1) {
		fj(1, v[i]) {
			p++;
			if (j == v[i]) cur--;
			ans1[p] = cur;
		}
	}
	while (p < n + 1) {
		p++;
		ans1[p] = ans1[p - 1];
	}
}

void solve2() {
	vector<int> v;
	int cur = 0;
	fi(1, K) {
		if (!q[i]) continue;
		cur++;
		v.pb(q[i]);
	}
	sort(v.begin(), v.end());
	dbg(v);	
	int p = 0;
	ans2[p] = cur;
	fi(0, sz(v) - 1) {
		fj(1, v[i]) {
			if (i == 0 && j == 1) cur++;
			p++;
			if (j == v[i]) cur--;			
			ans2[p] = cur;
		}
	}
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);	
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
	fi(1, n) {
		q[a[i]]++;
	}
	init();
	solve1();
	solve2();
#ifdef LOCAL
	fi(0, n) {
		fprintf(stderr, "%d ", ans1[i]);
	}
	fprintf(stderr, "\n");
	fi(0, n) {
		fprintf(stderr, "%d ", ans2[i]);
	}
	fprintf(stderr, "\n");
#endif
	fi(0, n) {
		printf("%d ", min(ans1[i], ans2[i]));
	}
	printf("\n");
	return 0;
}


