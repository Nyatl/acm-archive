#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define sz(a) ((int)(a).size())
#define fi(a,b) for(int i = (a); i < (b); ++i)

int getAns(int q1, int q2, int q3, int c, vector<int> & ret) {
	int res = 0;
	while(q1 + q2 + q3) {
		if(c == 1) {
			if(q3) {
				c = 3;
				ret.push_back(3);
				res += 3;
				q3--;
			} else if(q2) {
				c = 2;
				ret.push_back(2);
				res += 2;
				q2--;
			} else {
				ret.push_back(1);
				res += 1;
				q1--;
			}
		} else if(c == 3) {
			if (q1) {
				c = 1;
				ret.push_back(1);
				res += 3;
				q1--;
			} else if (q2) {
				c = 2;
				ret.push_back(2);
				res += 2;
				q2--;
			} else {
				ret.push_back(3);
				res += 1;
				q3--;
			}
		} else {
			if (q3) {
				c = 3;
				ret.push_back(3);
				res += 2;
				q3--;
			} else if (q1) {
				c = 1;
				ret.push_back(1);
				res += 2;
				q1--;
			} else {
				ret.push_back(2);
				res += 1;
				q2--;
			}
		}
	}
	return res;
}

void solve() {
	int q1, q2, q3;
	scanf("%d%d%d", &q1, &q2, &q3);
	vector<int> ret1;
	vector<int> ret2;
	int ans1 = 0;
	int ans2 = 0;
	if(q1) {
		ret1.push_back(1);
		ans1 = 2 + getAns(q1 - 1, q2, q3, 1, ret1);
	}
	if(q3) {
		ret2.push_back(3);
		ans2 = 2 + getAns(q1, q2, q3 - 1, 3, ret2);
	}
	if(!q1 && !q3) {
		fi(0, q2) {
			printf("2 ");
		}
		return;
	}
	if(ans1 > ans2) {
		fi(0, sz(ret1)) {
			printf("%d ", ret1[i]);
		}
	} else {
		fi(0, sz(ret2)) {
			printf("%d ", ret2[i]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}