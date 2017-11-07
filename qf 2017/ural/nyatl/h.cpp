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

#ifdef _DEBUG
#define MAX 110
#else
#define MAX 100100
#endif

int n;
int p[MAX];
int ans;
int ansp[MAX];

int d[MAX][2];
int b[MAX][2];
int q[MAX];
vector<int> e[MAX];

int dfs(int x) {
    q[x]++;
    fi(0, sz(e[x]) - 1) {
	q[x] += dfs(e[x][i]);
    }
    return q[x];
}

int fun(int x, int f) {
    if (d[x][f] != -1) return d[x][f];
    if (!sz(e[x])) {
	return d[x][f] = 0;
    }
    int res = -1;
    int sum = 0;
    if (f == 1) {
	res = 0;
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    res += fun(y, 0);
	}
    } else {
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    sum += fun(y, 0);
	}
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    if (sum - fun(y, 0) + fun(y, 1) + 1 > res) {
		res = sum - fun(y, 0) + fun(y, 1) + 1;
		b[x][f] = e[x][i];
	    }
	}
    }
    return d[x][f] = res;
}

vector <int> leaf;
int match[MAX];

void dfs1(int x, int f) {
    if (!sz(e[x]) && !f) {
	leaf.pb(x);
    }

    fi(0, sz(e[x]) - 1) {
	int y = e[x][i];
	dfs1(e[x][i], match[x] == y);	
    }
}

void dfs0(int x, int f) {
    if (!sz(e[x])) return;
    if (f == 0) {
	match[x] = b[x][0];
	dfs0(b[x][0], 1);
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    if (b[x][0] == y) continue;
	    dfs0(y, 0);
	}
    } else {
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    dfs0(y, 0);
	}
    }
}

int dfs2(int x, int f) {
    if (!sz(e[x]) && !f) return true;
    if (f == 0) {
	assert(match[x] != 0);
	if (dfs2(match[x], 1)) {
	    match[x] = 0;
	    return true;
	}
    } else {
	fi(0, sz(e[x]) - 1) {
	    int y = e[x][i];
	    if (dfs2(y, 0)) {
		assert(match[x] == 0);
		match[x] = y;
		return true;
	    }
	}
    }
    return false;
}

int u[MAX];

void solve() {
    vector <int> v;
    memset(d, -1, sizeof(d));
    fi(1, n) {
	if (p[i] == 0) dfs(i);
    }
    int cnt = 0;
    int size = 0;
    fi(1, n) {
	fun(i, 0);
	fun(i, 1);
    }

    fi(1, n) {
	if (p[i] != 0) continue;
	dfs0(i, 0);
    }

    fi(1, n) {
	if (p[i] != 0) continue;
	if (d[i][0] > d[i][1]) {			
	    dfs1(i, 0);
	    u[i] = 1;
	}	
    }

    vector<pair<int, int> > P;

    fi(1, n) {
	if (p[i] != 0) continue;		
	if (u[i]) continue;
	P.pb(mp(q[i] - 2 * d[i][0], i));
    }

    sort(P.begin(), P.end());
    reverse(P.begin(), P.end());

    fj(0, sz(P) - 1) {
	int i = P[j].second;
	if (p[i] != 0) continue;		
	if (u[i]) continue;
	u[i] = 1;
	if (i != 1 && sz(leaf) && (!sz(e[i]) || match[i] && dfs2(i, 0))) {
	    ansp[i] = leaf[sz(leaf) - 1];
	    leaf.pop_back();
	    dfs1(i, 1);
	} else {
	    dfs1(i, 0);
	}	
    }

    fi(2, n) {
	ansp[i] = max(1, ansp[i]);
    }
    cpy(p, ansp);
    memset(d, -1, sizeof(d));
    fi(1, n) {
	e[i].clear();
    }
    fi(2, n) {
	e[p[i]].pb(i);
    }
    ans = max(fun(1, 0), fun(1, 1));
}

int main() {
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);

    while (1) {

	leaf.clear();
	clr(p);
	ans = 0;
	clr(ansp);
	clr(d);
	clr(b);
	clr(match);
	clr(q);
	fi(0, MAX - 1) {
	    e[i].clear();
	}

	if (scanf("%d", &n) != 1) break;
	if (n == -1) break;
	fi(2, n) {
	    scanf("%d", &p[i]);
	    e[p[i]].pb(i);
	}
	fi(1, n) {
	    ansp[i] = p[i];
	}

	solve();

	printf("%d\n", ans);
	fi(2, n) {
	    printf("%d ", max(ansp[i], 1));
	}
	printf("\n");
    }

    return 0;
}