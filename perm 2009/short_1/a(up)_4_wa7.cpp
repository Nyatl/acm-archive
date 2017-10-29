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
typedef long long ll;
typedef pair<ll, ll> pll;
////////////////

int const N = 1e5 + 41;
int const MOD = 1e9;

int n;
ll suf[N];
int c[N], f[N], d[N], g[N], e[N];

struct Bignum{
	vector<ll> d;
	Bignum(){};
	
	Bignum(ll a){
		while(a){
			d.pb(a % MOD);
			a /= MOD;
		}
	}

	void relax(bool f = false){
		ll add = 0;
		fi(0, sz(d)){
			d[i] += add;
			add = d[i] / MOD;
			d[i] %= MOD;
		}
		while(add){
			d.pb(add % MOD);
			add /= MOD;
		}
		while(f && sz(d) && d.back() == 0) d.pop_back();
	}
	
	Bignum operator+(const Bignum &a) const{
		int l = max(sz(d), sz(a.d));
		Bignum res;
		res.d.assign(l, 0);
		fi(0, l){
			if(i < sz(d)) res.d[i] += d[i];
			if(i < sz(a.d)) res.d[i] += a.d[i];
		}
		res.relax();
		return res;
	};

	Bignum operator*(const Bignum &a) const{
		Bignum res;
		int l = sz(d) + sz(a.d);
		res.d.assign(l, 0);
		fi(0, sz(d)){
			fj(0, sz(a.d)){
				res.d[i+j] += d[i] * a.d[j];
				res.relax();
			}
		}
		return res;
	};

	void print(){
		if(sz(d) == 0){
			printf("0");
			return;
		}
		bool f = true;
		fdi(sz(d), 0){
			if(f){
				printf("%d",(int)d[i]);
			}else{
				printf("%09d",(int)d[i]);
			}
			f = false;
		}
	}
};

Bignum ans;
multiset<pll> t;
ll q;

void bad(){
	printf("-1\n");
	exit(0);
}

pll popmin(){
	pll res = (*t.begin());
	t.erase(res);
	return res;
}

pll popmax(){
	multiset<pll> :: iterator it = t.end();
	--it;
	pll res = *it;
	t.erase(res);
	return res;
}

void solve(){
	fdi(n, 0){
		suf[i] = suf[i+1] + e[i];
	}
	ans = Bignum(0);
	fi(0, n){
		t.insert(mp(suf[i] + f[i], c[i]));
		q += c[i];
		ll rem = d[i];
		if(rem > q) bad();
		while(rem){
			pll x = popmin();
			ll take = min(x.second, rem);
			Bignum a = Bignum(take);
			Bignum b = Bignum(x.first - suf[i]);
			Bignum add = a * b;
			ans = ans + add;
			rem -= take;
			x.second -= take;
			q -= take;
			if(x.second) t.insert(x);
		}
		while(q > g[i]){
			pll y = popmax();
			ll take = min(y.second, q - g[i]);
			y.second -= take;
			q -= take;
			if(y.second) t.insert(y);
		}
	}
	ans.relax(true);
}

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

	ans.print();

	return 0;
}

