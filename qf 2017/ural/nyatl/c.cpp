#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <set>
#include <assert.h>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define fi(a,b) for(int i=a; i<=b; i++)
#define fj(a,b) for(int j=a; j<=b; j++)
#define fo(a,b) for(int o=a; o<=b; o++)
#define fdi(a,b) for(int i=a; i>=b; i--)
#define fdj(a,b) for(int j=a; j>=b; j--)
#define fdo(a,b) for(int o=a; o>=b; o--)
#define sz(x) (int)x.size()
#define clr(x) memset(x, 0, sizeof(x))
#define copy(x, y) memset(x, y, sizeof(x))

template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	fi(0, sz(v) - 1) {
		cerr << v[i] << " ";
	}
	return s;
}

#ifdef LOCAL
#define dbg(x) cerr << #x << ": " << x << endl;
#else
#define dbg(x) while(0){}
#endif

typedef long long ll;

#define FILENAME "consonant"

#define MAX 1000100

int n;
int num[MAX];
char str[MAX];

int q[256][256];
int f[256];

void solve() {
	int b = 0;
	int bv = -1;
	fo(0, (1 << 18) - 1) {
		int cur = 0;
		fi(0, 18) {
			fj(i + 1, 18) {
				if (((o >> i) & 1) ^ ((o >> j) & 1)) {
					cur += q[i][j];
				}
			}
		}
		if (cur > bv) {
			b = o;
			bv = cur;
		}
	}
	dbg(bv);
	fi(0, 18) {
		if ((1 << i) & b) {
			f[i] = 1;
		}
	}
	fi(1, n) {
		if (f[num[str[i]]]) {
			printf("%c", str[i] - ('a' - 'A'));
		} else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}

void init() {
	memset(num, -1, sizeof(num));
	num['b'] = 0;
	num['c'] = 1;
	num['d'] = 2;
	num['f'] = 3;
	num['g'] = 4;
	num['h'] = 5;
	num['j'] = 6;
	num['k'] = 7;
	num['l'] = 8;
	num['m'] = 9;
	num['n'] = 10;
	num['p'] = 11;
	num['q'] = 12;
	num['r'] = 13;
	num['s'] = 14;
	num['t'] = 15;
	num['v'] = 16;	
	num['x'] = 17;
	num['z'] = 18;
	
	fi(1, n - 1) {
		int a = num[str[i]];
		int b = num[str[i + 1]];
		if (a == -1 || b == -1) continue;
		dbg(a);
		dbg(b);
		q[a][b]++;
		q[b][a]++;		
	}		
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);	
	scanf("%s", str + 1);
	n = strlen(str + 1);
	init();
	solve();
	return 0;
}


