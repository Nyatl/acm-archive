#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define clr(x) memset(x, 0, sizeof(x))
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

#define TASK "knight"

#define MAX 55

int a, b, c, d;
vpii ans;

void print() {
	printf("NO\n");
	printf("%d\n", sz(ans));
	fi(0, sz(ans) - 1) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	exit(0);
}

int color[MAX][MAX];

int k;
int dx[4 * MAX * MAX];
int dy[4 * MAX * MAX];

int n, m;

bool inside(int x, int y) {
	if (x < 1 || x > n) return false;
	if (y < 1 || y > m) return false;
	return true;
}

bool bfs() {
	clr(color);
	queue<pii> qu;
	qu.push(mp(1, 1));
	color[1][1] = 1;
	while (sz(qu)) {
		pii p = qu.front();
		qu.pop();
		int x = p.first;
		int y = p.second;
		fi(1, k) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (!inside(x2, y2)) continue;
			if (color[y2][x2]) continue;
			qu.push(mp(x2, y2));
			color[y2][x2] = 1;
		}
	}
	fj(1, m) {
		fi(1, n) {
			if (!color[j][i]) return false;
		}
	}
	return true;
}

bool check() {
	int res = 0;
	
	n = a;
	m = b;

	res = bfs();
	if (!res) return false;

	fi(1, k) {
		dx[i] = -dx[i];
		dy[i] = -dy[i];
	}
	res = bfs();
	fi(1, k) {
		dx[i] = -dx[i];
		dy[i] = -dy[i];
	}
	if (!res) return false;

	n = c;
	m = d;

	res = bfs();
	if (!res) return true;

	fi(1, k) {
		dx[i] = -dx[i];
		dy[i] = -dy[i];
	}
	res = bfs();
	fi(1, k) {
		dx[i] = -dx[i];
		dy[i] = -dy[i];
	}
	if (!res) return true;

	return false;
}

void to_ans() {
	ans.clear();
	fi(1, k) {
		ans.pb(mp(dx[i], dy[i]));
	}
}

bool solve() {
	k = 0;
	if (check()) return true;

	k = 2;
	dx[1] = 0;
	dy[1] = 1;
	dx[2] = -dx[1];
	dy[2] = -dy[1];;
	if (check()) return true;

	k = 2;
	dx[1] = 1;
	dy[1] = 0;
	dx[2] = -dx[1];
	dy[2] = -dy[1];;
	if (check()) return true;

	k = 6;
	dx[1] = 0;
	dy[1] = 1;
	dx[2] = -dx[1];
	dy[2] = -dy[1];
	dx[3] = 1;
	dy[3] = b - 1;
	dx[4] = -dx[3];
	dy[4] = -dy[3];
	dx[5] = 1;
	dy[5] = -(b - 1);
	dx[6] = -dx[5];
	dy[6] = -dy[5];
	if (check()) return true;


	k = 6;
	dx[1] = 1;
	dy[1] = 0;
	dx[2] = -dx[1];
	dy[2] = -dy[1];
	dx[3] = a - 1;
	dy[3] = 1;
	dx[4] = -dx[3];
	dy[4] = -dy[3];
	dx[5] = -(a - 1);
	dy[5] = 1;
	dx[6] = -dx[5];
	dy[6] = -dy[5];
	if (check()) return true;

	k = 2;
	dx[1] = 1;
	dy[1] = 0;
	dx[2] = -(a - 1);
	dy[2] = 0;
	if (check()) return true;

	k = 3;
	dx[1] = -1;
	dy[1] = 0;
	dx[2] = 0;
	dy[2] = -1;
	dx[3] = a - 1;
	dy[3] = b - 1;
	if (check()) return true;

	return false;
}

int main() {
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (solve()) {
		to_ans();
		print();
	}
	swap(a, b);
	swap(c, d);
	if (solve()) {
		to_ans();
		for (auto &z : ans) {
			swap(z.first, z.second);
		}
		print();
	}
	printf("YES\n");
	return 0;
}