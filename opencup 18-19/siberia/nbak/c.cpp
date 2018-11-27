#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(auto i=a; i<=b; i++)
#define fj(a, b) for(auto j=a; j<=b; j++)
#define fo(a, b) for(auto o=a; o<=b; o++)
#define fy(a) for(auto &y : a)
#define fz(a) for(auto &z : a)
#define fdi(a, b) for(auto i=a; i>=b; i--)
#define fdj(a, b) for(auto j=a; j>=b; j--)
#define fdo(a, b) for(auto o=a; o>=b; o--)
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

void err(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln(const char *format, ... ) {
#ifdef LOCAL
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "\t%s\n", __buffer);
#else
	if (format < 0) {
		__buffer[0]++;
	}
#endif
}

void errln() {
#ifdef LOCAL	
	fprintf(stderr, "\n");
#endif	
}

double START_TIME;

void exit() {
#ifdef LOCAL	
	cerr << "TIME: " << setprecision(5) << fixed << (clock() - START_TIME) / CLOCKS_PER_SEC << endl;
#endif	
	exit(0);
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << (x[ABC]) << ' '; cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

const ll MOD = 2147483647LL;

char matr[16][31] = {
	"X2223X20013X310011100123211XXX",
	"24XX3X2001XXX2122X2111XXX22343",
	"X4X32111235X43X5X43X34443X23X3",
	"X3110113XX3X34XXXX33XXX334X5XX",
	"110112X4X4322XX654X334XX2XXX5X",
	"0001X22X23X323XX2X4X212222334X",
	"1112211112XX1234323X20122101X3",
	"X33X2221135533X3X222112XX2012X",
	"2XX33XX22XXXX3X313X201X6X42121",
	"234X445X335X442213X2013XXX2X10",
	"X22X4XX22X33X3X11X22124X633232",
	"X3325X4112X34X312221X3XX3X12XX",
	"3X2X4X41124X4X323X113X534333X3",
	"X2214XX22X3X312XX3203X5X4XX211",
	"11014X53X22121223X102X4X4X4200",
	"0001XX3X21001X101110112122X100"
};

int n, m, k;

struct Mapa {
	char a[20][35];
	Mapa() {
		fi(1, 16) {
			fj(1, 30) {
				a[i][j] = '?';
			}
		}
	}
};

Mapa cur = Mapa();

bool check(const Mapa &mapa) {
	fi(1, n) {
		fj(1, m) {
			if (cur.a[i][j] == '?') continue;
	//		dbg(mapa.a[i][j]);
			if (cur.a[i][j] != mapa.a[i][j]) return false;
		}
	}
	return true;
}

ll next(ll x) {
	return (48271LL * x) % MOD;
}

Mapa gen(ll x) {
	int q = 0;
	Mapa res = Mapa();
	while (q < k) {
		x = next(x);
		int r = (x / 30) % 16 + 1;
		int c = x % 30 + 1;
		if (res.a[r][c] == '?') {
			res.a[r][c] = 'X';
			q++;
		}
	}
	fi(1, 16) {
		fj(1, 30) {
			if (res.a[i][j] == '?') {
				int cnt = 0;
				cnt += res.a[i + 1][j - 1] == 'X';
				cnt += res.a[i + 1][j + 0] == 'X';
				cnt += res.a[i + 1][j + 1] == 'X';
				cnt += res.a[i - 1][j - 1] == 'X';
				cnt += res.a[i - 1][j + 0] == 'X';
				cnt += res.a[i - 1][j + 1] == 'X';
				cnt += res.a[i + 0][j - 1] == 'X';
				cnt += res.a[i + 0][j + 1] == 'X';
				
				res.a[i][j] = '0' + cnt;
			}
		}
	}
	return res;
}

vector<Mapa> maps;

char buff[100];

int openq;
int boomq;
char query(int x, int y) {
	dbg(mp(x, y));
#ifdef LOCAL
	if (matr[x - 1][y - 1] != 'X') {
		openq++;
	} else {
		boomq++;
	}
	assert(boomq <= 6);
	if (openq == n * m - k) {
		exit();
	}
	return cur.a[x][y] = matr[x - 1][y - 1];
#else
	printf("%d %d\n", x - 1, y - 1);
	fflush(stdout);
	dbg(mp(x, y));
	scanf(" %[^\n\r]", buff);
	assert(buff[0] != 'L');
	if (buff[0] == 'W') {
		exit();
	} else if (buff[0] == 'B') {
		boomq++;
		return cur.a[x][y] = 'X';
	} else if (buff[0] == 'E') {
		openq++;
		return cur.a[x][y] = buff[6];
	} else {
		assert(false);
	}
	return '?';
#endif
}

mt19937 r(time(0) + clock());

pii randC() {
	return mp(r() % n + 1, r() % m + 1);
}

void slct() {
	vector<Mapa> maps2;
	for (Mapa & z : maps) {
		if (check(z)) {
			maps2.pb(z);
		} else {
	//		dbg(3);
		}
	}
	maps = maps2;
}

pii getC() {
	vector<pii> v;
	int b = 100000;
	fi(1, n) {
		fj(1, m) {
			if (cur.a[i][j] != '?') continue;
			int q = 0;
			for (Mapa & z : maps) {
				q += (z.a[i][j] == 'X');
			}
			if (q < b) {
				b = q;
				v.clear();
				v.pb(mp(i, j));
			} else if (q == b) {
				v.pb(mp(i, j));
			}
		}
	}
	return v[r() % sz(v)];
}

void solve() {
	while (boomq < 4) {
		pii p;
		while (true) {
			p = randC();
			if (cur.a[p.first][p.second] == '?') break;
			
		}
		dbg(1);
		query(p.first, p.second);
		dbg(cur.a[p.first][p.second]);
	}
	dbg(maps[0].a[5][4]);
	slct();
	dbg(sz(maps));
	while (true) {
		pii p = getC();
		query(p.first, p.second);
		slct();
	}
}

void init() {
	fi(100, 10000) {
		maps.pb(gen(i));
	}
}

int main() {
#ifdef LOCAL
	START_TIME = (double)clock();
#endif
#ifdef LOCAL
	n = 16;
	m = 30;
	k = 137;
#else
	scanf("%d %d %d", &n, &m, &k);
#endif
	init();
	solve();
	exit();
	return 0;
}
