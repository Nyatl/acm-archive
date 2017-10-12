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
typedef unsigned long long ull;

#define FILENAME "circuit"

ll gcd(ll x, ll y) {
        return x == 0 ? y : gcd(y % x, x);
}

struct Frac {
        ll a, b;
        Frac operator+(const Frac x) const {
                Frac res;
                res.a = a * x.b + b * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator-(const Frac x) const {
                Frac res;
                res.a = a * x.b - b * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator*(const Frac x) const {
                Frac res;
                res.a = a * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator/(const Frac x) const {
                Frac res;
                res.a = a * x.b;
                res.b = b * x.a;
                res.reduce();
                return res;
        }
        Frac operator|(const Frac x) const {
                Frac res;
                res = (x * *this) / (x + *this);
                res.reduce();
                return res;
        }
        bool operator<(const Frac x) const {
                return (double)a/b < (double)x.a/x.b;
        }
        Frac() {
                a = 0;
                b = 1;
        }
        Frac(ll a) {
                this->a = a;
                this->b = 1;
        }
        Frac(ll a, ll b) {
                this->a = a;
                this->b = b;
        }
        Frac abs() {
                Frac res = *this;
                res.a = res.a < 0 ? -res.a : res.a;
                return res;
        }

        void reduce() {
                ll g = ::abs(gcd(a, b));
                a /= g;
                b /= g;
        }
};

int A, B;
int n;
int r[6];

set <pair<int, Frac> > g;

void init() {
        fi(1, n) {
                g.insert(mp(1 << i, Frac(r[i])));
        }
}

Frac ans;

void solve() {
        fi(1, 10) {
                for (set <pair<int, Frac> >::iterator it = g.begin(); it != g.end(); it++) {
                        for (set <pair<int, Frac> >::iterator it2 = g.begin(); it2 != g.end(); it2++) {
                                if ((it->first ^ it2->first) != (it->first | it2->first)) continue;
                                g.insert(mp(it->first | it2->first, it->second + it2->second));
                                g.insert(mp(it->first | it2->first, it->second | it2->second));
                        }
                }
        }
        ans = Frac(1000000000000000000LL);
        for (set <pair<int, Frac> >::iterator it = g.begin(); it != g.end(); it++) {
                Frac f = (it->second - Frac(A, B)).abs();
                if (f < ans) {
                        ans = f;
                }
        }
}

int main() {
        freopen(FILENAME ".in", "r", stdin);
        freopen(FILENAME ".out", "w", stdout);
        scanf("%d %d %d", &n, &A, &B);
        fi(1, n) {
                scanf("%d", &r[i]);
        }
        init();
        solve();

        printf("%lld/%lld\n", ans.a, ans.b);

        return 0;
}