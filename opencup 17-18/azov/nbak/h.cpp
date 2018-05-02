#include <iostream>

#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <memory>
#include <memory.h>
#include <iomanip>
#include <functional>
#include <cassert>
#include <climits>
#include <cstdio>
#include <ctime>



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

const int MAX = 100000 + 5;
const int INF = 2 * 1000 * 1000000 + 5;
int n;
int k;
int Q;

int t[MAX];
int s[MAX];
int b[MAX];
int q[MAX];

const int QUE = 1, ADD = 0, REM = 2;

struct Event {
	int t;
	int type;
	int id;
	Event() {}
	Event(int t, int type, int id) : t(t), type(type), id(id) {}
	bool operator<(const Event & e) const {
		if (t != e.t) {
			return t < e.t;
		}
		if (type != e.type) {
			return type < e.type;
		}
		return id < e.id;
	}
};

ostream& operator<<(ostream& s, const Event & e) {
	s << e.t << " " << (e.type == 2 ? "rem" : e.type == 0 ? "add" : "que") << " " << e.id;
	return s;
}


vector<Event> events;

int ans[MAX];

void solve() {
	s[k + 1] = INF;
	fi(1, k) {
		if (b[i] > n) continue;
		
		int beg = s[i];
		int en = s[i + 1];
		int ok = t[b[i]];
		int tRem = ok - beg;
		int tAdd = ok - en + 1;
		dbg(Event(tAdd, ADD, i));
		dbg(Event(tRem, REM, i));
		events.pb(Event(tAdd, ADD, i));
		events.pb(Event(tRem, REM, i));
	}
	fi(1, Q) {
		events.pb(Event(q[i], QUE, i));
	}
	sort(all(events));
	dbg(events);
	int bal = 0;
	fi(0, sz(events) - 1) {
		switch(events[i].type) {
			case QUE:
				ans[events[i].id] = bal;
				break;
			case ADD:
				bal++;
				break;
			case REM:
				bal--;
				break;
			default:
				break;
		}
	}
	assert(bal == 0);
	fi(1, Q) {
		printf("%d ", ans[i]);
	}

}


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &t[i]);
	}
	scanf("%d", &k);
	fi(1, k) {
		scanf("%d%d", &s[i], &b[i]);
	}
	scanf("%d", &Q);
	fi(1, Q) {
		scanf("%d", &q[i]);
	}
	solve();
	return 0;
}