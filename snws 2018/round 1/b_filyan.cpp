#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cstring>
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
typedef vector<int> vi;
typedef long double ld;
///////////////////////////

int const N = 141;
ld const INF = 1e9 + 41;

int n;
ld a[N];
ld ans;

void solve(){
	int id = -1;
	fi(0, n){
		if(a[i] >= 30.0 && a[i] <= 30.2){
			id = i;
			break;
		}
	}
	if(id == -1){
		ans = 0;
		return;
	}
	int q = n - id;
	if(q < 3){
		ans = 0;
		return;
	}
	ans = INF;
	fi(id+3, n){
		//ld d = max(a[i] - 30.0, (a[i] - 30.0));
		ld d = a[i] - 30.0;
		ans = min(ans, d);
	}
}

int main(){
//#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//#endif

	int t;

	cin >> t;
	fo(0, t){
		cin >> n;
		fi(0, n) cin >> a[i];
		solve();
		printf("%.2Lf\n",ans);
	}

	return 0;
}