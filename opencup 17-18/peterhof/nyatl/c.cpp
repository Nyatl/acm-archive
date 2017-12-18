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

#define MAX 300

char str[200];
 
int rev[256];
int _num[256];
int n;
int l;

int num(int x) {
	if (_num[x] == 0) {
		n++;
		_num[x] = n;
		rev[n] = x;
	}
	return _num[x];
}

int matr[MAX][MAX];

int d[15][2200];
int p[15][2200];

int fun(int x, int mask) {
	if (d[x][mask] != -1) return d[x][mask];
	int res = 1;
	p[x][mask] = -1;
	fi(1, n) {
		if (!matr[x][i]) continue;
		if ((1 << i) & mask) continue;
		int t = fun(i, mask | (1 << i)) + 1;
		if (t > res) {
			res = t;
			p[x][mask] = i;
		}
	}
	return d[x][mask] = res;
}

int ans[256];

void print(int x) {
	vector<int> v;
	int mask = 1 << x;
	fi(1, n) {
		ans[rev[x]] = i;
		int x2 = p[x][mask];
		mask |= 1 << p[x][mask];
		x = x2;
	}

	fprintf(stderr, "ans:\n");
	fi(1, n) {
		fprintf(stderr, "%c -> %d\n", rev[i], ans[rev[i]]);
	}

	fi(1, l) {
		printf("%c ", str[i]);
		if (i != l) {
			if (ans[str[i]] > ans[str[i + 1]]) {
				printf("> ");
			} else if (ans[str[i]] < ans[str[i + 1]]) {
				printf("< ");
			} else {
				printf("= ");
			}
		}
	}
	exit(0);
}

void solve() {
	fi(1, n) {
		memset(d, -1, sizeof(d));
		memset(p, 0, sizeof(p));
		fun(i, 1 << i);
		if (d[i][1 << i] == n) {
			print(i);
			return;
		}		
	}
	printf("Impossible\n");
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%s", str + 1);
    l = strlen(str + 1);
    fi(1, l - 1) {
    	char a = num(str[i]);
    	char b = num(str[i + 1]);
    	matr[a][b] = 1;
    	matr[b][a] = 1;
    }
    dbg(n);
    solve();
    return 0;
}
