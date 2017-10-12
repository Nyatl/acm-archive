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

void relax(Frac f) {
        if ((Frac(A, B) - f).abs() < ans) {
                ans = (Frac(A, B) - f).abs();
        }
}

void solve1(Frac r1) {
        relax(r1);
}

void solve2(Frac r1, Frac r2) {
        relax(r1 + r2);
        relax(r1 | r2);
}

void solve3(Frac r1, Frac r2, Frac r3) {
        relax(r1 + r2 + r3);
        relax(r1 + (r2 | r3));
        relax(r1 | (r2 | r3));
}

void solve4(Frac r1, Frac r2, Frac r3, Frac r4) {
        relax(r1 + (r2 + (r3 + r4)));
        relax(r1 + (r2 + (r3 | r4)));
        relax(r1 + (r2 | (r3 | r4)));
        relax(r1 + (r2 | (r3 + r4)));
        relax(r1 + (r2 + (r3 | r4)));
        relax(r1 + (r2 + (r3 + r4)));
        relax(r1 | (r2 + (r3 | r4)));
        relax(r1 | (r2 | (r3 | r4)));
        relax(r1 | (r2 | (r3 + r4)));
        relax(r1 | (r2 + (r3 | r4)));
        relax((r1 | r2) | (r3 | r4));
        relax((r1 | r2) + (r3 | r4));
        relax((r1 + r2) | (r3 + r4));
}

void solve5(Frac r1, Frac r2, Frac r3, Frac r4, Frac r5) {
        relax(r1 + (r2 + (r3 + (r4 + r5))));
        relax(r1 + (r2 + (r3 + (r4 | r5))));
        relax(r1 + (r2 + (r3 | (r4 | r5))));
        relax(r1 + (r2 + (r3 | (r4 + r5))));
        relax(r1 + (r2 + (r3 + (r4 | r5))));
        relax(r1 + (r2 + (r3 + (r4 + r5))));
        relax(r1 + (r2 | (r3 + (r4 | r5))));
        relax(r1 + (r2 | (r3 | (r4 | r5))));
        relax(r1 + (r2 | (r3 | (r4 + r5))));
        relax(r1 + (r2 | (r3 + (r4 | r5))));
        relax(r1 + ((r2 | r3) | (r4 | r5)));
        relax(r1 + ((r2 | r3) + (r4 | r5)));
        relax(r1 + ((r2 + r3) | (r4 + r5)));

        relax(r1 | (r2 + (r3 + (r4 + r5))));
        relax(r1 | (r2 + (r3 + (r4 | r5))));
        relax(r1 | (r2 + (r3 | (r4 | r5))));
        relax(r1 | (r2 + (r3 | (r4 + r5))));
        relax(r1 | (r2 + (r3 + (r4 | r5))));
        relax(r1 | (r2 + (r3 + (r4 + r5))));
        relax(r1 | (r2 | (r3 + (r4 | r5))));
        relax(r1 | (r2 | (r3 | (r4 | r5))));
        relax(r1 | (r2 | (r3 | (r4 + r5))));
        relax(r1 | (r2 | (r3 + (r4 | r5))));
        relax(r1 | ((r2 | r3) | (r4 | r5)));
        relax(r1 | ((r2 | r3) + (r4 | r5)));
        relax(r1 | ((r2 + r3) | (r4 + r5)));

        relax((r1 | r2) | (r3 | r4 | r5));
        relax((r1 | r2) | (r3 | (r4 + r5)));
        relax((r1 | r2) | (r3 + r4 + r5));

        relax((r1 | r2) + (r3 | r4 | r5));
        relax((r1 | r2) + (r3 | (r4 + r5)));
        relax((r1 | r2) + (r3 + r4 + r5));

        relax((r1 + r2) | (r3 | r4 | r5));
        relax((r1 + r2) | (r3 | (r4 + r5)));
        relax((r1 + r2) | (r3 + r4 + r5));

        relax((r1 + r2) + (r3 | r4 | r5));
        relax((r1 + r2) + (r3 | (r4 + r5)));
        relax((r1 + r2) + (r3 + r4 + r5));

}

void solve() {
        sort(r + 1, r + n + 1);
        do {
                if (n >= 1) solve1(r[1]);
                if (n >= 2) solve2(r[1], r[2]);
                if (n >= 3) solve3(r[1], r[2], r[3]);
                if (n >= 4) solve4(r[1], r[2], r[3], r[4]);
                if (n >= 5) solve5(r[1], r[2], r[3], r[4], r[5]);
        } while (next_permutation(r + 1, r + n + 1));
}

int main() {
        freopen(FILENAME ".in", "r", stdin);
        freopen(FILENAME ".out", "w", stdout);
        scanf("%d %d %d", &n, &A, &B);
        fi(1, n) {
                scanf("%d", &r[i]);
        }
        init();

        ans = Frac(1000000000000000000LL);

        solve();

        printf("%lld/%lld\n", ans.a, ans.b);

        return 0;
}