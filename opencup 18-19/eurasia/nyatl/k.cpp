#include <bits/stdc++.h>

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
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 0; ABC < n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for (int ABC = 1; ABC <= n; ABC++) cerr << x[ABC] << ' '; cerr << endl;}
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

#define MAX 4

int n = 3;
double alpha, phi;
double time0;

double temp[MAX];

double matr[MAX][MAX];

double pi = acos(-1.);

void mult(double a[MAX][MAX], double b[MAX], double c[MAX]) {
	clr(temp);
	fj(1, n) {
		double sum = 0;
		fi(1, n) {
			sum += a[j][i] * b[i];
		}
		temp[j] = sum;
	}
	cpy(c, temp);
}

void rotate(double &a, double &b, double &c) {
	double v[MAX];
	v[1] = a;
	v[2] = b;
	v[3] = c;
	mult(matr, v, v);
	a = v[1];
	b = v[2];
	c = v[3];
}

void print(double ans) {
	int seconds = (int)(time0 + ans + 0.5 + 1e-9) % (24 * 3600);
	int h = seconds / 3600;
	int m = seconds % 3600 / 60;
	int s = seconds % 3600 % 60;
	printf("%02d:%02d:%02d\n", h, m, s);
}

double get_dist(double diff) {
	double x, y, z;
	diff = (diff / (24 * 3600)) * (2 * pi);
	x = sin(diff) * cos(phi);
	y = cos(diff) * cos(phi);
	z = sin(phi);
	rotate(x, y, z);
	return fabs(z);
}

void solve() {
	double x0, y0, z0;
	x0 = sin(0) * cos(phi);
	y0 = cos(0) * cos(phi);	
	z0 = sin(phi);
	double l, r;
	l = 0;
	r = 6 * 3600;
	while (r - l >= 1) {
		double h1 = l + (r - l) / 3.;
		double h2 = r - (r - l) / 3.;
		if (get_dist(h1) > get_dist(h2) ) {
			l = h1;
		} else {
			r = h2;
		}
	}
	print((l + r) / 2);
}

void init() {
	matr[1][1] = cos(alpha);
	matr[1][3] = sin(alpha);
	matr[2][2] = 1;
	matr[3][3] = cos(alpha);
	matr[3][1] = -sin(alpha);
}

int main() {
#ifdef LOCAL
	freopen("k.in", "r", stdin);
	freopen("k.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%lf %lf", &alpha, &phi);
		alpha = alpha / 180 * pi;
		phi = phi / 180 * pi;
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		time0 = h * 3600 + m * 60 + s;
		init();
		solve();
	}

	exit();
	return 0;
}