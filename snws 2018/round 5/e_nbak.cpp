#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <string.h>
using namespace std;

#define sz(a) (int)(a).size()

#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fdi(a,b) for(int i = (a); i >= (b); --i)

#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef long long ll;

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << " : " << x << endl;
#else
#define dbg(x) while(0){}
#endif

struct state {
	int len, link;
	map<char, int> nxt;
};

#define MAXN 100000

vector<state> st;

int siz, lst;

void init(int len) {
	st.clear();
	st.resize(2 * len);
	siz = lst = 0;
	st[0].len = 0;
	st[0].link = -1;
	siz++;
}

void extend(char c) {
	int cur = siz++;
	st[cur].len = st[lst].len + 1;
	int p;
	for (p = lst; p != -1 && !st[p].nxt.count(c); p = st[p].link) {
		st[p].nxt[c] = cur;
	}
	if (p == -1) {
		st[cur].link = 0;
	} else {
		int q = st[p].nxt[c];
		if (st[p].len + 1 == st[q].len) {
			st[cur].link = q;
		} else {
			int clone = siz++;
			st[clone].len = st[p].len + 1;
			st[clone].nxt = st[q].nxt;
			st[clone].link = st[q].link;
			for (; p != -1 && st[p].nxt[c] == q; p = st[p].link) {
				st[p].nxt[c] = clone;
			}
			st[q].link = st[cur].link = clone;
		}
	}
	lst = cur;
}

char buff[2 * MAXN];
char c;

ll d1[2 * MAXN];
ll d2[2 * MAXN];


ll dfs1(int x) {
	if (d1[x]) {
		return d1[x];
	}
	d1[x] = 1;
	for (auto p : st[x].nxt) {
		d1[x] += dfs1(p.second);
	}
	return d1[x];
}

ll dfs2(int x) {
	if (d2[x]) {
		return d2[x];
	}
	d2[x] = 1;
	for (auto p : st[x].nxt) {
		if (p.first == c) {
			continue;
		}
		d2[x] += dfs2(p.second);
	}
	return d2[x];
}

void solve() {
	ll qall = dfs1(0);
	ll qwo = dfs2(0);
	ll ans = qall - qwo;
	printf("%lld\n", ans);
}

void clear() {
	fi(0, sz(st)) {
		d1[i] = 0;
		d2[i] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf(" %c", &c);
		scanf(" %s", buff);
		int len = strlen(buff);
		init(len);
		int p = 0;
		while (buff[p]) {
			extend(buff[p]);
			p++;
		}
		solve();
		clear();
	}
	return 0;
}