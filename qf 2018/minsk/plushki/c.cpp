#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++) 
#define fj(a, b) for (int j = a; j <= b; j++) 
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--) 
#define fdj(a, b) for (int j = a; j >= b; j--) 
#define fdo(a, b) for (int o = a; o >= b; o--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

template<typename A, typename B>
ostream& operator<<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")" << endl;
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}
/*
template<typename A, typename B>
ostream& operator<<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}*/

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": " << x << endl; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": " << x << endl; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define err(...) while (0) {}
#define dbg(x) while (0) {}
#define dbg0(x, n) while (0) {}
#define dbg1(x, n) while (0) {}
#endif
 
void exit() {	
	exit(0);
}

//////////////////////

const int MAX = (1 << 15) + 41;

int eq[20], vq[20];
vi e[MAX];
set<int> rev[MAX];
bool f[MAX];
int d[MAX];
set<int> pos[MAX];
int k, m, n;
queue<int> qu;

void bad(string s) {
	dbg(s);
	
#ifdef LOCAL
	assert(false);
#endif
	printf("No\n");
	exit();
}

set<int> nears(int x) {
	set<int> res;
	fi(0, k - 1) {
		int tmp = x ^ (1 << i);
		if (!f[tmp]) res.insert(tmp);
	}
	if (res.empty()) bad("5");
	return res;
}

void ans(int x, int v) {
	d[x] = v;
	f[v] = true;
}

set<int> cross(set<int> &a, set<int> &b) {
	set<int> res;
	for (int x : a) {
		if (b.count(x)) res.insert(x);
	}
	if (res.empty()) bad("6");
	return res;
}

void upd(int x);

void relax(int val) {
	for (int x : rev[val]) {
		if (d[x] != -1) continue;
		pos[x].erase(x);
		if (sz(pos[x]) == 1) upd(x);
	}
}

void upd(int x) {
	ans(x, *(pos[x].begin()));
	qu.push(x);
//	relax(x);
}

vector<pii> e3;

void solve() {
	fill_n(&d[0], MAX, -1);
	dbg(n);
	dbg(k);

	if (m != eq[k]) bad("1");
	fi(0, n - 1) {
		//dbg(sz(e[i]));
		if (sz(e[i]) != k) bad("2");
	}
	dbg("asdf");
	
	
	int start = abs(rand()) % n;
//	int start = 6;
	ans(start, 0);
	pos[start].insert(0);
	fi(0, sz(e[start]) - 1) {
		int y = e[start][i];
		ans(y, 1 << i);
		pos[y].insert(1 << i);
		qu.push(y);
	}
	
	//dbg0(d, n);
	
	while (sz(qu)) {
		int x = qu.front();qu.pop();
		
		for (int y : e[x]) {
			if (d[y] != -1) continue;
			set<int> nrs = nears(d[x]);
			if (pos[y].empty()) {
				pos[y] = nrs;
			} else {
				pos[y] = cross(pos[y], nrs);
			}
			for (int val : pos[y]) {
				rev[val].insert(y);
			}
			//dbg(pos[y]);

			if (sz(pos[y]) == 1) {
				upd(y);
			}
		}
		//dbg0(d, n);
	}
	

	dbg0(d, n);
	dbg0(f, n);
	fi(0, n - 1) {
		if (d[i] == -1) bad("3");
	}

	fi(0, n - 1) {
		if (!f[i]) bad("4");
	}	
		
	for (auto z : e3) {
		int a = d[z.first] ^ d[z.second];
		if (__builtin_popcount(a) != 1) {
			bad("asd");
		}
	}
	
	printf("Yes\n");
	fi(0, n - 1) {
		printf("%d ", d[i]);
	}
	printf("\n");
}

void init() {
	vq[0] = 1;
	eq[0] = 0;
	fi(1, 19) {
		vq[i] = vq[i - 1] * 2;
		eq[i] = eq[i - 1] * 2 + vq[i - 1];
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	scanf("%d %d", &k, &m);
	n = vq[k];
	
	
	fi(1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
		e3.pb(mp(a, b));
	}
	solve();
	
	
	return 0;
}
