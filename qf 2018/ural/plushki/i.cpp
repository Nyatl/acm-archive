#include <bits/stdc++.h>
 
using namespace std;
 
#define fi(a, b) for (int i = a; i <= b; i++) 
#define fj(a, b) for (int j = a; j <= b; j++) 
#define fo(a, b) for (int o = a; o <= b; o++) 
#define fdi(a, b) for (int i = a; i >= b; i--) 
#define fdj(a, b) for (int j = a; j >= b; j--) 
#define fdo(a, b) for (int o = a; o >= b; o--) 
#define sz(x) (int) x.size()
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
double START_TIME;
 
template<typename T1, typename T2>
ostream& operator<<(ostream &s, pair<T1, T2> v) {
    s << "(" << v.first << ", " << v.second << ")";
    return s;
}
 
template<typename T>
ostream& operator<<(ostream &s, vector<T> v) {
    for (auto z : v) {
        s << z << " ";
    }
    return s;
}
 
template<typename T>
ostream& operator<<(ostream &s, set<T> v) {
    for (auto z : v) {
        s << z << " ";
    }
    return s;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream &s, map<T1, T2> v) {
    for (auto z : v) {
        s << "(" << v.first << "->" << v.second << ")" << endl;
    }
    return s;
}
 
void exit() {
    cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
    exit(0);
}
 
#ifdef LOCAL
#define err(...) fprintf(__VA_ARGS__)
#define dbg(x) {cerr << __LINE__ << "\t" << #x << " : " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << " : "; for (int ABC = 0; ABC < n; ABC++) cerr << x[i] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << " : "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[i] << " "; cerr << endl;}
#else
#define err(...) while (0) {}
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif
 
///////////////////////////////
 
int n;
 
vector<vi> localAns;
 
vi query(const vi &qs) {
    assert(sz(qs) <= n);
    assert(sz(qs) > 0);
    for (int z : qs) {
        assert(z <= n);
        assert(z > 0);
    }
     
    vi res;
     
#ifdef LOCAL
    for (int z : qs) {
        res.insert(res.end(), all(localAns[z - 1]));
    }
#else
    printf("? %d", sz(qs));
    for (int z : qs) {
        printf(" %d", z);
    }
    printf("\n");
    fflush(stdout);
     
    int cnt;
     
    scanf("%d", &cnt);
    fi(1, cnt) {
        int tmp;
        scanf("%d", &tmp);
        res.pb(tmp);
    }
#endif
    return res;
}
 
void queryAns(const vector<vi> &ans) {
#ifdef LOCAL
    assert(localAns == ans);
#else
    printf("!");
    for (auto &z : ans) {
        printf(" %d", sz(z));
        for (int z2 : z) {
            printf(" %d", z2);
        }
    }
    printf("\n");
    fflush(stdout);
    exit(0);
#endif
}
 
vi sub(const vi &v, int l, int r) {
    vi res;
    fi(l, r) {
        res.pb(v[i]);
    }
    return res;
}
 
void solve() {
    vector<vi> ans;
    vi req1, req2;
    fi(1, n) req1.pb(i);
    fdi(n, 1) req2.pb(i);
    dbg(req1);
    dbg(req2);
 
    vi resp1 = query(req1);
    vi resp2 = query(req2);
    int k = sz(resp1);
     
    int c = 0;
    fi(1, n) {
        dbg(ans);
        int len = 1;
        while (true) {
            dbg(len);
            vi pos1 = sub(resp1, c, c + len - 1);
            vi pos2 = sub(resp2, k - c - len, k - c - 1);
            dbg(pos1);
            dbg(pos2);
            if (pos1 == pos2) {
                dbg("if");
                ans.pb(pos1);
                c += len;
                dbg("break");
                break;
            }
            len++;
        }
    }
    dbg("end");
     
    queryAns(ans);
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
 
    scanf("%d", &n);
 
#ifdef LOCAL
    fi(1, n) {
        vi cur;
        int k;
        scanf("%d", &k);
        fi(1, k) {
            int tmp;
            scanf("%d", &tmp);
            cur.pb(tmp);
        }
        localAns.pb(cur);
    }
#endif
     
    solve();
 
    exit();
    return 0;
}
