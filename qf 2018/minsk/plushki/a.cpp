#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define fi(a, b) for (int i = a; i <= b; i++) 
#define fj(a, b) for (int j = a; j <= b; j++) 
#define fo(a, b) for (int o = a; o <= b; o++)
#define fdi(a, b) for (int i = a; i >= b; i--) 
#define fdj(a, b) for (int j = a; j >= b; j--) 
#define fdo(a, b) for (int o = a; o >= b; o--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

template<typename A, typename B>
ostream& operator<<(ostream &s, pair<A, B> v) {
	s << "(" << v.first << ", " << v.second << ")" << endl;
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, vector<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}

template<typename T>
ostream& operator<<(ostream &s, set<T> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}
/*
template<typename A, typename B>
ostream& operator<<(ostream &s, map<A, B> v) {
	for (auto z : v) {
		s << z;
	}
	return s;
}*/

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << x << endl;}
#else
#define err(...) while (0) {}
#define dbg(x) while (0) {}
#endif 

//////////////////////

int n;
int K[30], W[30];

vector<vector<int>> ans;

void minus1(int x) {
	vector<int> res;
	fi(1, n) {
		if (i == x) {
			res.pb(-1);
		} else {
			res.pb(0);
		}
	}
	ans.pb(res);
}

void plus1(int x) {
	vector<int> res;
	bool f = true;
	fi(1, n) {
		if (i != x && f) {
			res.pb(x);
			f = false;
		} else {
			res.pb(0);
		}
	}
	ans.pb(res);
}

void suicide(int x) {
	vector<int> res;
	fi(1, n) {
		if (i == x) {
			res.pb(x);
		} else {
			res.pb(0);
		}
	}
	ans.pb(res);
}

void print() {
	printf("%d\n", sz(ans));
	for (auto &v : ans) {
		for (int z : v) {
			printf("%d ", z);
		}
		printf("\n");
	}
}

void solve() {
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d %d", &K[i], &W[i]);
	}
	fi(1, n) {
		fj(1, W[i]) {
			minus1(i);
		}
	}
	fi(1, n) {
		fj(1, K[i]) {
			plus1(i);
		}
	}
	fi(1, n) {
		fj(K[i], -1) {
			suicide(i);
		}
	}
	print();
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
	