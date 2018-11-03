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

const int MAX = 300005;

set<int> t;
int n;

int a[MAX];

void init() {
	fi(1, 300000) {
		t.insert(i);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	scanf("%d", &n);
	int c = 1;
	fi(1, n) {
		char tmp;
		scanf(" %c", &tmp);
		if (tmp == 'C') {
			int ans = *t.begin();
			t.erase(t.begin());
			a[c++] = ans;
			printf("%d\n", ans);
		} else if (tmp == 'T') {
			int x;
			scanf("%d", &x);
			t.insert(a[x]);
		} else {
			assert(false);
		}
	}
	return 0;
}
