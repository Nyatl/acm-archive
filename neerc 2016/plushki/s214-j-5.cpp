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
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define _(a, b) memset(a, b, sizeof(a))

int n, m, h, w, globalId;

struct Level{
	int id, par, cnt;
	vector<bool> have;
	ll mini, maxi;
	double center;

	Level(){
		have.assign(n, true);
		mini = 0;
		maxi = n - 1;
		cnt = n;
		calcCenter();
		id = globalId++;
		par = (id & 1);
	};

	void calcCenter(){
		center = 0;
		fi(0, sz(have)){
			if (have[i]){
				center += i;
			}
		}
		center /= cnt;
	}

	void removeBlock(int _id){
		have[_id] = false;
		--cnt;
		if (cnt == 0){
			mini = maxi = -1;
			center = -1;
			return;
		}
		if (_id == mini){
			int p = _id;
			while (!have[p]){
				++p; 
			}
			mini = p;
		}

		if (_id == maxi){
			int p = _id;
			while (!have[p]){
				--p;
			}
			maxi = p;
		}

		calcCenter();
	}
};

vector<Level> levels;

bool inRange(double center, ll cnt, ll mini, ll maxi){
	if (cnt == 0) {
		return true;
	}
	if (mini == -1) {
		return false;
	}
	bool ret = true;
	if (cnt * (mini - .5) >= center || cnt * (maxi + .5) <= center){
		ret = false;
	}
	return ret;
}

bool check(){
	double curCenterEven = 0;
	double curCenterOdd = 0;
	ll cntOdd = 0;
	ll cntEven = 0;
	for (int i = h - 1; i >= 0; --i){
		if (i & 1){
			if (!inRange(curCenterOdd, cntOdd, levels[i].mini, levels[i].maxi)){
				return true;
			}
			curCenterOdd += levels[i].center * levels[i].cnt;
			curCenterEven += levels[i].cnt * (n - 1) / 2;
		}
		else{
			if (!inRange(curCenterEven, cntEven, levels[i].mini, levels[i].maxi)){
				return true;
			}
			curCenterEven += levels[i].center * levels[i].cnt;
			curCenterOdd += levels[i].cnt * (n - 1) / 2;
		}
		cntOdd += levels[i].cnt;
		cntEven += levels[i].cnt;
	}

	return false;
}

void read() {
	scanf("%d %d", &n, &w);
	scanf("%d %d", &h, &m);
	fi(0, h){
		levels.push_back(Level());
	}
	fi(0, m){
		int levId, id;
		scanf("%d %d", &levId, &id);
		--levId;
		--id;
		levels[levId].removeBlock(id);
		if (check()){
			printf("yes\n%d", i + 1);
			exit(0);
		}
	}
	printf("no\n");
}

void solve() {

}

#define FILENAME "jenga"

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