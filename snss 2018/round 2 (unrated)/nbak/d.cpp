#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif 

const int MAX = 105;

const int INF = 1000000;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;

char matr[MAX][MAX];
bool isc[MAX][MAX];

int xs;
int ys;

void fillc(int x, int y) {
	fi(0, 3) {
		fj(1, MAX) {
			int x2 = x + dx[i] * j;
			int y2 = y + dy[i] * j;
			if (matr[x2][y2] == 'W') {
				break;
			}
			if (matr[x2][y2] == '.') {
				isc[x2][y2] = 1;
			}
		}
	}
}

int d[MAX][MAX];
int f[MAX][MAX];

pii nxt[MAX][MAX];

void djk() {
	fi (1, n) {
		fj(1, m) {
			d[i][j] = INF;
		}
	}
	set<pair<int, pii > > t;
	t.insert(mp(0, mp(xs, ys)));
	d[xs][ys] = 0;
	while (sz(t)) {
		auto p = t.begin()->second;
		t.erase(t.begin());
		int x = p.first;
		int y = p.second;
		if (!(matr[x][y] == '.' || matr[x][y] == 'S' || matr[x][y] == 'C')) continue;
		if (f[x][y]) continue;
		f[x][y] = 1;
		fi(0, 3) {
			pii p2 = nxt[x + dx[i]][y + dy[i]];
			int d2 = d[x][y] + 1;
			int x2 = p2.first;
			int y2 = p2.second;
			
			if (x2 == -1) continue;
			
			if (d[x2][y2] > d2) {
				d[x2][y2] = d2;
				t.insert(mp(d2, p2));
			}
		}
	}
}

int color[MAX][MAX];

pii dfs(int x, int y) {
	if (color[x][y] == 2) {
		return nxt[x][y];
	}
	if (color[x][y] == 1) {
		return mp(-1, -1);
	}
	color[x][y] = 1;
	pii res = mp(x, y);
	if (isc[x][y]) {
		res = mp(-1, -1);
	} else if (matr[x][y] == 'W') {
		res = mp(-1, -1);
	} else if (matr[x][y] == 'L') {
		res = dfs(x, y - 1);
	} else if (matr[x][y] == 'R') {
		res = dfs(x, y + 1);
	} else if (matr[x][y] == 'U') {
		res = dfs(x - 1, y);
	} else if (matr[x][y] == 'D') {
		res = dfs(x + 1, y);
	}
	color[x][y] = 2;
	return nxt[x][y] = res;
}

void calcNxt() {
	fi(1, n) {
		fj(1, m) {
			if (isc[i][j]) {
				nxt[i][j] = mp(-1, -1);
			} else {
				nxt[i][j] = dfs(i, j);
			}
		}
	}
}

void solve() {
	fi(1, n) {
		fj(1, m) {
			if (matr[i][j] == 'S') {
				xs = i;
				ys = j;
			}
		}
	}
	dbg(mp(xs, ys));
	fi(1, n) {
		fj(1, m) {
			if (matr[i][j] == 'C') {
				fillc(i, j);
			}
		}
	}
	fi(1, n) {
		dbg1(isc[i], m);
	}
	calcNxt();
	fi(1, n) {
		dbg1(nxt[i], m);
	}
	djk();
	fi(1, n) {
		dbg1(d[i], m);
	}
	fi(1, n) {
		fj(1, m) {
			if (matr[i][j] == '.') {
				if (d[i][j] < INF) {
					printf("%d\n", d[i][j]);
				} else {
					printf("-1\n");
				}
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	fi(1, n) {
		scanf("%s", matr[i] + 1);
	}
	solve();
	return 0;
}