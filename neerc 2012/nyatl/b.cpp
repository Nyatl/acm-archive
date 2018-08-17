#include <bits/stdc++.h>

using namespace std;

#define fi(a, b) for (auto i = a; i <= b; i++)
#define fj(a, b) for (auto j = a; j <= b; j++)
#define fo(a, b) for (auto o = a; o <= b; o++)
#define fdi(a, b) for (auto i = a; i >= b; i--)
#define fdj(a, b) for (auto j = a; j >= b; j--)
#define fdo(a, b) for (auto o = a; o >= b; o--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back

template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> &v) {
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
#define dbg0(x, n) while(0){}
#define dbg1(x, n) while(0){}
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define MAX 1010

int n, c, w;

int get_next() {
    int res;
    scanf("%d", &res);
    return res;
}

int decline() {
    printf("decline\n");
    fflush(stdout);
    return get_next();
}

int accept() {
    printf("accept\n");
    fflush(stdout);
    return get_next();
}

int stop() {
    printf("stop\n");
    fflush(stdout);
    exit(0);
}

int k;
int W[MAX];
int ans;
ll anss;

void solve() {
    sort(W + 1, W + k + 1);
    anss = -1;
    fi(0, (1 << k) - 1) {
	ll sum = 0;
	fj(1, n) {
	    if ((1 << (j - 1)) & i) {
		sum += W[j];
	    }
	}
	if (sum > anss && sum <= c) {
	    anss = sum;
	    ans = i;
	}
    }	
}

int remove(int mask, int dif) {
    fdi(n, 1) {
	if (!((1 << (i - 1)) & mask)) continue;
	if (W[i] != dif) continue;
	return mask ^ (1 << (i - 1));
    }
    return -1;
}

int main() {
    int w2;
    scanf("%d %d %d", &n, &c, &w2);

    int cnt = 0;

    dbg("1");

    w = w2;

    if (w2 != 0) {
        w2 = accept();
    }
    
    while (w2 > 0) {
	if (w2 < w) {
	    w = w2;
	    w2 = accept();
	    cnt = 0;
	} else {
	    w2 = decline();
	    cnt++;
	}
    }

    if (w2 == 0) {
	w = w2;
	w2 = accept();
    }

    dbg("2");

    while (k < n) {
	if (w2 < w) {
	    w2 = decline();
	} else {
	    k++;
	    W[k] = w2 - w;
	    dbg(k);
	    w = w2;
	    if (k == n && w <= c) stop();
	    w2 = accept();
	}	
    }

    solve();
    int cur = (1 << k) - 1;
    dbg(ans);
    dbg(cur);

    while (1) {
	if (w2 < w) {
	    int cur2 = remove(cur, w - w2);
	    dbg(w - w2);
	    dbg(cur2);
	    if (cur2 != -1 && ((ans & cur2) == ans)) {
		cur = cur2;
		if (cur == ans) stop();
		w = w2;
		w2 = accept();
	    } else {
		w2 = decline();
	    }			
	} else {
	    w2 = decline();
	}
    }
    return 0;
}