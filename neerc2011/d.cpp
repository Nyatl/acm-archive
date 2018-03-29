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

template<class T> bool uin(T &a, T b){ return (a > b ? a = b, true : false); }
template<class T> bool uax(T &a, T b){ return (a < b ? a = b, true : false); }

/////////////////////////////////

int const MAXK = 26;

int n;
vector<string> vs, ivs;
int have[MAXK];
int qs[MAXK];
int qc[MAXK];

void proceed(vector<string> &v) {
	vector<string> tmp;
	fi(0, sz(v) - 1) {
		while(sz(tmp)) {
			int n = sz(tmp.back());
			if (sz(v[i]) < n) break;
			if (v[i].substr(0, n) == tmp.back()) {
				tmp.pop_back();
			} else {
				break;
			}
		}
		tmp.pb(v[i]);
	}
	v = tmp;
}

int getlcp(string &a, string &b) {
	int n = min(sz(a), sz(b));
	fi(0, n - 1) {
		if (a[i] != b[i]) {
			return i;
		}
	}
	return n;
}

void solve() {
 	fi(0, n - 1) {
		if (sz(vs[i]) == 1) {
			qc[vs[i][0] - 'a'] = 1;	
		}
		have[vs[i].back() - 'a'] = 1;
	}	
	fi(0, n - 1) {
		string tmp = vs[i];
		reverse(tmp.begin(), tmp.end());
		ivs.pb(tmp);
	}
	sort(vs.begin(), vs.end());
	sort(ivs.begin(), ivs.end());
	proceed(vs);
	proceed(ivs);
	/*
	for(string z : vs) {
		err("%s\n", z.c_str());
	}
	err("\n");
	*/
	fi(0, sz(ivs) - 1) {
		int lcp = 0;
		if (i) {
			lcp = getlcp(ivs[i - 1], ivs[i]);
		}
		fj(lcp, sz(ivs[i]) - 1) {
			qs[ivs[i][j] - 'a']++;
		}
	}	
	/*
	fi(0, MAXK - 1) {
		err("qs[%c] = %d\n", (char)(i + 'a'), qs[i]);
	}
	*/
	ll all = 0;
	ll ans = 0;
	fi(0, MAXK - 1) {
		all += qs[i];
	}
	fi(0, MAXK - 1) {
		ans += qc[i];
	}
	fi(0, sz(vs) - 1) {
		int lcp = 0;
		if (i) {
			lcp = getlcp(vs[i - 1], vs[i]);
		}				
		ll cur = 0;
		fj(lcp, sz(vs[i]) - 1) {
			cur += all;
			if (j + 1 < sz(vs[i])) {
				int c = vs[i][j + 1] - 'a';
				cur -= qs[c];
				cur += have[c];
			}			
		}
		if (lcp) {
			cur -= qs[vs[i][lcp] - 'a'];
			cur += have[vs[i][lcp] - 'a'];
		}
		ans += cur;
//		err("string = %s lcp = %d cur = %lld\n", vs[i].c_str(), lcp, cur);
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	fi(0, n - 1) {
		string s;
		cin >> s;
		vs.pb(s);
	}
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}