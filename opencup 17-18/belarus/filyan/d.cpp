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

int const MAX = 201;

int n, m;
int edge[MAX][MAX];

namespace Dsu {
	int par[MAX];

	void init() {
		fi(0, MAX - 1) {
			par[i] = i;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	
	bool uni(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		par[b] = a;
		return true;
	}

};

//COMPS

struct Comp {
	vi nodes;
	set<pii> edges;
	Comp () {};

	int getmask() {
		int res = sz(nodes) % 2 + (sz(edges) % 2) * 2;
		return res;
	}
};

Comp c[MAX];
bool f[MAX];

pii getedge(int x, int y) {
	return mp(min(x, y), max(x, y));
}

void addedge(int x, int y) {
	int px = Dsu::find(x);
	int py = Dsu::find(y);
	if (px == py) {
		c[px].edges.erase(getedge(x, y));				
	}	else {
		for (int a : c[px].nodes) {
			for (int b : c[py].nodes) {
				if (a == x && b == y) continue;
				c[px].edges.insert(getedge(a, b));				
			}
		}
		c[px].nodes.insert(c[px].nodes.end(), c[py].nodes.begin(), c[py].nodes.end());
		c[px].edges.insert(c[py].edges.begin(), c[py].edges.end());
		Dsu::uni(px, py);
		f[py] = 0;
	}
}

//END COMPS

int mem[4][4];
int ver[4];
int edg[4];

void initmem() {
	fi(0, 3) {
		ver[i] = (i & 1);
		edg[i] = ((i & 2) ? 1 : 0);
	}
	fi(0, 3) {
		fj(0, 3) {
			int nv = (ver[i] + ver[j]) % 2;
			int ne = (edg[i] + edg[j] + ver[i] * ver[j] - 1) % 2;
			if (ne < 0) ne += 2;
			mem[i][j] = nv + ne * 2;						
		}
	}
}

//STATE

int const BASE = 210;

int pbase[4] = {1, BASE, BASE * BASE, BASE * BASE * BASE};

int getq(int mask, int i) {
	return mask / pbase[i] % BASE;
}

int inc(int mask, int i) {
	return mask + pbase[i];
}

int dec(int mask, int i) {
	return mask - pbase[i];
}

int getcurrentstate() {
	int res = 0;
	fi(1, n) {
		int p = Dsu::find(i);
		if (f[p] && p == i) { 
			res = inc(res, c[p].getmask());
		}
	}
	return res;
}

unordered_map<int, int> d;
unordered_map<int, pii> dm;

bool endstate(int mask) {
	int sum = 0;
	fi(0, 3) {
		sum += getq(mask, i);
	}
	return (sum == 1);
}

//

void printstate(int mask) {
	err("{state = %d}", mask);
	fi(0, 3) {
		err("{%d:%d} ", i, getq(mask, i));
	}
	err("\n");
}

//

int rec(int st) {
	if (endstate(st)) return 0;
	if (d.find(st) != d.end()) return d[st];
	int res = 0;
	pii bm = mp(-1, -1);
	fi(0, 3) {
		if (res) break;
		if (!getq(st, i)) continue;
		fj(0, 3) {
			if (i != j || (getq(st, i) > 1)) {
				if (getq(st, j)) {
					int nst = st;
					nst = dec(nst, i);
					nst = dec(nst, j);
					nst = inc(nst, mem[i][j]);
					if (!rec(nst)) {
						res = 1;
						bm = mp(i, j);
						break;
					}
				}
			}
		}
	}	
	if (!res && getq(st, 2)) {
		int nst = dec(st, 2);
		nst = inc(nst, 0);
		if (!rec(nst)) {
			res = 1;
			bm = mp(-1, 2);
		}
	}
	if (!res && getq(st, 3)) {
		int nst = dec(st, 3);
		nst = inc(nst, 1);
		if (!rec(nst)) {
			res = 1;
			bm = mp(-1, 3);
		}
	}
	d[st] = res;
	dm[st] = bm;
	/*
	printstate(st);
	err(" res = %d move = %d %d\n", res, bm.first, bm.second);
	*/
	return res;
}

void MLE() {
	while (1) {
		double a[1234567];
	}
}

pii findedge(int m1, int m2) {
	if (m1 == -1) {
		fi(1, n) {
			if (!f[i]) continue;
			if (c[i].getmask() == m2) {
				if (sz(c[i].edges)) {
					pii res = *c[i].edges.begin();
					return res;
				}
			}
		}
	}	else {
		fi(1, n) {
			if (!f[i]) continue;
			if (c[i].getmask() != m1) continue;
			fj(1, n) {
				if (i == j) continue;
				if (!f[j]) continue;
				if (c[j].getmask() != m2) continue;
				pii res = getedge(c[j].nodes.back(), c[i].nodes.back());
				return res;
			}
		}
	}
	return mp(-1, -1);
}

void query(int x, int y) {
	printf("%d %d\n", x, y);
	fflush(stdout);
}

pii read() {
	pii res;
	scanf("%d %d", &res.first, &res.second);
	return res;
}

void solve() {
	initmem();
	Dsu::init();
	fi(1, n) {
		f[i] = 1;
		c[i].nodes.pb(i);
	}
	fi(1, n) {
		fj(i + 1, n) {
			if (edge[i][j]) {
				addedge(i, j);
			}
		}
	}
	int cur = getcurrentstate();		
	if (endstate(cur)) {
		printf("1\n");
		fflush(stdout);
		exit(0);
	}
	if (rec(cur)) {		
		printf("1\n");
		fflush(stdout);
		/*
		return;
		*/
		pii e = findedge(dm[cur].first, dm[cur].second);
		query(e.first, e.second);
		cur = getcurrentstate();
		if (endstate(cur)) {
			exit(0);
		}
		addedge(e.first, e.second);
	} else {
		printf("2\n");		
		fflush(stdout);
		/*
		return;
		*/
	}
	while (1) {
		if (endstate(getcurrentstate())) {
			exit(0);
		}
		pii e = read();
		if (e.first == 0 && e.second == 0) {
			exit(0);
		}		
		addedge(e.first, e.second);
		int st = getcurrentstate();
		if (!rec(st)) {
			pii e1 = findedge(-1, 0);
			if (e1.first != -1) {
				query(e1.first, e1.second);
				addedge(e1.first, e1.second);
				continue;
			}
			e1 = findedge(-1, 1);
			if (e1.first != -1) {
				query(e1.first, e1.second);
				addedge(e1.first, e1.second);
				continue;				
			}
			MLE();
		} else {
			pii e1 = findedge(dm[st].first, dm[st].second);
			if (e1.first == -1) {
				MLE();
			}
			query(e1.first, e1.second);
			addedge(e1.first, e1.second);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &m);
	fi(1, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x][y] = edge[y][x] = 1;
	}
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}