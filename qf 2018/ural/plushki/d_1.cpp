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
#define err(...) fprintf(stderr, __VA_ARGS__)
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
 
const int MAX = 1041;
 
char s[MAX];
int n;
int k;
int dev;
 
ll ans;
 
ll solvesmall(int len) {
    set<string> t;    
    string tmp = "";
    while (sz(tmp) < len * 2) {
        tmp += string(s + 1);
    }
    if (sz(tmp) > n) {
        tmp.resize(n);
    }
    dbg(tmp);
     
    fi(0, sz(tmp) - 1) {
        fj(1, len) {
            if (i + j - 1 >= sz(tmp)) break;
            string str = tmp.substr(i, j);
            t.insert(str);
        }
    }
    dbg(t);
    return sz(t);
}
 
void solve() {
    ll anssmall = solvesmall(dev * 2 - 1);
    ll anslarge = 0;
    fi(1, dev) {
        ll x = i + dev * 2 - 1;
        ll ways = max(0LL, n - x + 1);
        if (ways > 0) {
            err("i = %d ways = %lld\n", i, ways);
        }
        anslarge += ways;
    }
    ans = anssmall + anslarge;
    printf("%lld\n", ans);
#ifdef LOCAL
    ll bruteans = solvesmall(n);
    dbg(bruteans);
    if (bruteans != ans) {
        err("brute = %lld ans = %lld\n", bruteans, ans);
    }
    assert(bruteans == ans);
#endif  
}
 
void init() {
    string tmp = string(s + 1);
    fi(1, k) {
        if (k % i != 0) continue;
        string str = tmp.substr(0, i);
        string cur = "";
        while (sz(cur) != k) {
            cur += str;
        }
        if (cur == tmp) {
            dev = i;            
            break;
        }
    }
    dbg(tmp.substr(0, dev));
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    START_TIME = clock();
#endif
 
    scanf("%s", s + 1);
    k = strlen(s + 1);
    scanf("%d", &n);
    init();
    solve();
 
    exit();
    return 0;
}
