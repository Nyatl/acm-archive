#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <memory.h>
#include <assert.h>

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
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef set<pii> spii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<ll> sl;
typedef set<pll> spll;

char __buffer[100000];

#ifdef _DEBUG
#define LOCAL
#endif

#ifdef LOCAL
#define PRINT
#endif

// #undef PRINT

void err(const char *format, ... ) {
#ifdef PRINT
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
#ifdef PRINT
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
#ifdef PRINT	
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

#ifdef PRINT
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

#define MAX 11

int n;
int k = 6;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inside(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

struct Fig {
	char a[MAX][MAX];
	
	Fig() {
		fj(1, n) {
			fi(1, n) {
				a[j][i] = '.';
			}
		}
	}
	
	void rotate() {
		char a2[MAX][MAX];
		fj(1, n) {
			fi(1, n) {
				a2[j][i] = a[i][n - j + 1];
			}			
		}
		cpy(a, a2);
	}        
	
	void reflect() {
		char a2[MAX][MAX];
		fj(1, n) {
			fi(1, n) {
				a2[j][i] = a[j][n - i + 1];
			}			
		}
		cpy(a, a2);
	}
	
	void move(int dir) {
		fj(1, n) {
			fi(1, n) {
				if (a[j][i] == '.') continue;
				if (!inside(i + dx[dir], j + dy[dir])) return;
			}
		}
		char a2[MAX][MAX];
		fj(1, n) {
			fi(1, n) {
				a2[j][i] = '.';
			}
		}
		fj(1, n) {
			fi(1, n) {
				if(a[j][i] == '.') continue;
				a2[j + dy[dir]][i + dx[dir]] = a[j][i];
			}
		}
		cpy(a, a2);
	}
	
	void print() const {		
		fj(1, n) {
			fi(1, n) {
				err("%c", a[j][i]);
			}
			errln();
		}
		errln();
	}
	
	bool operator<(const Fig &f) const {
		fj(1, n) {
			fi(1, n) {
				if (a[j][i] != f.a[j][i]) return a[j][i] < f.a[j][i]; 
			}
		}
		return false;
	}
};

Fig f[7];
set<Fig> fs[7];

char image[MAX][MAX][MAX];

bool print(int x0, int y0, int z0, int dx1, int dy1, int dz1, int dx2, int dy2, int dz2, const Fig &f) {	
	fj(1, n) {
		fi(1, n) {
			int x = x0 + (i - 1) * dx1 + (j - 1) * dx2;
			int y = y0 + (i - 1) * dy1 + (j - 1) * dy2;
			int z = z0 + (i - 1) * dz1 + (j - 1) * dz2;
			if (f.a[j][i] != '.' && image[z][y][x] != '.') return false;  
		}
	}
	
	fj(1, n) {
		fi(1, n) {
			int x = x0 + (i - 1) * dx1 + (j - 1) * dx2;
			int y = y0 + (i - 1) * dy1 + (j - 1) * dy2;
			int z = z0 + (i - 1) * dz1 + (j - 1) * dz2;
			if (f.a[j][i] != '.') image[z][y][x] = f.a[j][i];  
		}
	}
	
	return true;
}

bool print(const Fig &f, int p) {
	if (p == 1) {
		return print(1, 1, 1, 1, 0, 0, 0, 1, 0, f);
	} else if (p == 1) {
		return print(1, 1, 1, 1, 0, 0, 0, 1, 0, f);
	} else if (p == 2) {
		return print(1, 1, 1, 1, 0, 0, 0, 0, 1, f);
	} else if (p == 3) {
		return print(1, n, 1, 0, -1, 0, 0, 0, 1, f);
	} else if (p == 4) {
		return print(1, n, 1, 1, 0, 0, 0, 0, 1, f);
	} else if (p == 5) {
		return print(n, n, 1, 0, -1, 0, 0, 0, 1, f);
	} else if (p == 6) {
		return print(1, 1, n, 1, 0, 0, 0, 1, 0, f);
	}
	return false;
}

void clear(int num) {
	fo(1, n) {
		fj(1, n) {
			fi(1, n) {
				if (image[o][j][i] == 'A' + num - 1) {
					image[o][j][i] = '.';
				}
			}
		}
	}
}

int u[MAX];

bool fun(int p) {
	if (p == k + 1) return true;
	dbg(p);
	fi(1, k) {
		if (u[i]) continue;
		u[i] = 1;
		
		for (auto &z : fs[i]) {
			if (print(z, p)) {
				//z.print();
				if (fun(p + 1)) return true;
				clear(i);
			}
		}
		
		u[i] = 0;
	}
	return false;
}

void solve() {
	
#ifdef LOCAL
	fun(1);
#else
	assert(fun(1));
#endif	
	
	fo(1, n) {
		fj(1, n) {
			fi(1, n) {
				printf("%c", image[o][j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void build() {
	fi(1, k) {
		fo(1, 8) {
			fj(1, n) {
				f[i].move(0);
				f[i].move(1);
			}
					
			fs[i].insert(f[i]);
			
			for (int x = 0; x <= n; x++) {
				for (int y = 0; y <= n; y++) {
					fj(1, n) {
						f[i].move(0);
						f[i].move(1);
					}
					fj(1, x) {
						f[i].move(2);
					}
					fj(1, y) {
						f[i].move(3);
					}
					fs[i].insert(f[i]);
				}
			}
			
			f[i].rotate();
			
			if (o % 4 == 0) {
				f[i].reflect();
			}
		}
	}
	
	fi(1, k) {
		for (auto z : fs[i]) {
			z.print();
		}
	}	
	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	START_TIME = (double)clock();
#endif

	scanf("%d", &n);

	fo(1, k) {
		fj(1, n) {
			scanf("%s", f[o].a[j] + 1);
		}
	}
	
	fj(1, n) {
		fi(1, n) {
			f[0].a[j][i] = '.';
		}
	}
	fo(1, n) {	
		fj(1, n) {
			fi(1, n) {
				image[o][j][i] = '.';
			}
		}
	}


	build();
		
	solve();
	
	exit();
	return 0;
}
