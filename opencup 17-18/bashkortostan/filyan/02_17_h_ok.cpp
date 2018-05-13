#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;

/////////////////////////////////

int const MAX = 1e3 + 41;
int const INF = 1e9 + 41;

int n, m;
char s[MAX][MAX];

pii nxt[MAX][MAX][4];

int d[MAX][MAX];

bool inside(int x, int y) {
	if (x < 0 || y < 0) return false;
	if (x > n || y > m) return false;
	return true;
}

pii st, en;

struct State {
	int x, y, d;
	State () {};
	State (int x, int y, int d) : x(x), y(y), d(d) {};
	bool operator<(const State &a) const {
		if (d != a.d) return d < a.d;
		if (x != a.x) return x < a.x;
		return y < a.y;
	};
};

pii const EMP = mp(-1, -1);
int u[MAX][MAX];

void solve() {
	fi(1, n) {
		fj(1, m) {
			if (s[i][j] == 'K') {
				st = mp(i, j);
				s[i][j] = '.';
			}
			if (s[i][j] == 'S') {
				en = mp(i, j);
				s[i][j] = '.';
			}
		}
	}
	fi(0, MAX - 1) {
		fj(0, MAX - 1) {
			fo(0, 3) {
				nxt[i][j][o] = EMP;
			}
		}
	}
	//0
	fj(1, m) {
		fi(1, n) {
			nxt[i][j][0] = nxt[i - 1][j][0];
			if (i > 1 && s[i - 1][j] != '#') {
				nxt[i][j][0] = mp(i - 1, j);
			}			
		}
	}
	//2
	fj(1, m) {
		fdi(n, 1) {
			nxt[i][j][2] = nxt[i + 1][j][2];
			if (i + 1 <= n && s[i + 1][j] != '#') {
				nxt[i][j][2] = mp(i + 1, j);
			}			
		}
	}
	//1
	fi(1, n) {
		fdj(m, 1) {
			nxt[i][j][1] = nxt[i][j + 1][1];
			if (j + 1 <= m && s[i][j + 1] != '#') {
				nxt[i][j][1] = mp(i, j + 1);
			}
		}
	}
	//3
	fi(1, n) {
		fj(1, m) {
			nxt[i][j][3] = nxt[i][j - 1][3];
			if (j > 1 && s[i][j - 1] != '#') {
				nxt[i][j][3] = mp(i, j - 1);
			}
		}
	}

	fi(0, MAX - 1) {
		fj(0, MAX - 1) {
			d[i][j] = INF;
		}
	}
	set<State> t;
	t.insert(State(st.first, st.second, 0));
	d[st.first][st.second] = 0;
	while (sz(t)) {
		State x = (*t.begin());
		t.erase(t.begin());
		if (u[x.x][x.y]) continue;
		fo(0, 3) {
			pii y = nxt[x.x][x.y][o];
			if (y == EMP) continue;
			if (s[y.first][y.second] != '.') continue;
			int cost = abs(x.x - y.first) + abs(x.y - y.second);
			if (d[y.first][y.second] > x.d + cost) {
				/*
				if (y == en) {
					err("cost = %d from = %d %d dir = %d\n", cost, x.x, x.y, o);
				}
				*/
				d[y.first][y.second] = x.d + cost;
				t.insert(State(y.first, y.second, d[y.first][y.second]));
			}
		}
		u[x.x][x.y] = 1;
	}
	/*
	fi(1, n) {
		fj(1, m) {
			if (d[i][j] == INF) d[i][j] = -1;
			err("%2d", d[i][j]);
		}
		err("\n");
	}
	*/
	int ans = -1;
	if (u[en.first][en.second]) {
		ans = d[en.first][en.second];
	} 
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	fi(1, n) {
		scanf(" %s", s[i] + 1);
	}  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}