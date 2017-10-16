#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
////////////////////////

//16072

int const N = 1e3 + 41;
ll const INF = 1e13 + 41;

vector<int> e[N];
int l[N], a[N];
int w[N];
int n;
ll ans;

bool cmpp(pll a, pll b){
        return a.first - a.second > b.first - b.second;
}

bool cmpn(pll a, pll b){
        //return a.first + a.second > b.first + b.second;
        return a < b;
}

pii dfs(int u, int p){
        if(u == 2){
                int asd = 1;
        }
        if(w[u]){
                ll a = max(l[u], l[u] - ::a[u] + l[u]);
                ll b = l[u] * 2 - ::a[u];
                return mp(a, b);
        }

        vector<pll> v, vn, vp;
        fi(0, sz(e[u])){
                int to = e[u][i];
                if(to == p) continue;
                pll cur = dfs(to, u);
                v.pb(cur);
        }

        fi(0, sz(v)){
                if(v[i].second < 0) vn.pb(v[i]);
                else vp.pb(v[i]);
        }

        ll s = l[u], a = 0;

        sort(vn.begin(), vn.end(), cmpn);
        fi(0, sz(vn)){
                a = max(a, s + vn[i].first);
                s += vn[i].second;
        }

        sort(vp.begin(), vp.end(), cmpp);
        fi(0, sz(vp)){
                a = max(a, s + vp[i].first);
                s += vp[i].second;
        }

        s += l[u];
        a = max(a, s);

        ll b = l[u] * 2;
        fi(0, sz(v)) b += v[i].second;

        return mp(a, b);
}

void solve(){
        ans = dfs(0, -1).first;
}

int main(){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        scanf("%d",&n);
        fi(0, n){
                scanf("%d",&l[i]);
                int q;
                scanf("%d",&q);
                if(q == 0){
                        scanf("%d",&a[i]);
                        w[i] = 1;
                }else{
                        fj(0, q){
                                int u;
                                scanf("%d",&u);
                                --u;
                                e[i].pb(u);
                                e[u].pb(i);
                        }
                }
        }

        solve();

        printf("%lld\n",ans);

        return 0;
}
