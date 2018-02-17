#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define sz(a) ((int)(a).size())
#define fi(a,b) for(int i = (a); i < (b); ++i)
#define fj(a,b) for(int j = (a); j < (b); ++j)

const int N = 100005;

int n;
vector<int> v[N], vInv[N];
int perm[N];
int permInv[N];

int color[N];

int h[N];

void bad() {
	printf("-1\n");
	exit(0);
}

void dfs(int x) {
	if(color[x] == 2) {
		return;
	}
	if(color[x] == 1) {
		bad();
	}
	color[x] = 1;
	fi(0, sz(v[x])) {
		dfs(v[x][i]);
	}
	color[x] = 2;
}

void checkCycles() {
	fi (1, n + 1) {
		dfs(i);
	}
}

int getAns(int x) {
	if (h[x]) {
		return h[x];
	}
	if (sz(vInv[x]) == 0) {
		return h[x] = 1;
	}
	int ret = 1;
	fi (0, sz(vInv[x])) {
		ret = max(ret, getAns(vInv[x][i]) + (permInv[x] > permInv[vInv[x][i]]));
	}
	return h[x] = ret;
}

void solve() {
	scanf("%d", &n);
	fi (1, n + 1) {
		scanf("%d", &perm[i]);
		permInv[perm[i]] = i;
	}
	fi (1, n + 1) {
		int k;
		scanf("%d", &k);
		fj (0, k) {
			int t;
			scanf("%d", &t);
			v[i].push_back(t);
			vInv[t].push_back(i);
		}
	}
	checkCycles();
	fi (1, n + 1) {
		getAns(i);
	}
	int ans = 0;
	fi (1, n + 1) {
		//cerr << h[i] << endl;
		ans = max(ans, h[i]);
	}	
	printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}