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
#define pb push_back
#define mp make_pair

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

#define FILENAME "intel"

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);	
	
	int n;
	vector<pair<ll, ll>> arr;
	scanf("%d", &n);
	fi(0, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr.pb(mp(a, b));
	}
	

	ll sum = 0;
	ll minf = 1e8;
	ll mins = 1e8;
	ll maxf = -1e8;
	ll maxs = -1e8;
	fi(0, n - 1) {
		sum += abs(arr[i].first - arr[(i + 1) % n].first);
		sum += abs(arr[i].second - arr[(i + 1) % n].second);
		
		minf = min(minf, arr[i].first);
		mins = min(mins, arr[i].second);
		maxf = max(maxf, arr[i].first);
		maxs = max(maxs, arr[i].second);				
	}
	
	dbg(minf);
	dbg(maxf);
	dbg(mins);
	dbg(maxs);

	ll ans = sum - 2 * ((maxf - minf) + (maxs - mins));
	printf("%lld\n", ans);	
	
	return 0;
}


