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
const int P = 41;
const int MOD = 1000 * 1000 * 100 + 41;
 
int h[MAX * 4][MAX * 4];
  
int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
  
int mul(int a, int b) {
    return (ll) a * b % MOD;
}
  
string S;
 
void build() {
    fi(0, sz(S) - 1) {
        int hash = 0;
        int p = 1;      
        fj(i, sz(S) - 1) {
            hash = add(hash, mul(p, S[j] - 'a'));
            p = mul(p, P);
            h[i][j] = hash;
        }
    }
}
  
char s[MAX];
int n;
int k;
int dev;
  
ll ans;
  
ll solvesmall(int len) {
    unordered_set<int> t; 
    while (sz(S) < len * 2) {
        S += string(s + 1);
    }
    if (sz(S) > n) {
        S.resize(n);
    }
    build();
      
    fi(0, sz(S) - 1) {
        fj(1, len) {
            if (i + j - 1 >= sz(S)) break;
//          string str = tmp.substr(i, j);          
//          t.insert(str);
            t.insert(h[i][i + j - 1]);
        }
    }
    //dbg(t);
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
