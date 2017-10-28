#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<deque>
#include<algorithm>
#include<ctime>
#include<memory>
#include<memory.h>

using namespace std;

#define sz(a) int((a).size())

#define fi(a, b) for(int i = (a); i < (b); ++i)
#define fj(a, b) for(int j = (a); j < (b); ++j)
#define fk(a, b) for(int k = (a); k < (b); ++k)
typedef long long ll;
#define all(a) (a).begin(),(a).end()
#define _(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

string const INFS = "INFINITY";
ll const INF = 9e18;
int const N = 2e5 + 41;

int n, q, ansInf[N], fpos;
ll ans[N];


struct Balance{
	ll l, r;
	ll bal;
	Balance(ll l, ll r, ll bal) : l(l), r(r), bal(bal) {};
	Balance(){};
	bool operator<(const Balance &a) const{
		if (bal != a.bal){
			return a.bal < bal;
		}
		return (mp(l, r) < mp(a.l, a.r));
	};
};

set <Balance> setb;

struct Query{
	ll id;
	ll start;
	Query(ll id, ll start) : id(id), start(start) {};
	Query(){};
	bool operator<(const Query &a) const{
		return start < a.start;
	};
};

bool compQid(Query &a, Query &b){
	return a.id < b.id;
}

struct Event{
	ll time, add;
	Event(ll time, ll add) : time(time), add(add) {};
	Event(){};
	bool operator<(const Event &a) const{
		return time < a.time;
	};
};

vector<Query> queries;
vector<Event> events;

ll brute(ll start){
	int const L = 100;
	ll bal[L];
	ll ret = 0;
	memset(bal, 0, sizeof(bal));
	bal[0] = start;
	fi(0, sz(events)){
		int t = events[i].time;
		int a = events[i].add;
		bal[t] += a;
	}
	fi(1, L){
		bal[i] += bal[i - 1];
	}

	fi(0, L){
		ll add = -bal[i];
		ret += max(0LL, add);
	}
	
	if (bal[L - 1] < 0){
		return INF;
	}
	
	return ret;
}

void read() {
	scanf("%d %d\n", &n, &q);
	fi(0, n){
		char type;
		int ti, vi;
		scanf("%c %d %d\n", &type, &ti, &vi);
		if (type == '-'){
			vi = -vi;
		}
		events.pb(Event(ti, vi));
	}
	events.push_back(Event(0, 0));
	sort(events.begin(), events.end());
	fi(0, q){
		int vi;
		scanf("%d", &vi);
		queries.pb(Query(i, vi));
	}
	sort(queries.begin(), queries.end());
}

int findInfs(){
	ll cur = 0; 
	fi(0, sz(events)){
		cur += events[i].add;
	}
	int fpos = 0;
	fi(0, sz(queries)){
		if (cur + queries[i].start < 0){
			ansInf[queries[i].id] = 1;
			++fpos;
		}
		else{
			break;
		}
	}
	return fpos;
}

void print(){
	sort(queries.begin(), queries.end(), compQid);
	fi(0, q){
		int id = queries[i].id;
		if (ansInf[id] == 1){
			printf("INFINITY\n");
		}
		else{
			printf("%lld\n", ans[id]);
		}
	}
}

void solve() {
	int pos = findInfs();
	if (pos == sz(queries)){
		print();
		return;//all infs
	}
	ll addZero = queries[pos].start;
	events[0].add += addZero;
	ll cur = 0;
	ll answer = 0;

	fi(0, sz(queries)){
		queries[i].start -= addZero;
	}


	ll sumLen = 0;
	fi(1, sz(events)){
		cur += events[i - 1].add;
		if (cur < 0){
			Balance b = Balance(events[i - 1].time, events[i].time, cur);
			setb.insert(b);
			answer += (b.r - b.l) * b.bal;
			sumLen += (b.r - b.l);
		}
	}

	answer = -answer;

	ans[queries[pos].id] = answer;

	fi(pos + 1, sz(queries)){
		ll dans = (queries[i].start - queries[i - 1].start); 
		answer -= dans * sumLen;
		while (sz(setb) > 0){
			ll sVal = queries[i].start;
			Balance b = (*setb.begin());
			if (-b.bal > sVal){
				break;
			}
			else{
				setb.erase(setb.begin());
				answer += (sVal - (- b.bal)) * (b.r - b.l);
				sumLen -= b.r - b.l;
			}
		}
		ans[queries[i].id] = answer;
	}


	print();
}



#define FILENAME "expect"

void prepare() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
}

int main() {
	prepare();
	read();
	solve();
	return 0;
}