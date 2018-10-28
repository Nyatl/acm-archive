#include<bits/stdc++.h>
 
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
 
const ll MOD = 998244353;
 
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
 
ll sub(ll a, ll b) {
    return (a - b) % MOD;
}
 
ll mul(ll a, ll b) {
    return (a * b) % MOD;
}
 
///////////////////////////////
 
// todo
const int MAX = 200 * 1000 + 41;
 
int d2[MAX][500];
 
ll calc(int k, int col);
 
ll calc2(int k, int col) {
    if (k < 0) return 0;
    if (d2[k][col] != -1) return d2[k][col];
     
     
    ll res = calc(k, col - 1);
    res = add(res, calc2(k - col, col));
    /*
    fi(0, maxval) {
        res = add(res, calc(k - i * col, col - 1));
    }
    */
    return d2[k][col] = res;
}
 
ll calc(int k, int col) {
    if (col == 0) {
        return k == 0;
    }
     
    ll res = calc2(k, col);
 
    return res;
}
 
int solve(int k0) {
    ll res = 0;
    fi(1, 500) {
        int k = k0 - i * i;
        if (k < 0) break;
        if (k % 2 == 1) continue;
        k /= 2;
        ll tmp = calc(k, i);
        res = add(res, tmp);
    }
    return res;
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    START_TIME = clock();
#endif
    memset(d2, -1, sizeof(d2));
    int t;
    scanf("%d", &t);
    fi(1, t) {
        int n;
        scanf("%d", &n);
        int ans = solve(n);
        printf("%d\n", ans);
    }
 
    exit();
    return 0;
}