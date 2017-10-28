#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int n, w, h, k;
LL sumX[10010], sumY[10010];
LL cnt[10010];
set< int > Set[10010];
int first[10010], last[10010];

void sol()
{
	FOR(a,1,h+1)
	{
		cnt[a] = cnt[a-1] + n;
		sumX[a] = sumX[a-1] + (LL)n*n;
		sumY[a] = sumX[a];
		first[a] = 1;
		last[a] = n;
	}

	FOR(z,1,k)
	{
		int L, t;
		RE("%d%d", &L, &t);
		L = h+1-L;

		Set[L].insert( t );
		first[L] = 1;
		last[L] = n;
		for (set< int >::iterator it = Set[L].begin(); it != Set[L].end(); it++)
			if ((*it)==first[L])
				first[L]++;
		for (set< int >::reverse_iterator it = Set[L].rbegin(); it != Set[L].rend(); it++)
			if ((*it)==last[L])
				last[L]--;

		FOR(a,L,h+1)
		{
			cnt[a]--;
			if (L&1)
			{
				sumX[a] -= n;
				sumY[a] -= t*2-1;
			}
			else
			{
				sumX[a] -= t*2-1;
				sumY[a] -= n;
			}
		}

		FOR(a,L,h+1)
			if (a>1 && cnt[a-1]>0)
			{
				// sumX[L-1]/cnt[L-1] , sumY[L-1]/cnt[L-1]

				bool flag = false;
				LL be, en;
				if (a&1)
				{
					be = (sumY[a-1]/cnt[a-1])/2+1;
					en = be;
					if ( (LL)(be-1)*2*cnt[a-1] == sumY[a-1] ) en--;
				}
				else
				{
					be = (sumX[a-1]/cnt[a-1])/2+1;
					en = be;
					if ( (LL)(be-1)*2*cnt[a-1] == sumX[a-1] ) en--;
				}

				if (SZ(Set[a])==n) flag = true;
				else
				{
					if (first[a] > en || last[a] < be) flag = true;
				}

				if (flag)
				{
					cout << "yes\n" << z;
					return;
				}
			}
	}

	cout << "no";
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	freopen("jenga.in","r",stdin);
	freopen("jenga.out","w",stdout);

	cin >> n >> w >> h >> k;

	sol();
	return 0;
}
