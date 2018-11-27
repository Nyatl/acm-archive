#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#ifndef LOCAL
typedef __int128 lll;
#else
typedef long long lll;
#endif


template<typename T>
ostream& operator<<(ostream& s, vector<T> v) {
	for (T z : v) s << z << " ";
	return s;
}

template<typename T>
ostream& operator<<(ostream& s, deque<T> v) {
	for (T z : v) s << z << " ";
	return s;
}


template<typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2> v) {
	s << v.first << " " << v.second;
	return s;
}

#define sz(a) (int)((a).size())
#define fi(a,b) for(int i = (a); i <= (b); ++i)
#define fj(a,b) for(int j = (a); j <= (b); ++j)
#define fo(a,b) for(int o = (a); o <= (b); ++o)
#define fdi(a,b) for(int i = (a); i >= (b); --i)
#define fdj(a,b) for(int j = (a); j >= (b); --j)
#define fdo(a,b) for(int o = (a); o >= (b); --o)
#define all(a) (a).begin(),(a).end()

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << '\t' << #x << ":" << x << endl
#define dbg0(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=0; ABC<n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#define dbg1(x, n) {cerr << __LINE__ << '\t' << #x << ":";for(int ABC=1; ABC<=n;ABC++) cerr << x[ABC] << " "; cerr << endl;}
#else
#define dbg(x) while(false) {}
#define dbg0(x, n) while(false) {}
#define dbg1(x, n) while(false) {}
#endif 

const int MAX = 20;

char t[20];

int isA(string & s) {
	if (sz(s) == 1) {
		return 1;
	}
	if (sz(s) == 2) {
		return s[0] != '0';
	}
	if (sz(s) == 3) {
		if (s[0] == '1') {
			return 1;
		}
		if (s[0] == '2') {
			if (s[1] >= '6') {
				return 0;
			}
			if (s[1] == '5') {
				return s[2] <= '5';
			}
			return 1;
		}
		return 0;
	}
	return 0;
}

string s;

void process(int al, int bl, int cl, int dl) {
	if (dl < 1 || dl > 3) return;
	string a = s.substr(0, al);
	string b = s.substr(al, bl);
	string c = s.substr(al + bl, cl);
	string d = s.substr(al + bl + cl);
	if (isA(a) && isA(b) && isA(c) && isA(d)) {
		printf("%s.%s.%s.%s\n", a.c_str(), b.c_str(), c.c_str(), d.c_str());
	}
}

void solve() {
	scanf("%s", t);
	s = t;
	dbg(s);
	fi(1, 3) {
		fj(1, 3) {
			fo(1, 3) {
				process(i, j, o, sz(s) - i - j - o);
			}
		}
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