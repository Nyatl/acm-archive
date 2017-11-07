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

#define FILENAME "boolean"

#define MAX 10000

int f1[MAX];
int f2[MAX];

char s[1000];

ll ans;

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	while (1) {
		s[0] = 0;
		scanf("%[^|]|", s);
		if (s[0] == 0) break;
		dbg(s);
		if (s[0] == '~') {
			f2[s[1]] = 1;
		} else {
			f1[s[0]] = 1;		
		}
	}	
	ans = 1;
	int q1 = 0;
	int q2 = 0;
	fi('a', 'z') {
		if (f1[i] && !f2[i] || !f1[i] && f2[i]) q1++;
		if (f1[i] && f2[i]) q2++;
	}
	fi('A', 'Z') {
		if (f1[i] && !f2[i] || !f1[i] && f2[i]) q1++;
		if (f1[i] && f2[i]) q2++;
	}
	dbg(q1);
	dbg(q2);
	fi(1, q1) {
		ans *= 2;
	}
	fi(1, q2) {
		ans *= 2;
	}
	if (q2 == 0) ans--;
	printf("%lld\n", ans);
	return 0;
}


