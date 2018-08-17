#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back

template<typename T>
ostream& operator<<(const ostream& os, const vector<T> &v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << "\t" << #x << ": " << x << endl
#define dbg0(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 0; ABC < n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << "\t" << #x << ": "; for(int ABC = 1; ABC <= n; ABC++) {cerr << x[ABC] << " ";} cerr << endl;}
#else
#define dbg(x) while(0){}
#define dbg0(x) while(0){}
#define dbg1(x) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define TASK "turtles"

const int MAX = 200'005;

struct Node {
	Node *p;
	int c;
	int q;
	Node(int c) {
		q = 1;
		this->c = c;
		p = this;
	}
};

map<pii, int> num;

int K;

Node* node[MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

Node* find(Node *x) {
	if (x->p == x) return x;
	return x->p = find(x->p);
}

void unite(Node *x, Node *y) {
	Node *a = find(x);
	Node *b = find(y);
	if (a == b) return;
	a->q += b->q;
	b->p = a;
}

set<int> hor[MAX];
set<int> ver[MAX];
int Q;

void add_to_sets(pii p) {
	int x = p.first;
	int y = p.second;
	int before = -1, after = -1;
	if (!sz(hor[y]) || sz(hor[y]) == *hor[y].rbegin() - *hor[y].begin() + 1) {
		before = 0;
	} else {
		before = 1;
	}

	hor[y].insert(x);

	if (!sz(hor[y]) || sz(hor[y]) == *hor[y].rbegin() - *hor[y].begin() + 1) {
		after = 0;
	} else {
		after = 1;
	}
	Q += after - before;

	if (!sz(ver[x]) || sz(ver[x]) == *ver[x].rbegin() - *ver[x].begin() + 1) {
		before = 0;
	} else {
		before = 1;
	}

	ver[x].insert(y);

	if (!sz(ver[x]) || sz(ver[x]) == *ver[x].rbegin() - *ver[x].begin() + 1) {
		after = 0;
	} else {
		after = 1;
	}

	Q += after - before;

	dbg(Q);
}

int add(pii p) {
	K++;
	num[p] = K;
	node[K] = new Node(K);
	fi(0, 3) {
		pii p2 = mp(p.first + dx[i], p.second + dy[i]);
		if (!num.count(p2)) continue;
		unite(node[num[p]], node[num[p2]]);
	}
	add_to_sets(p);
	return find(node[1])->q == K;
}

int h, w;
int n, k;

int x[MAX];
int y[MAX];
int xt[MAX];
int yt[MAX];

bool check() {
	return Q == 0;
}

void solve() {
	int con = 0;
	fi(1, n) {
		con = add(mp(x[i], y[i]));
	}
	if (con && check()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	fi(1, k) {
		con = add(mp(xt[i], yt[i]));
		if (con && check()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d %d", &h, &w);
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d %d", &x[i], &y[i]);
	}
	scanf("%d", &k);
	fi(1, k) {
		scanf("%d %d", &xt[i], &yt[i]);
	}
	solve();
	return 0;
}