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
#define dbg0(x,n) {cerr << __LINE__ << "\t" << #x << ": "; fi(0, n) cerr << x[i] << " "; cerr << endl;}
#define dbg1(x,n) {cerr << __LINE__ << "\t" << #x << ": "; fi(1, n) cerr << x[i] << " "; cerr << endl;}
#define as(x) cerr << __LINE__ << " assertion failed: " << #x << endl, assert(0);
#else
#define dbg(x) while(0){}
#define dbg0(x,n) while(0){}
#define dbg1(x,n) while(0){}
#define as(x) assert(x)
#endif
 
#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
 
#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))
 
#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000
 
void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}
 
int n;
int a;
int ans;

int hexNum(int x) {
	return 1 + 3 * x * (x - 1);
}

void calcA() {
	int l = 0, r = 20000;
	while(r - l > 1) {
		int h = (r + l) / 2;
		if(n < hexNum(h)) {
			r = h;
		} else {
			l = h;
		}
	}
	a = l;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    calcA();
    ans = 6 * a;
    int rem = n - hexNum(a);
    dbg(ans);
    dbg(a);
    dbg(rem);
    if (rem == 0) {
    	ans += 0;
    } else if (rem < a) {
    	ans += 1;
    } else if(rem < 2 * a) {
    	ans += 2;
    } else if(rem < 3 * a) {
    	ans += 3;
    } else if(rem < 4 * a) {
    	ans += 4;
    } else if(rem < 5 * a) {
    	ans += 5;
    } else {
    	ans += 6;
    }
    printf("%d\n", ans);
    return 0;
}