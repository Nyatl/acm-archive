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

bool check(string s) {
	if (sz(s) != 9) return false;
	if (s[4] != ' ') return false;
	if (s[1] != 'T') return false;
	if (s[3] != 'X') return false;
	if (s[0] < '1' || s[0] > '7') return false;
	if (s[0] == '7') {
		if (s[2] != 'A' && s[2] != 'E' && s[2] != 'B' ) return false;
	} else {
		if (s[2] != 'A' && s[2] != 'B') return false;
	}
	if ('0' > s[5] || s[5] > '9') return false;
	if ('0' > s[6] || s[6] > '9') return false;
	if ('0' > s[7] || s[7] > '9') return false;
	if ('0' > s[8] || s[8] > '9') return false;
	if (s[5] == '0' && s[6] == '0' && s[7] == '0' && s[8] == '0') return false;
	return true;
}

int n, ans;

char buff[500];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%*[\r\n]");
	fi(1, n) {
		scanf("%[^\r\n]", buff);
		scanf("%*[\r\n]");
		if (check(buff)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
