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

typedef long long ll;

#define ADD 1
#define DEL 2
#define MAX 200100

int n, m, k;

struct Event {
	int type;
	int time;
	int num;
	bool operator<(const Event &e) const {
		if (time != e.time) return time < e.time;
		if (type != e.type) return type > e.type;
		return num < e.num;
	}
};

vector <Event> e;

int a[MAX];
int b[MAX];

int s[MAX];
int total[MAX];

int place[MAX];

int ans;
int ansv;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d", &n, &m, &k);
	fi(1, k) {
		scanf("%d %d", &a[i], &b[i]);
	}

	fi(1, k) {
		Event t;
		t.time = a[i];
		t.type = ADD;
		t.num = i;
		e.pb(t);
		t.time = b[i];
		t.type = DEL;
		t.num = i;
		e.pb(t);
	}

	sort(e.begin(), e.end());

	int q = m - 1;
	set<int> p;

	fi(1, m) {
		p.insert(i);
	}

	fi(0, sz(e) - 1) {
		int x = e[i].num;
		if (e[i].type == ADD) {
			if (q > 0) {
				place[x] = -1;
				q--;
			} else if (sz(p)) {
				int fst = *p.begin();
				p.erase(p.begin());
				place[x] = fst;
			}
		} else {
			int pl = place[x];
			if (pl == -1) {
				q++;
			} else if (pl > 0) {
				p.insert(pl);
				total[pl] += b[x] - a[x];
			}
		}
	}

	int bst = 1000000100;
	int bstv = -1;

	fi(1, m) {
		if (total[i] < bst) {
			bst = total[i];
			bstv = i;
		}
	}

	ans = bst;
	ansv = bstv;

	printf("%d %d\n", ans, ansv);

	return 0;
}
