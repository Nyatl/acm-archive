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

int const MAX = 100 * 1000 + 41;
ll const INF = (ll) 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

int n;
int x[MAX];
int y[MAX];
int S;
ll ans, diff;

struct Point {
	ll x, y;
	Point() {};
	Point (ll x, ll y) : x(x), y(y) {};
	bool operator<(const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	};
};

ll getarea(Point a, Point b, Point c) {
	ll res = 0;
	res += (b.x - a.x) * (a.y + b.y);
	res += (c.x - b.x) * (b.y + c.y);
	res += (a.x - c.x) * (a.y + c.y);
	return res;
}

Point p[MAX];

vector<Point> hi, lo;
ll prefhi[MAX];
ll preflo[MAX];
ll sufhi[MAX];
ll suflo[MAX];

void printhull(int step) {
	err("hull after %d:\n", step);
	err("hi: ");
	fi(0, sz(hi) - 1) {
		err("{%lld;%lld} ", hi[i].x, hi[i].y);
	}
	err(" lo: ");
	fdi(sz(lo) - 1, 0) {
		err("{%lld;%lld} ", lo[i].x, lo[i].y);
	}
	err("\n");
}

void buildhull(ll a[MAX], ll b[MAX]) {
	hi.clear();
	lo.clear();
	fi(1, n) {
		//hi
		a[i] = a[i - 1];
		while (sz(hi) > 1) {
			ll area = getarea(hi[sz(hi) - 2], hi[sz(hi) - 1], p[i]);
			if (area > 0) break;
			if (sz(hi) > 2) {
				a[i] -= abs(getarea(hi[0], hi[sz(hi) - 2], hi[sz(hi) - 1]));
			}
			hi.pop_back();			
		}
		if (sz(hi) > 1) {
			a[i] += abs(getarea(hi[0], hi[sz(hi) - 1], p[i]));
		}
		hi.pb(p[i]);
		//lo
		b[i] = b[i - 1];
		while (sz(lo) > 1) {
			ll area = getarea(lo[sz(lo) - 2], lo[sz(lo) - 1], p[i]);
			if (area < 0) break;
			if (sz(lo) > 2) {
				b[i] -= abs(getarea(lo[0], lo[sz(lo) - 2], lo[sz(lo) - 1]));
			}
//			err("i = %d area = %lld {%lld;%lld} {%lld;%lld} {%lld;%lld}\n", i, area, lo[sz(lo) - 2].x, lo[sz(lo) - 2].y, lo[sz(lo) - 1].x, lo[sz(lo) - 1].y, p[i].x, p[i].y);
			lo.pop_back();			
		}
		if (sz(lo) > 1) {
			a[i] += abs(getarea(lo[0], lo[sz(lo) - 1], p[i]));
		}
		lo.pb(p[i]);
		printhull(i);
	}			
}

void solve() {
	fi(1, n) {
		p[i] = Point(x[i], y[i]);
	}
	sort(p + 1, p + n + 1);
	buildhull(prefhi, preflo);
	fi(1, n) {
		p[i].x *= -1;
		p[i].y *= -1;
	}
	sort(p + 1, p + n + 1);
	buildhull(sufhi, suflo);
	diff = INF;
	fi(1, n) {
		if (i == n || (p[i].x != p[i + 1].x)) {
			ll a0 = prefhi[n - i] + preflo[n - i];
			ll a1 = sufhi[i] + suflo[i];
			ll d = abs(a0 - a1);
			ll g = abs(d - S * 2);
			if (g < diff || (g == diff && ans > d)) {
				diff = g;
				ans = d;
			}
		}
	}	
	printf("%.15lf\n", (double) ans / 2);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &S);
	fi(1, n) {
		scanf("%d %d", &x[i], &y[i]);
	}
	solve();		


	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}