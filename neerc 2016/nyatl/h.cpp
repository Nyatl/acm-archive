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

vector< PAR > seg;

void sol()
{
	vector< PAR > ans;
	sort( seg.begin(), seg.end() );
	FA(a,seg) ass( seg[a].FI <= seg[a].SE );

	int be = o_O, en = -o_O;
	FA(a,seg)
	{
		if (be == o_O)
		{
			be = seg[a].FI;
			en = seg[a].SE;
		}
		else
		{
			if (seg[a].FI <= en+1) en = max( en, seg[a].SE );
			else
			{
				ans.push_back( make_pair( be, en ) );
				be = seg[a].FI;
				en = seg[a].SE;
			}
		}
	}

	if (be != o_O) ans.push_back( make_pair( be, en ) );

	if (SZ(ans)==0) cout << "false";
	else if (SZ(ans)==1 && ans[0] == make_pair( -32768, 32767 )) cout << "true";
	else
	{
		FA(a,ans)
		{
			if (ans[a].FI==-32768) cout << "x <= " << ans[a].SE;
			else if (ans[a].SE==32767) cout << "x >= " << ans[a].FI;
			else cout << "x >= " << ans[a].FI << " && x <= " << ans[a].SE;
			if (a!=SZ(ans)-1) cout << " ||\n";
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	freopen("hard.in","r",stdin);
	freopen("hard.out","w",stdout);

	string x, sign1, sign2, tmp;
	int value1, value2;
	while(1)
	{
		cin >> x >> sign1 >> value1;
		if (!(cin >> tmp) || tmp == "x")
		{
			if (sign1 == ">=") seg.push_back( make_pair( value1, 32767 ) );
			else seg.push_back( make_pair( -32768, value1 ) );
			break;
		}
		if (tmp == "&&")
		{
			cin >> x >> sign2 >> value2;
			if (sign1 == ">=" && sign2 == ">=") seg.push_back( make_pair( max( value1, value2 ), 32767 ) );
			else if (sign1 == "<=" && sign2 == "<=") seg.push_back( make_pair( -32768, min( value1, value2 ) ) );
			else if (sign1 == ">=" && sign2 == "<=")
			{
				if (value1 <= value2) seg.push_back( make_pair( value1, value2 ) );
			}
			else
			{
				if (value2 <= value1) seg.push_back( make_pair( value2, value1 ) );
			}
			if (!(cin >> tmp) || tmp == "x") break;
		}
		else
		{
			if (sign1 == ">=") seg.push_back( make_pair( value1, 32767 ) );
			else seg.push_back( make_pair( -32768, value1 ) );
		}
	}

	sol();
	return 0;
}
