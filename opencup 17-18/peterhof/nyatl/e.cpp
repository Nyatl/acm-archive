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
#define all(x) (x).being(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
 
template<typename A, typename B>
ostream& operator<<(ostream& s, pair<A, B> p) {
    cerr << "(" << p.first << ", " << p.second << ")";
    return s;
}
 
template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
    fi(0, sz(v) - 1) {
        cerr << v[i] << " ";
    }
    return s;
}

#ifdef _DEBUG
#define LOCAL
#endif
 
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl;
#define dbg0(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x,n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define ass(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x,n) while(0){}
#define dbg1(x,n) while(0){}
#define ass(x) assert(x)
#endif

#define MAX 2500000

int n, m;
int k;
char str[MAX];
char tmp[MAX];

vector<string> s;

set<int> p[256];
int cur;

int get(char x, int shift) {
	return *p[x].lower_bound(cur + shift) - (cur + shift);
}

ll ans = 0;

void solve() {
	fj(0, m - 1) {
		int u = 0;
		fi(0, n - 1) {
			u = max(u, get(s[j][i], i));
		}
		ans += u;
		cur = (cur + u) % k;

		ans++;
		cur = (cur + 1) % k;
	}
	printf("%lld\n", ans);
}

void init() {
	fi(0, k - 1) {
		p[str[i]].insert(i);
		p[str[i]].insert(k + i);
		p[str[i]].insert(2 * k + i);
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%[^\n\r]%*[\n\r]", str);
    k = strlen(str);
    while (scanf("%[^\n\r]%*[\n\r]", tmp) == 1) {
    	m++;
    	s.pb(tmp);
    	tmp[0] = 0;
    }
    n = sz(s[0]);
    init();
    solve();
    return 0;
}