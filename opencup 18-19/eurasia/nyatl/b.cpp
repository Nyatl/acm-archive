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

#define MAX 200100

int n;
ll d;

int type[MAX];
ll w[MAX];

int order[MAX];

ll need[MAX];

vector <int> dep[MAX];
int cnt0[MAX];
int cnt[MAX];

int in_buffer;

int processed[MAX];
int played[MAX];

int busy = 0;

void finish(int x) {
	processed[x] = 1;
	fi(0, sz(dep[x]) - 1) {
		cnt[dep[x][i]]--;
		if (cnt[dep[x][i]] == 0 && played[dep[x][i]]) {
			in_buffer--;
		}
	}
}

void print() {
#ifndef LOCAL
	return;
#endif
	dbg1(cnt, n);
	dbg1(played, n);
	dbg1(processed, n);
	errln();
}

#define INF 1000000000000000000LL

bool solve(int k) {
	dbg(k);
	cpy(cnt, cnt0);

	clr(processed);
	clr(played);

	in_buffer = 0;

	fi(1, k) {
		in_buffer++;
	}

	fi(1, k) {
		finish(order[i]);
	}

	int cur_frame = 1;
	int last_frame = k;

	busy = 0;

	ll FINISH = 0;

	ll cur_time = 0;

	while (1) {
		ll T1 = ((cur_time / d) * d) + d;
		ll T2 = FINISH;
		cur_time = min(T1, T2);		

		if (cur_time > (n - 1) * d) break;

		if (cur_time == FINISH) {
			if (busy) {
				finish(busy);
				busy = 0;
			}
			FINISH = INF;
		}

		while (cur_frame <= n && (cur_frame - 1) * d <= cur_time) {
			if (!processed[cur_frame]) return false;
			played[cur_frame] = 1;
			if (cnt[cur_frame] == 0) in_buffer--;
			cur_frame++;
		}

		if (!busy && last_frame < n && in_buffer < k) {
			last_frame++;

			FINISH = cur_time + w[order[last_frame]];

			busy = order[last_frame];
			in_buffer++;
		}
	}

	return true;
}

void init() {	
	int q = 0;
	int c = 1;
	while (c <= n) {
		if (type[c] != 2) {
			q++;
			order[q] = c;
			c++;
		} else {
			fi(c, n) {
				if (type[i] != 2) {
					q++;
					order[q] = i;
					fj(c, i - 1) {
						q++;
						order[q] = j;
					}
					c = i + 1;
				}
			}
		}
	}

	int last = 1;

	fi(1, n) {
		if (type[i] != 0) {
			dep[i].pb(last);
			cnt0[last]++;
		}
		if (type[i] != 2) last = i;
	}

	last = n;

	fdi(n, 1) {
		if (type[i] == 2) {
			dep[i].pb(last);
			cnt0[last]++;
		}
		if (type[i] != 2) last = i;
	}
}

void gen() {
	n = 200000;
	d = 1000000000;
	fi(1, n) {
		type[i] = 2;
	}
	type[1] = 0;
	type[n] = 1;
}

int main() {
#ifdef LOCAL
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d %lld", &n, &d);
	fi(1, n) {
		char g;
		scanf(" %c %lld", &g, &w[i]);
		if (g == 'I') type[i] = 0;
		if (g == 'P') type[i] = 1;
		if (g == 'B') type[i] = 2;
	}

	init();

	int l = 1, r = n;
	while (l < r) {
		int h = (l + r) / 2;
		dbg(h);
		if (!solve(h)) {
			l = h + 1;
		} else {
			r = h;
		}
	}

	printf("%d\n", l);

	exit();
	return 0;
}