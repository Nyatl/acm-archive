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
        Frac operator+(Frac x) {
                Frac res;
                res.a = a * x.b + b * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator-(Frac x) {
                Frac res;
                res.a = a * x.b - b * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator*(Frac x) {
                Frac res;
                res.a = a * x.a;
                res.b = b * x.b;
                res.reduce();
                return res;
        }
        Frac operator/(Frac x) {
                Frac res;
                res.a = a * x.b;
                res.b = b * x.a;
                res.reduce();
                return res;
        }
        Frac operator&(Frac x) {
                Frac res;
                res = (x * *this) / (x + *this);
                res.reduce();
                return res;
        }
        bool operator<(Frac x) {
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

struct Circuit {
        ull hash;
        ll mask;
        Frac r;
};

int A, B;
int n;
int r[6];

vector <Circuit> v;
set <ull> u;

void init() {
        fi(1, n) {
                Circuit t;
                t.hash = 456435233 * i * i + i * r[i];
                t.mask = 1LL << i;
                t.r = Frac(r[i]);
                u.insert(t.hash);
                v.pb(t);
        }
}

Frac ans;

void solve() {
        while (1) {
                vector <Circuit> to_add;
                fi(0, sz(v) - 1) {
                        fj(0, sz(v) - 1) {
                                if (i == j) continue;
                                if ((v[i].mask ^ v[j].mask) != (v[i].mask | v[j].mask)) continue;
                                Circuit t;
                                t.hash = 2547 * v[i].hash + 647521 * v[j].hash;
                                t.mask = v[i].mask | v[j].mask;
                                t.r = v[i].r + v[j].r;
                                if (u.find(t.hash) == u.end()) {
                                        u.insert(t.hash);
                                        to_add.pb(t);
                                }
                                t.hash = 25653 * v[i].hash + 4317 * v[j].hash;
                                t.mask = v[i].mask | v[j].mask;
                                t.r = v[i].r & v[j].r;
                                if (u.find(t.hash) == u.end()) {
                                        u.insert(t.hash);
                                        to_add.pb(t);
                                }
                        }
                }
                if (!sz(to_add)) break;
                fi(0, sz(to_add) - 1) {
                        v.pb(to_add[i]);
                }
        }
        ans = (v[0].r - Frac(A, B)).abs();
        fi(1, sz(v) - 1) {
                Frac f = (v[i].r - Frac(A, B)).abs();
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