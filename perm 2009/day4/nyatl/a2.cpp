#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <cmath>
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

#define MAX 520
#define INF 1000000000

int n;
double a[MAX][MAX];
int f[MAX][MAX];

struct Edge {
        int v;
        int f;
        int c;
        double w;
        Edge *next, *rev;
};

Edge *e[MAX];

void insert(int x, int v, int c, double w) {
        Edge *temp = new Edge;
        temp->v = v;
        temp->f = 0;
        temp->c = c;
        temp->w = w;
        temp->next = e[x];
        e[x] = temp;

        Edge *temp2 = new Edge;
        temp2->v = x;
        temp2->f = 0;
        temp2->c = 0;
        temp2->w = -w;
        temp2->next = e[v];
        e[v] = temp2;

        temp->rev = temp2;
        temp2->rev = temp;
}

int S = 1;
int T = 2;
int _num1[MAX];
int _num2[MAX];
int k = 2;

int num1(int x) {
        if (_num1[x] == 0) {
                k++;
                _num1[x] = k;
        }
        return _num1[x];
}

int num2(int x) {
        if (_num2[x] == 0) {
                k++;
                _num2[x] = k;
        }
        return _num2[x];
}

double d[MAX];
Edge *p[MAX];

bool bellman() {
        fi(1, k) {
                d[i] = INF;
                p[i] = NULL;
        }
        d[S] = 0;
        int f = 1;
        while (f) {
                f = 0;
                fi(1, k) {
                        if (d[i] == INF) continue;
                        for (Edge *y=e[i]; y; y=y->next) {
                                if (y->f == y->c) continue;
                                if (d[i] + y->w + 1e-9 < d[y->v]) {
                                        d[y->v] = d[i] + y->w;
                                        p[y->v] = y;
                                        f = 1;
                                }
                        }
                }
        }
        return p[T] != NULL;
}

void update() {
        int flow = INF;
        int x = T;
        while (x != S) {
                flow = min(flow, p[x]->c - p[x]->f);
                x = p[x]->rev->v;
        }
        x = T;
        while (x != S) {
                p[x]->f += flow;
                p[x]->rev->f -= flow;
                x = p[x]->rev->v;
        }
}

double solve() {
        fi(1, n) {
                if (!bellman()) {
                        printf("0\n");
                        exit(0);
                }
                update();
        }
        double res = 0;
        fi(1, k) {
                for (Edge *y=e[i]; y; y=y->next) {
                        if (y->f > 0) {
                                res += y->w * y->f;
                        }
                }
        }
        return res;
}

void init() {
        fi(1, n) {
                insert(S, num1(i), 1, 0);
        }

        fi(1, n) {
                insert(num2(i), T, 1, 0);
        }

        fi(1, n) {
                fj(1, n) {
                        if (f[i][j]) {
                                insert(num1(i), num2(j), 1, a[i][j]);
                        }
                }
        }

}

int main() {
        freopen("bond2.in", "r", stdin);
        freopen("bond2.out", "w", stdout);
        scanf("%d", &n);
        fj(1, n) {
                fi(1, n) {
                        scanf("%lf", &a[j][i]);
                }
        }

        fj(1, n) {
                fi(1, n) {
                        if (a[j][i] < 80.) {
                                a[j][i] = 0;
                        } else {
                                a[j][i] /= 100.;
                                f[j][i] = 1;
                        }
                }
        }

        fj(1, n) {
                fi(1, n) {
                        if (f[j][i]) {
                                a[j][i] = -log(a[j][i]);
                        }
                }
        }

        init();
        double ans = solve();
        ans = exp(-ans);
        printf("%.15lf\n", ans * 100);
        return 0;
}