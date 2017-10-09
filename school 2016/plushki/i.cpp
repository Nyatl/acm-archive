#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cassert>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
//////////////////////

int const N = 1e8 + 41;
int const MV = 510510;

int l[N];
ll x;
ll ans = -1;
vector<int> pr;

int getDiv(int x){
	int ret = 1;
	while(x > 1){
		int k = l[x];
		int d = 0;
		while(x % k == 0){
			++d;
			x /= k;
		}
		ret *= (d+1);
	}
	return ret;
}

void sieve(){
	fi(2, N){
		if(!l[i]){
			l[i] = i;
			pr.pb(i);
		}
		for(int j=0;j<sz(pr) && pr[j] * 1LL * i < N && l[i] >= pr[j];++j){
			int v = pr[j] * i;
			if(l[v] == 0 || l[v] > pr[j]) l[v] = pr[j];
		}
	}
}

void solve(){
	sieve();
	ll y = x + x / 100;
	if(y < N){
		fi(x, y+1){
			if(getDiv(i) >= 100){
				ans = i;
				return;
			}
		}
	}else{
		ans = (y / MV) * MV;
	}
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%lld",&x);

	solve();
	
	printf("%lld\n",ans);

	return 0;
}