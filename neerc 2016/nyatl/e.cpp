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
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long ll;

#define FILENAME "expect"

#define MAX 100100

int n, q;

multiset<pair<ll, int>, greater<pair<ll, int> > > ms;

vector<pair<int, int> > queries;

ll ans[MAX];
ll r[MAX];

ll mdf = 0;
ll sum = 0;
ll cnt = 0;

void add(ll v, int c) {
	ms.insert(mp(v, c));	
	sum += (ll) v * c;
	cnt += c;
}

ll get_max() {
	return ms.begin()->first + mdf;
}

void remove() {
	multiset<pair<ll, int>, greater<pair<ll, int> > >::iterator it = ms.begin();
	cnt -= it->second;
	sum -= (it->first + mdf) * (ll)it->second;
	ms.erase(it);
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	scanf("%d %d", &n, &q);
	char com[256];
	int time = 0;
	ll cur = 0;
	fi(1, n) {		
		scanf("%s", com);
		int t, a;
		scanf("%d %d", &t, &a);
		if (cur < 0) {
			add(cur, t - time);
		}
		if (com[0] == '-') {
			cur -= a;
		} else {
			cur += a;
		}
		time = t;
	}

	if (cur < 0) {
		add(cur, 1);
	}

	fi(1, q) {
		int x;
		scanf("%d", &x);
		queries.pb(mp(x, i));
	}	
	sort(queries.begin(), queries.end());

	ll last = 0;

	fi(0, SIZE(queries) - 1) {
		if (cur < 0 && queries[i].first < -cur) {
			r[i + 1] = -1;
		}
		ll d_mdf = queries[i].first - last;
		mdf += d_mdf;
		sum += d_mdf * cnt;
		while (SIZE(ms) > 0 && get_max() >= 0) {
			remove();
 		}
		last = queries[i].first;
		if (r[i + 1] != -1) {
			r[i + 1] = -sum;
		}
	}

	fi(0, q - 1) {
		ans[queries[i].second] = r[i + 1];
	}

	fi(1, q) {
		if (ans[i] == -1) {
			printf("INFINITY\n");
		} else {
			printf("%lld\n", ans[i]);
		}
	}

	return 0;
}
