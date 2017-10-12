#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <tuple>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(a) ((int)((a).size()))
#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fo(a, b) for(int o = (a); o < (b); ++o)
#define fdi(a, b) for(int i = (int)(a) - 1; i >= (b); --i)
#define fdo(a, b) for(int o = (int)(a) - 1; o >= (b); --o)
#define fdj(a, b) for(int j = (int)(a) - 1; i >= (b); --j)
#define all(a) (a).begin(),(a).end()
#define _(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/////////////////////////////////

int const N = 1e4 + 41;
int const M = 1e5 + 41;

struct Event {
        ll p, f;
        Event() {};
        Event(ll p, ll f) : p(p), f(f) {}
        bool operator<(const Event & a) const {
                if (p != a.p) {
                        return p < a.p;
                }
                return f < a.f;
        }
};

int p[N];
int n, m;

ll pref[N];
ll ans[M];

vector<Event> es;

void solve() {
        scanf("%d%d", &n, &m);
        fi(0, n) {
                scanf("%d", &p[i]);
                pref[i + 1] = pref[i] + p[i];
        }
        fi(0, m) {
                int bs, ps, bf, pf;
                scanf("%d%d%d%d", &bs, &ps, &bf, &pf);
                ll pgs = pref[bs - 1] + p[bs - 1] - ps + 1;
                ll pgf = pref[bf - 1] + p[bf - 1] - pf + 1;
                if (pgs > pgf) {
                        swap(pgs, pgf);
                }
                pgf += 1;
                es.push_back(Event(pgs, 0));
                es.push_back(Event(pgf, 1));
        }
        es.push_back(Event(pref[n] + 1, 2));
        sort(all(es));
        int bal = 0;
        ll prp = 1;
        fi(0, sz(es)) {
                ans[bal] += es[i].p - prp;
                prp = es[i].p;
                if (es[i].f) {
                        --bal;
                } else {
                        ++bal;
                }
        }
        fi(0, m + 1) {
                printf("%lld\n", ans[i]);
        }
}

#define FILENAME "worms"

int main() {
#ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#else
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
#endif

        solve();

        return 0;
}