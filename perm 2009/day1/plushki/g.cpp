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

int const N = 2e5 + 41;
int const K = 141;

int n, k;
ll ans;
ll d[N][K];
int s[N], e[N], p[N][2];

struct Event {
        int id, x, t, nxtid;
        Event() {};
        Event(int id, int x, int t, int nxtid) : id(id), x(x), t(t), nxtid(nxtid) {};
        bool operator<(const Event &a) const {
                return x < a.x;
        };
};

vector<Event> ev;

void prepareevents() {
        fi(0, n) {
                ev.pb(Event(i, s[i], 0, -1));
                ev.pb(Event(i, e[i], 1, -1));
        }
        sort(ev.begin(), ev.end());
        fi(0, sz(ev)) {
                int t = ev[i].t;
                int id = ev[i].id;
                p[id][t] = i;
        }
}

int getleft(int x) {
        int l = -1;
        int r = sz(ev);
        while (r - l > 1) {
                int m = (l + r) / 2;
                if (ev[m].x >= x) r = m;
                else l = m;
        }
        return r;
}

int getright(int x) {
        int l = -1;
        int r = sz(ev);
        while (r - l > 1) {
                int m = (l + r) / 2;
                if (ev[m].x <= x) l = m;
                else r = m;
        }
        return l;
}

int t[N * 4];

void build(int v, int tl, int tr) {
        if (tl == tr) {
                t[v] = -1;
        } else {
                int tm = (tl + tr) / 2;
                build(v * 2 + 1, tl, tm);
                build(v * 2 + 2, tm + 1, tr);
                t[v] = -1;
        }
}

void upd(int v, int tl, int tr, int l, int r, int valid) {
        if (tl > r || l > tr) return;
        if (l <= tl && tr <= r) {
                t[v] = valid;
                return;
        }
        int tm = (tl + tr) / 2;
        upd(v * 2 + 1, tl, tm, l, r, valid);
        upd(v * 2 + 2, tm + 1, tr, l, r, valid);
}

int get(int v, int tl, int tr, int p) {
        if (tl == tr) {
                return t[v];
        } else {
                int tm = (tl + tr) / 2;
                int ret = t[v];
                if (p <= tm) ret = max(ret, get(v * 2 + 1, tl, tm, p));
                else ret = max(ret, get(v * 2 + 2, tm + 1, tr, p));
                return ret;
        }
}

void findrights() {
        fi(0, sz(ev)) {
                int t = ev[i].t;
                if (t == 1) continue;
                int id = ev[i].id;
                ev[i].nxtid = p[id][1];
        }
        fi(0, sz(ev)) {
                int t = ev[i].t;
                if (t == 0) continue;
                int id = ev[i].id;
                int l = p[id][0];
                int r = i;
                upd(0, 0, sz(ev) - 1, l, r, r);
        }
        fi(0, sz(ev)) {
                int t = ev[i].t;
                if (t == 0) continue;
                int id = ev[i].id;
                int val = get(0, 0, sz(ev) - 1, i);
                ev[i].nxtid = val;
        }
}

void remax(ll &a, ll b) {
        a = max(a, b);
}

void solve() {
        prepareevents();
        findrights();
        build(0, 0, sz(ev) - 1);

        fi(0, sz(ev)) {
                fj(0, k) {
                        remax(d[i + 1][j], d[i][j]);
                }
                fj(0, k) {
                        int nxt = ev[i].nxtid;
                        if (nxt != -1) {
                                ll dist = ev[nxt].x - ev[i].x;
                                remax(d[nxt][j + 1], d[i][j] + dist);
                        }
                }
        }

        fi(0, sz(ev) + 1) fj(0, k + 1) {
                remax(ans, d[i][j]);
        }
}

#define FILENAME "timetable"

int main() {
#ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#else
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
#endif

        scanf("%d %d", &n, &k);
        fi(0, n) scanf("%d %d", &s[i], &e[i]);

        solve();

        printf("%lld\n", ans);

        return 0;
}