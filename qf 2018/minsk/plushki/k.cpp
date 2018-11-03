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

typedef long long ll;

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


#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif

int n;
char tmp1[41];
char tmp2[41];

void solve() {
	scanf("%d", &n);
	double cur = 1.;
	lll C = 0;
	fi(1, n) {
		scanf(" ");
		scanf("%[ a-z]", tmp1);
		string s = tmp1;
		int d;
		int f = scanf("%d", &d) == 1;
		if (!f) scanf("?");
		dbg(d);
		if (s == "multiply by ") {
			assert(f);
			cur *= d;
			C *= d;
		}
		if (s == "add ") {
			if (!f) {
				cur += 1.;
			} else {
				C += d;
			}
		}
		if (s == "subtract ") {
			if (!f) {
				cur -= 1.;
			} else {
				C -= d;
			}
		}
		dbg(cur);
		dbg(C);
	}
	
	dbg(cur);
	dbg(C);
	
	if (fabs(cur) < 1e-9) {
		// print C;
		if (C == 0) {
			printf("0\n");
			return;
		}
		string s;
		bool f = false;
		if (C < 0) {
			f = true;
			C = -C;
		}
		while (C) {
			s += (char)('0' + (C % 10));
			C /= 10;
		}
		reverse(all(s));
		if (f) {
			s = "-" + s;
		}
		printf("%s", s.c_str());
		//printf("%lld\n", C);
	} else {
		printf("Epic fail\n");
	}
	
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}
