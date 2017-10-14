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

typedef long long ll;

#define MAX 1010

int n;
int l[MAX];
vector <int> e[MAX];
int a[MAX];

int r[MAX];
int p[MAX];

bool _less(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second >= 0 && p2.second < 0) {
		return true;
	}
	if (p1.second < 0 && p2.second >= 0) {
		return false;
	}
	if (p1.second >= 0 && p2.second >= 0) {
		return p1.first < p2.first;
	}
	return p1.first + p1.second > p2.first + p2.second;
}

void dfs(int x) {
	if (!sz(e[x])) {
		r[x] = l[x] + max(0, l[x] - a[x]);
		p[x] = a[x] - 2 * l[x];
		return;
	}

	vector <pair<int, int> > v;

	fi(0, sz(e[x]) - 1) {
		int y = e[x][i];
		dfs(y);
		v.pb(mp(r[y], p[y]));
	}
	sort(v.begin(), v.end(), _less);

	int cur = -l[x];

	r[x] = l[x];

	fi(0, sz(v) - 1) {
		r[x] = max(r[x], v[i].first - cur);
		cur += v[i].second;
	}
	cur -= l[x];
	r[x] = max(r[x], -cur);
	p[x] = cur;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &l[i]);
		int q;
		scanf("%d", &q);		
		if (q == 0) {
			scanf("%d", &a[i]);
		} else {
			fj(1, q) {
				int t;
				scanf("%d", &t);
				e[i].pb(t);
			}
		}
	}
	dfs(1);
	printf("%d\n", r[1]);
	return 0;
}
