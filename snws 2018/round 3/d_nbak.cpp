#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fdi(a,b) for(int i = (a); i >= (b); --i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << " : " << x << endl;
#else
#define dbg(x) while(0){}
#endif

#define N 50005

int r, o, l;

vector<int> es[N], esinv[N];

char f[N];

char bad[N];

void dfs(int x) {
	if (f[x]) {
		return;
	}
	f[x] = true;
	fi(0, sz(esinv[x]) - 1) {
		dfs(esinv[x][i]);
	}
}

char f1[N];
char color[N];

int ans;

char f3[N];
int comp[N];
int C;

void dfs1(int x) {
	if (f1[x]) {
		if (color[comp[x]] == 2) {
			ans--;
			dbg(x);
			color[comp[x]] = 0;
		}
		return;
	}
	f1[x] = true;
	fi(0, sz(es[x]) - 1) {
		dfs1(es[x][i]);
	}
}


vector<int> order;

void dfs3(int x) {
	if (f3[x]) {
		return;
	}
	f3[x] = true;
	fi(0, sz(es[x]) - 1) {
		dfs3(es[x][i]);
	}
	order.pb(x);
}

void dfs4(int x) {
	if (f[x]) {
		return;
	}
	if (comp[x]) {
		return;
	}
	comp[x] = C;
	fi(0, sz(esinv[x]) - 1) {
		dfs4(esinv[x][i]);
	}
}

void solve() {
	scanf("%d%d%d", &r, &o, &l);
	fi(1, l) {
		int a, b;
		scanf("%d%d", &a, &b);
		a++;
		b++;
		es[a].pb(b);
		esinv[b].pb(a);
	}
	fi(1, o) {
		int a;
		scanf("%d", &a);
		a++;
		bad[a] = true;
	}
	fi(1, r) {
		if (bad[i]) {
			dfs(i);
		}
	}
	fi(1, r) {
		ans += (f[i] && !bad[i]);
		
	}
	fi(1, r) {
		if (!f[i]) {
			dfs3(i);
		}
	}
	fdi(sz(order) - 1, 0) {
		C++;
		dfs4(order[i]);
	}
	fi(1, r) {
		if (!f[i]) {
			if (!f1[i]) {
				ans++;
				dfs1(i);
				color[comp[i]] = 2;
			}
		}
	}
	assert(ans >= 0);
	printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	solve();
	
	return 0;
}