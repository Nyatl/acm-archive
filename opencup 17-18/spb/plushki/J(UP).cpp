#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
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
typedef pair<ll, ll> pll;
///////////////////

int const N = 2e5 + 41;
#ifdef _DEBUG
int const INF = 41;
#else
int const INF = 2e9 + 41;
#endif

int L, R;
ll lp, rp;
int a[N], b[N], ans[N];
int n;
int cnt;

int getleq(int v){
	int ret = 0;
	int l = -1;
	int r = n;
	while(r-l>1){
		int m = (l+r)/2;
		if(b[m] <= v) l = m;
		else r = m;
	}
	return l + 1;
}

ll getrightpos(int v){
	ll ret = 0;
	fi(0, n){
		int rm = v - a[i];
		ret += getleq(rm);
	}

	return ret;
}

int findval(ll p){
	ll l = -1;
	ll r = INF;
	while(r-l>1){
		ll m = (l+r)/2;
		if(getrightpos((int)m) >= p) r = m;
		else l = m;
	}
	return (int)r;
}

void solve(){
	lp = n * 1LL * (n - 1) / 2 + 1;
	rp = n * 1LL * (n + 1) / 2;
	sort(a, a+n);
	sort(b, b+n);
	L = findval(lp);
	R = findval(rp);
#ifdef _DEBUG
	printf("%d %d\n",L,R);
#endif
	if(L == R){
		fi(0, n) ans[i] = L;
		return;
	}
	ll leftpos = getrightpos(L);
	int cntl = (int)(leftpos - lp + 1);
	while(cntl-- > 0){
		ans[cnt++] = L;
	}
	fi(0, n){
		int v = L - a[i];
		int p = getleq(v);
		while(cnt < n && p < n && a[i] + b[p] < R){
			ans[cnt++] = a[i] + b[p];
			++p;
		}
	}

	ll rightpos = getrightpos(R-1);
	int cntr = (int)(rp - rightpos);
	while(cntr-- > 0){
		ans[cnt++] = R;
	}
	sort(ans, ans+n);
	assert(cnt == n);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	fi(0, n){
		scanf("%d",&a[i]);
	}
	fi(0, n){
		scanf("%d",&b[i]);
	}

	solve();

	fi(0, n) printf("%d ",ans[i]);
	printf("\n");

	return 0;
}