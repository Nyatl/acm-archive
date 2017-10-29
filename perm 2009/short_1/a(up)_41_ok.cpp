#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define pb push_back
#define mp make_pair
#ifdef _DEBUG
typedef long long ll;
#else
typedef __int128 ll;
#endif
typedef pair<ll, ll> pll;
////////////////

int const N = 1e5 + 41;

int n;
int c[N], f[N], d[N];
int g[N], e[N];

ll ADD;
multiset<pll> t;
ll q;
ll ans;

void bad(){
	printf("-1\n");
	exit(0);
}

void push(ll c, ll q1){
	q += q1;
	t.insert(mp(c - ADD, q1));
}

pll popmin(ll q1){
	pll res = (*t.begin());
	t.erase(t.find(res));
	if(res.second > q1){
		pll x = mp(res.first, res.second - q1);
		t.insert(x);
		res.second = q1;
	}
	return res;
}

pll popmax(ll q1){
	multiset<pll> :: iterator it = t.end();
	--it;
	pll res = (*it);
	t.erase(t.find(res));
	if(res.second > q1){
		pll y = mp(res.first, res.second - q1);
		t.insert(y);
		res.second = q1;
	}
	return res;
}

void remove(ll q1){
	q -= q1;
	while(q1){
		pll x = popmax(q1);
		q1 -= x.second;
	}
}

ll answer(ll q1){
	ll res = 0;
	q -= q1;
	while(q1){
		pll x = popmin(q1);
		q1 -= x.second;
		res += (x.first + ADD) * x.second;
	}
	return res;
}

void addall(ll x){
	ADD += x;
}

void solve(){
	fi(0, n){
		push(f[i], c[i]);
		if(q < d[i]) bad();
		ans += answer(d[i]);
		remove(max((ll)0, q - g[i]));
		addall(e[i]);
	}
}

#ifdef _DEBUG
#else
std::ostream&
operator<<(std::ostream& dest, __int128_t value)
{
	std::ostream::sentry s(dest);
	if (s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char* d = std::end(buffer);
		do
		{
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		if (value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}

#endif

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	fi(0, n){
		scanf("%d %d %d",&c[i],&f[i],&d[i]);
	}
	fi(0, n-1){
		scanf("%d %d",&g[i],&e[i]);
	}

	solve();

	cout << ans << endl;

	return 0;
}

