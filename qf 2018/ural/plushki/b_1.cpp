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
 
char matr[105][105];
 
int n;
 
void solve() {
    scanf("%d", &n);
    int pos = 2;
    fi(1, 100) {
        fj(1, 100) {
            matr[i][j] = '.';
        }
    }
    while (n > 2) {
        n -= 2;
        matr[pos][1] = matr[1][pos] = 'o';
        pos++;
    }
    matr[1][1] = 'o';
    n--;
    if (n) {
        matr[2][2] = 'o';
        n--;
    }
    printf("100\n");
    fdi(100, 1) {
        printf("%s\n", matr[i] + 1);
    }
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    START_TIME = clock();
#endif
 
    solve();
 
    exit();
    return 0;
}
