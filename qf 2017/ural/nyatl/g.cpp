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

#ifdef _DEBUG
#define LOCAL
#endif

#ifdef LOCAL
#define dbg(x) cerr << #x << ": " << x << endl;
#else
#define dbg(x) while(0){}
#endif

typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;

#define FILENAME "grand"

#define MAX 300100

int test;
int n, m;

struct Edge {
    int v;
    int f;
    int c;
    Edge *next;
    Edge *rev;
};

Edge *e[MAX];

void insert(int x, int v, int c) {
    Edge *t = new Edge;
    t->v = v;
    t->f = 0;
    t->c = c;
    t->next = e[x];
    e[x] = t;

    Edge *t2 = new Edge;
    t2->v = x;
    t2->f = 0;
    t2->c = 0;
    t2->next = e[v];
    e[v] = t2;

    t->rev = t2;
    t2->rev = t;
}

int TEST;
int C;
int k;
int _num1[MAX];
int _num2[MAX];
int _cnum1[MAX];
int _cnum2[MAX];
int orig[MAX];

int num1(int x) {
    if (_cnum1[x] == TEST) {
	return _num1[x];
    }
    _cnum1[x] = TEST;
    k++;
    orig[k] = x;
    return _num1[x] = k;
}

int num2(int x) {
    if (_cnum2[x] == TEST) {
	return _num2[x];
    }
    _cnum2[x] = TEST;
    k++;
    orig[k] = -1;
    return _num2[x] = k;
}

vector<int> E[MAX];

int S, T;
int S1, S2;

int used[MAX];
int timeV[MAX];
vector<int> Tstack;
vector<int> Sstack;
int cTime;
bool found;

bool dfs(int v, int from) {
    if (used[v] == 2) return false;
    if (used[v] == 1) {
	if (!Tstack.empty() && timeV[Tstack.back()] > timeV[v]) {
	    found = true;
	    S1 = v;
	    S2 = Sstack.back();
	    T = Tstack.back();
	    return true;
	} else {

	    if (!Sstack.empty()) {
		assert(timeV[Sstack.back()] <= timeV[v]);
	    }
	    Sstack.pb(v);
	    return true;
	}
    }

    cTime++;
    timeV[v] = cTime;
    used[v] = 1;

    bool ok = false;
    fi(0, sz(E[v]) - 1) {
	int to = E[v][i];
	if (to == from) continue;
	bool cur = dfs(to, v);
	if (found) {
	    return true;
	}
	if (cur) assert(!Sstack.empty());
	if (!Sstack.empty() && Sstack.back() == v) {
	    Sstack.pop_back();
	    continue;
	}
	if (cur) {
	    Tstack.pb(v);
	}

	ok |= cur;
    }
    if (!Tstack.empty() && Tstack.back() == v) {
	Tstack.pop_back();
    }
    used[v] = 2;
    return ok;
}

void findST() {
    if (TEST == 371) {
	TEST = TEST;
    }
    S = -1;
    T = -1;
    S1 = 0;
    S2 = 0;

    cTime = 0;
    Tstack.clear();
    Sstack.clear();
    found = false;
    fi(0, 2 * n) {
	used[i] = 0;
	timeV[i] = -1;

    }


    vector <int> P;
    fi(1, n) {
	P.pb(i);
    }

    //random_shuffle(P.begin(), P.end());

    fi(1, n) {
	if (!used[i]) {
	    dfs(i, -1);
	}
	if (found) break;
    }
}

int p[MAX];
int color[MAX];

vector <int> vc;

int dfs(int x) {
    if (color[x] == C) return false;
    color[x] = C;
    if (x == num1(T)) {
	vc.pb(T);
	return true;
    }
    for (Edge *y = e[x]; y; y = y->next) {
	if (y->f == y->c) continue;
	if (dfs(y->v)) {
	    y->f++;
	    y->rev->f--;
	    if (orig[x] > 0) {
		vc.pb(orig[x]);
	    }
	    return true;
	}
    }
    return false;
}

void dfs2(int x) {
    if (x == num1(T)) {
	vc.pb(T);
	return;
    }
    for (Edge *y = e[x]; y; y = y->next) {
	if (y->f >= 1) {
	    y->f--;
	    dfs2(y->v);
	    if (orig[x] != -1) {
		vc.pb(orig[x]);
	    }
	    break;
	}
    }
}

int try_solve() {
    dbg(S);
    dbg(T);
    if (S == -1 || T == -1) return false;
    if (S == T) return false;
    fi(0, k) {
	for (Edge *y = e[i]; y; y = y->next) {
	    y->f = 0;
	}
    }
    vector <vector<int> > ans;
    fi(1, 3) {
	C++;
	if (!dfs(num2(S))) {
	    return false;
	}
    }

    fi(1, 3) {
	vc.clear();
	dfs2(num2(S));
	dbg(vc);
	vc.pb(S);
	reverse(vc.begin(), vc.end());
	ans.pb(vc);
    }

    assert(sz(ans[0]) >= 2);
    assert(sz(ans[1]) >= 2);
    assert(sz(ans[2]) >= 2);

    printf("%d %d\n", S, T);
    fi(0, sz(ans) - 1) {
	printf("%d ", sz(ans[i]));
	fj(0, sz(ans[i]) - 1) {
	    printf("%d ", ans[i][j]);
	}
	printf("\n");
    }
    return true;
}

void solve() {
    scanf("%d %d", &n, &m);
    k = 0;
    fi(0, 3 * n) {
	E[i].clear();
	e[i] = 0;
    }
    fi(1, m) {
	int a, b;
	scanf("%d %d", &a, &b);
	insert(num2(a), num1(b), 1);
	insert(num2(b), num1(a), 1);
	E[a].pb(b);
	E[b].pb(a);
    }
    fi(1, n) {
	insert(num1(i), num2(i), 1);
    }
    fi(1, 1) {
	findST();
	if (!found) continue;
	S = S2;
	if (try_solve()) return;
	S = S1;
	if (try_solve()) return;
	//		assert(false);
    }
    printf("-1\n");
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    scanf("%d", &test);
    while (test--) {
	TEST++;
	fprintf(stderr, "%d\n", TEST);
	solve();
    }
    return 0;
}
