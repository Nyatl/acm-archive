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

#define FILENAME "kotlin"

int h, w, n;

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%d%d%d", &h, &w, &n);
	
	int h1 = (h + 1) / 2;
	int w1 = (w + 1) / 2;
	
	bool ok = false;
	int ah = -1;
	int aw = -1;
	fi(1, h1) {
		fj(1, w1) {
			if (i * j == n) {
				ah = i;
				aw = j;
				
				ok = true;
				break;		
			}
		}
		if (ok) break;
	}
	if (!ok) {
		printf("Impossible\n");
		return 0;
	}
	
	fi(1, h) {
		fj(1, w) {
			if ((j + 1) / 2 <= aw 
				&& (i + 1) / 2 <= ah 
				&& j % 2 == 1
				&& i % 2 == 1) 
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
	
	return 0;
}


