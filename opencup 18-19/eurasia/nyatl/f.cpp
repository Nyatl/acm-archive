#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fu(a, b) for(int u=a; u<=b; u++)
#define fw(a, b) for(int w=a; w<=b; w++)
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

#define INF 1000000000

int q[10];

int ans1, ans2;
double ans3;

int MOD;

int A, B, C, D;

int *****d1;
int *****d2;
double *****d3;

int solve1() {
	d1 = new int****[MOD];
	fw(0, MOD - 1) {
		d1[w] = new int***[A + 1];
		fi(0, A) {
			d1[w][i] = new int**[B + 1];
			fj(0, B) {
				d1[w][i][j] = new int*[C + 1];
				fo(0, C) {
					d1[w][i][j][o] = new int[D + 1];
					fu(0, D) {
						d1[w][i][j][o][u] = INF;
					}
				}
			}
		}
	}

	fw(0, MOD - 1) {
		d1[w][0][0][0][0] = (MOD - w) % MOD;
	}

	
	fi(0, A) {
		fj(0, B) {
			fo(0, C) {
				fu(0, D) {
					fw(0, MOD - 1) {
						if (i) {
							int w2 = (w + 1);
							d1[w][i][j][o][u] = min(d1[w][i][j][o][u], d1[w2 % MOD][i - 1][j][o][u] + w2 - w);
						}
						if (j) {
							int w2 = ((w + 1) / 2) * 2 + 2;
							d1[w][i][j][o][u] = min(d1[w][i][j][o][u], d1[w2 % MOD][i][j - 1][o][u] + w2 - w);
						}
						if (o) {
							int w2 = ((w + 3) / 4) * 4 + 4;
							d1[w][i][j][o][u] = min(d1[w][i][j][o][u], d1[w2 % MOD][i][j][o - 1][u] + w2 - w);
						}
						if (u) {
							int w2 = ((w + 7) / 8) * 8 + 8;
							d1[w][i][j][o][u] = min(d1[w][i][j][o][u], d1[w2 % MOD][i][j][o][u - 1] + w2 - w);
						}
						
					}
				}
			}
		}
	}

	return d1[0][A][B][C][D];
}

int solve2() {
	d2 = new int****[MOD];
	fw(0, MOD - 1) {
		d2[w] = new int***[A + 1];
		fi(0, A) {
			d2[w][i] = new int**[B + 1];
			fj(0, B) {
				d2[w][i][j] = new int*[C + 1];
				fo(0, C) {
					d2[w][i][j][o] = new int[D + 1];
					fu(0, D) {
						d2[w][i][j][o][u] = 0;
					}
				}
			}
		}
	}

	fw(0, MOD - 1) {
		d2[w][0][0][0][0] = (MOD - w) % MOD;
	}

	
	fi(0, A) {
		fj(0, B) {
			fo(0, C) {
				fu(0, D) {
					fw(0, MOD - 1) {
						if (i) {
							int w2 = (w + 1);
							d2[w][i][j][o][u] = max(d2[w][i][j][o][u], d2[w2 % MOD][i - 1][j][o][u] + w2 - w);
						}
						if (j) {
							int w2 = ((w + 1) / 2) * 2 + 2;
							d2[w][i][j][o][u] = max(d2[w][i][j][o][u], d2[w2 % MOD][i][j - 1][o][u] + w2 - w);
						}
						if (o) {
							int w2 = ((w + 3) / 4) * 4 + 4;
							d2[w][i][j][o][u] = max(d2[w][i][j][o][u], d2[w2 % MOD][i][j][o - 1][u] + w2 - w);
						}
						if (u) {
							int w2 = ((w + 7) / 8) * 8 + 8;
							d2[w][i][j][o][u] = max(d2[w][i][j][o][u], d2[w2 % MOD][i][j][o][u - 1] + w2 - w);
						}
						
					}
				}
			}
		}
	}

	return d2[0][A][B][C][D];
}

double solve3() {
	d3 = new double****[MOD];
	fw(0, MOD - 1) {
		d3[w] = new double***[A + 1];
		fi(0, A) {
			d3[w][i] = new double**[B + 1];
			fj(0, B) {
				d3[w][i][j] = new double*[C + 1];
				fo(0, C) {
					d3[w][i][j][o] = new double[D + 1];
					fu(0, D) {
						d3[w][i][j][o][u] = 0;
					}
				}
			}
		}
	}

	fw(0, MOD - 1) {
		d3[w][0][0][0][0] = (MOD - w) % MOD;
	}

	
	fi(0, A) {
		fj(0, B) {
			fo(0, C) {
				fu(0, D) {
					fw(0, MOD - 1) {
						if (i) {
							int w2 = (w + 1);
							d3[w][i][j][o][u] += (d3[w2 % MOD][i - 1][j][o][u] + w2 - w) * ((double)i / (i + j + o + u));
						}
						if (j) {
							int w2 = ((w + 1) / 2) * 2 + 2;
							d3[w][i][j][o][u] += (d3[w2 % MOD][i][j - 1][o][u] + w2 - w) * ((double)j / (i + j + o + u));
						}
						if (o) {
							int w2 = ((w + 3) / 4) * 4 + 4;
							d3[w][i][j][o][u] += (d3[w2 % MOD][i][j][o - 1][u] + w2 - w) * ((double)o / (i + j + o + u));
						}
						if (u) {
							int w2 = ((w + 7) / 8) * 8 + 8;
							d3[w][i][j][o][u] += (d3[w2 % MOD][i][j][o][u - 1] + w2 - w) * ((double)u / (i + j + o + u));
						}
						
					}
				}
			}
		}
	}

	return d3[0][A][B][C][D];
}

void read() {
	scanf(" struct { ");
	char type[50];
	while (1) {
		type[0] = 0;
		scanf(" %[a-zA-Z64_}]", type);
		if (type[0] == '}') break;
		char t;
		scanf(" %c", &t);
		int val = -1;
		dbg(type);
		dbg(t);
		if (t == '*') {
			val = 8;
		} else {
			if (strcmp(type, "char") == 0) val = 1;
			else if (strcmp(type, "short") == 0) val = 2;
			else if (strcmp(type, "int") == 0) val = 4;
			else if (strcmp(type, "float") == 0) val = 4;
			else if (strcmp(type, "int64_t") == 0) val = 8;
			else if (strcmp(type, "double") == 0) val = 8;
			else assert(0);
		}
		assert(val != -1);
		q[val]++;
		scanf("%*[^;]");
		scanf(";");
	}
	dbg(q[1]);
	dbg(q[2]);
	dbg(q[4]);
	dbg(q[8]);

	if (q[8]) MOD = 8;
	else if (q[4]) MOD = 4;
	else if (q[2]) MOD = 2;
	else MOD = 1;

	vi v;
	v.pb(q[1]);
	v.pb(q[2]);
	v.pb(q[4]);
	v.pb(q[8]);

	A = v[0];
	B = v[1];
	C = v[2];
	D = v[3];

	ans1 = solve1();
	ans2 = solve2();
	ans3 = solve3();

	printf("%d %d ", ans1, ans2);
	cout << fixed << setprecision(15) << ans3 << endl;
}

int main() {
#ifdef LOCAL
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
	START_TIME = (double)clock();
#endif

	read();

	exit();
	return 0;
}