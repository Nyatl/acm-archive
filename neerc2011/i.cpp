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

/////////////////////////////////

int const MAX = 41;

int n;
int Q, cnt;
vi a, p;

int d[MAX][MAX];

int rec(vi &a, vi &b, int x, int y) {
	if (x == sz(a)) return 0;
	if (y == sz(b)) return 0;
	if (d[x][y] != -1) return d[x][y];
	int res = 0;
	if (a[x] == b[y]) {
		res = 1 + rec(a, b, x + 1, y + 1);
	} else {
		res = max(rec(a, b, x + 1, y), rec(a, b, x, y + 1));
	}
	return d[x][y] = res;
}

int query(vi p) {
	cnt++;
#ifdef LOCAL
	memset(d, 255, sizeof(d));
	return rec(a, p, 0, 0);
#else
	fi(0, sz(p) - 1) {
		if (i) printf(" ");
		printf("%d", p[i]);
	}
	printf("\n");
	fflush(stdout);
	int resp;
	scanf("%d", &resp);
	return resp;
#endif
}

void kill() {
#ifdef LOCAL
	err("have = %d done = %d rem = %d\n", Q, cnt, Q - cnt);
	if (a != p) {
		err("a != p!!!!!!\n");
	}
	if (Q < cnt) {
		printf("bad : %d %d %d\n", Q, cnt, Q - cnt);
	}
#else
	exit(0);
#endif
}

void init() {
#ifdef LOCAL
	a.clear();
	fi(1, n) {
		a.pb(i);
	}
	random_shuffle(a.begin(), a.end());
#endif
	Q = n * n * 5;	
	cnt = 0;
	p.clear();
	fi(1, n) {
		p.pb(i);
	}
	fi(0, 10) {
		random_shuffle(p.begin(), p.end());
	}
}

void solve() {
	init();
	while (1) {
		int q = query(p);
		if (q == n) {
			kill();
			return;
		}					
		bool f = false;
		vi per1, per2;
		fi(0, n - 1) {
			per1.pb(i);
		}
		fi(0, n - 1) {
			per2.pb(i);
		}
		random_shuffle(per1.begin(), per1.end());
		random_shuffle(per2.begin(), per2.end());
		fi(0, sz(per1) - 1) {
			vi p1 = p;
			p1.erase(p1.begin() + per1[i]);
			int x = p[per1[i]];
			fj(0, sz(per2) - 1) {
				vi p2 = p1;
				p2.insert(p2.begin() + per2[j], x);
				int q1 = query(p2);
				if (q1 == n) {
					p = p2;
					kill();
					return;
				}				
				if (q1 > q) {
					p = p2;
					f = true;
					break;					
				}
			}
			if (f) break;
		}
		assert(f);
	}
}

int main() {
	srand(time(0) + clock());
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (1) {
#ifdef LOCAL
		n = rand() % 10 + 1;
		n = 40;
#else
		scanf("%d", &n);
#endif
		solve();		
	}

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}