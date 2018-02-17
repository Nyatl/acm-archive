#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<cassert>
#include<deque>
#include<numeric>
#include<functional>
#include<ctime>
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
///////////////////////

int const S = 5;

map<pll, ll> d;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
unsigned int st, en;
int n, m;
int sx, sy;
int fx, fy;
ll ans;

bool inbound(ll x, ll y){
	if(x < 0 || x >= n) return false;
	if(y < 0 || y >= m) return false;
	return true;
}

bool inside(int x, int y){
	if(!inbound(x, y)) return false;
	if( abs(x - fx) + abs(y - fy) > S ) return false;
	return true;
}

void bfs(){
	d[mp(fx, fy)] = 0;
	deque<pii> t;
	t.pb(mp(fx, fy));
	while(sz(t)){
		pii c = t.front();
		t.pop_front();
		fi(0, 8){
			int nx = c.first + dx[i];
			int ny = c.second + dy[i];
			if(!inside(nx, ny)) continue;
			if(d.find(mp(nx, ny)) != d.end()) continue;
			d[mp(nx, ny)] = 1 + d[c];
			t.pb(mp(nx, ny));
		}
	}
}

void solve(){
	bfs();
	if(d.find(mp(sx, sy)) != d.end()){
		ans = d[mp(sx, sy)];
		return;
	}
	ll a = abs(fx - sx);
	ll b = abs(fy - sy);
	if(b > a) swap(a, b);
	if(b * 2 > a){
		ll r = (2 * b - a + 2) / 3;
		a += r;
		b -= r;
	}
	ans = (a + 1) / 2;
	ll t = a / 2;
	if( (t - b) % 2 != 0) ++ans;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d %d",&n,&m);
	scanf("%d %d",&sx,&sy);
	scanf("%d %d",&fx,&fy);

	solve();

	printf("%lld\n",ans);

	return 0;
}