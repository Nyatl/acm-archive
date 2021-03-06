#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <memory.h>
#include <assert.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#ifdef DENIS
#define fi(a, b) for(int i=a; i<b; i++)
#define fj(a, b) for(int j=a; j<b; j++)
#define fo(a, b) for(int o=a; o<b; o++)
#define fdi(a, b) for(int i=a-1; i>=b; i--)
#define fdj(a, b) for(int j=a-1; j>=b; j--)
#define fdo(a, b) for(int o=a-1; o>=b; o--)
#else
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)

#endif
#define clr(x) memset(x, 0, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define sz(x) (int)x.size()

char __buffer[100000];

void err(const char *format, ... ) {
#ifdef _DEBUG
	va_list ap;
	va_start(ap, format);
	vsprintf(__buffer, format, ap);
	va_end(ap);
	
	fprintf(stderr, "%s\n", __buffer);
#endif
}

void _dbg(int x) {
	fprintf(stderr, "%d", x);
}

void _dbg(long long x) {
	fprintf(stderr, "%lld", x);
}

void _dbg(double x) {
	fprintf(stderr, "%.9lf", x);
}

void _dbg(char x) {
	fprintf(stderr, "%c", x);
}

void _dbg(vector<int> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg(vector<long long> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg(vector<double> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg(vector<char> x) {
	for (int i = 0; i < sz(x); i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void _dbg0(int *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg0(long long *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg0(double *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg0(char *x, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void _dbg1(int *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%d ", x[i]);
	}
}

void _dbg1(long long *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%lld ", x[i]);
	}
}

void _dbg1(double *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%.9lf ", x[i]);
	}
}

void _dbg1(char *x, int n) {
	for (int i = 1; i <= n; i++) {
		fprintf(stderr, "%c ", x[i]);
	}
}

void as(bool cond) {
	if (!cond) {
		fprintf(stderr, "ASSERT!\n");
	}
	assert(cond);
}

#ifdef _DEBUG
#define dbg(x) cerr << #x << ": "; _dbg(x); cerr << endl;
#define dbg0(x, n) cerr << #x << ": "; _dbg0(x, n); cerr << endl;
#define dbg1(x, n) cerr << #x << ": "; _dbg1(x, n); cerr << endl;
#else
#define dbg(x) while (0);
#define dbg0(x, n) while (0);
#define dbg1(x, n) while (0);
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define FILENAME "bit-squares"

ll n;
int q[100][100];

int length(ll x) {
    int res = 0;
    while (x) {
        res++;
        x >>= 1;
	}
    return res;
}

int cnt(ll x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
	}
    return res;
}

void init() {
    fi(1, 1000000000) {
		if (i % 100000 == 0) {
			fprintf(stderr, "%d (%d)\n", i, 1000000000 - i);
		}
		ll x = (ll)i * i;
        q[length(x)][cnt(x)]++;
	}
    fi(1, 99) {
		fj(1, 99) {
			if (q[i][j] != 0) {
				printf("q[%d][%d] = %d;\n", i, j, q[i][j]);
			}
		}
	}
}

void solve() {
	int a = length(n);
	int b = cnt(n);
	printf("%d\n", q[a][b]);
}

int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
    //init();
	q[1][1] = 1;
q[3][1] = 1;
q[4][2] = 1;
q[5][1] = 1;
q[5][3] = 1;
q[6][2] = 1;
q[6][3] = 1;
q[7][1] = 1;
q[7][3] = 2;
q[7][5] = 1;
q[8][2] = 1;
q[8][3] = 1;
q[8][4] = 2;
q[9][1] = 1;
q[9][3] = 3;
q[9][5] = 2;
q[9][6] = 1;
q[10][2] = 1;
q[10][3] = 2;
q[10][4] = 2;
q[10][5] = 3;
q[10][6] = 1;
q[11][1] = 1;
q[11][3] = 4;
q[11][5] = 4;
q[11][6] = 2;
q[11][7] = 2;
q[11][8] = 1;
q[12][2] = 1;
q[12][3] = 2;
q[12][4] = 3;
q[12][5] = 5;
q[12][6] = 4;
q[12][7] = 2;
q[12][8] = 1;
q[13][1] = 1;
q[13][3] = 5;
q[13][5] = 6;
q[13][6] = 5;
q[13][7] = 6;
q[13][8] = 2;
q[13][9] = 2;
q[14][2] = 1;
q[14][3] = 2;
q[14][4] = 4;
q[14][5] = 8;
q[14][6] = 7;
q[14][7] = 7;
q[14][8] = 6;
q[14][9] = 2;
q[15][1] = 1;
q[15][3] = 6;
q[15][5] = 9;
q[15][6] = 10;
q[15][7] = 8;
q[15][8] = 6;
q[15][9] = 12;
q[15][10] = 1;
q[15][13] = 1;
q[16][2] = 1;
q[16][3] = 2;
q[16][4] = 4;
q[16][5] = 10;
q[16][6] = 13;
q[16][7] = 14;
q[16][8] = 14;
q[16][9] = 9;
q[16][10] = 5;
q[16][11] = 2;
q[17][1] = 1;
q[17][3] = 7;
q[17][5] = 11;
q[17][6] = 17;
q[17][7] = 13;
q[17][8] = 14;
q[17][9] = 28;
q[17][10] = 9;
q[17][11] = 4;
q[17][12] = 2;
q[17][13] = 1;
q[18][2] = 1;
q[18][3] = 2;
q[18][4] = 4;
q[18][5] = 12;
q[18][6] = 18;
q[18][7] = 24;
q[18][8] = 29;
q[18][9] = 23;
q[18][10] = 18;
q[18][11] = 13;
q[18][12] = 5;
q[19][1] = 1;
q[19][3] = 8;
q[19][5] = 13;
q[19][6] = 23;
q[19][7] = 18;
q[19][8] = 26;
q[19][9] = 59;
q[19][10] = 26;
q[19][11] = 19;
q[19][12] = 9;
q[19][13] = 9;
q[19][14] = 2;
q[20][2] = 1;
q[20][3] = 2;
q[20][4] = 4;
q[20][5] = 14;
q[20][6] = 21;
q[20][7] = 32;
q[20][8] = 48;
q[20][9] = 56;
q[20][10] = 47;
q[20][11] = 36;
q[20][12] = 23;
q[20][13] = 8;
q[20][14] = 5;
q[20][15] = 2;
q[21][1] = 1;
q[21][3] = 9;
q[21][5] = 14;
q[21][6] = 32;
q[21][7] = 26;
q[21][8] = 42;
q[21][9] = 97;
q[21][10] = 58;
q[21][11] = 54;
q[21][12] = 40;
q[21][13] = 35;
q[21][14] = 14;
q[21][15] = 2;
q[21][16] = 1;
q[22][2] = 1;
q[22][3] = 2;
q[22][4] = 4;
q[22][5] = 16;
q[22][6] = 25;
q[22][7] = 41;
q[22][8] = 73;
q[22][9] = 88;
q[22][10] = 101;
q[22][11] = 94;
q[22][12] = 72;
q[22][13] = 43;
q[22][14] = 22;
q[22][15] = 12;
q[22][16] = 5;
q[23][1] = 1;
q[23][3] = 10;
q[23][5] = 16;
q[23][6] = 39;
q[23][7] = 33;
q[23][8] = 58;
q[23][9] = 150;
q[23][10] = 108;
q[23][11] = 124;
q[23][12] = 116;
q[23][13] = 107;
q[23][14] = 52;
q[23][15] = 24;
q[23][16] = 7;
q[23][17] = 4;
q[24][2] = 1;
q[24][3] = 2;
q[24][4] = 4;
q[24][5] = 17;
q[24][6] = 27;
q[24][7] = 47;
q[24][8] = 99;
q[24][9] = 141;
q[24][10] = 169;
q[24][11] = 201;
q[24][12] = 168;
q[24][13] = 128;
q[24][14] = 103;
q[24][15] = 59;
q[24][16] = 22;
q[24][17] = 10;
q[24][18] = 1;
q[25][1] = 1;
q[25][3] = 11;
q[25][5] = 17;
q[25][6] = 51;
q[25][7] = 37;
q[25][8] = 75;
q[25][9] = 202;
q[25][10] = 185;
q[25][11] = 248;
q[25][12] = 259;
q[25][13] = 255;
q[25][14] = 173;
q[25][15] = 102;
q[25][16] = 46;
q[25][17] = 24;
q[25][18] = 9;
q[25][19] = 2;
q[26][2] = 1;
q[26][3] = 2;
q[26][4] = 4;
q[26][5] = 19;
q[26][6] = 29;
q[26][7] = 55;
q[26][8] = 122;
q[26][9] = 213;
q[26][10] = 250;
q[26][11] = 329;
q[26][12] = 374;
q[26][13] = 321;
q[26][14] = 283;
q[26][15] = 200;
q[26][16] = 123;
q[26][17] = 55;
q[26][18] = 12;
q[26][19] = 5;
q[26][20] = 2;
q[27][1] = 1;
q[27][3] = 12;
q[27][5] = 19;
q[27][6] = 60;
q[27][7] = 43;
q[27][8] = 90;
q[27][9] = 261;
q[27][10] = 292;
q[27][11] = 386;
q[27][12] = 490;
q[27][13] = 564;
q[27][14] = 433;
q[27][15] = 330;
q[27][16] = 200;
q[27][17] = 121;
q[27][18] = 62;
q[27][19] = 21;
q[27][20] = 8;
q[27][21] = 1;
q[28][2] = 1;
q[28][3] = 2;
q[28][4] = 4;
q[28][5] = 20;
q[28][6] = 30;
q[28][7] = 58;
q[28][8] = 150;
q[28][9] = 263;
q[28][10] = 370;
q[28][11] = 503;
q[28][12] = 657;
q[28][13] = 701;
q[28][14] = 685;
q[28][15] = 523;
q[28][16] = 401;
q[28][17] = 237;
q[28][18] = 114;
q[28][19] = 60;
q[28][20] = 13;
q[28][21] = 4;
q[28][22] = 2;
q[29][1] = 1;
q[29][3] = 13;
q[29][5] = 20;
q[29][6] = 71;
q[29][7] = 47;
q[29][8] = 107;
q[29][9] = 321;
q[29][10] = 397;
q[29][11] = 602;
q[29][12] = 812;
q[29][13] = 1035;
q[29][14] = 951;
q[29][15] = 865;
q[29][16] = 624;
q[29][17] = 455;
q[29][18] = 267;
q[29][19] = 123;
q[29][20] = 49;
q[29][21] = 21;
q[29][22] = 5;
q[29][23] = 1;
q[30][2] = 1;
q[30][3] = 2;
q[30][4] = 4;
q[30][5] = 21;
q[30][6] = 32;
q[30][7] = 61;
q[30][8] = 175;
q[30][9] = 323;
q[30][10] = 480;
q[30][11] = 729;
q[30][12] = 1069;
q[30][13] = 1213;
q[30][14] = 1427;
q[30][15] = 1270;
q[30][16] = 1052;
q[30][17] = 774;
q[30][18] = 494;
q[30][19] = 284;
q[30][20] = 133;
q[30][21] = 36;
q[30][22] = 10;
q[30][23] = 6;
q[30][24] = 1;
q[31][1] = 1;
q[31][3] = 14;
q[31][5] = 22;
q[31][6] = 82;
q[31][7] = 50;
q[31][8] = 119;
q[31][9] = 399;
q[31][10] = 499;
q[31][11] = 825;
q[31][12] = 1229;
q[31][13] = 1751;
q[31][14] = 1856;
q[31][15] = 1851;
q[31][16] = 1582;
q[31][17] = 1388;
q[31][18] = 893;
q[31][19] = 572;
q[31][20] = 243;
q[31][21] = 139;
q[31][22] = 50;
q[31][23] = 6;
q[31][24] = 1;
q[31][25] = 1;
q[32][2] = 1;
q[32][3] = 2;
q[32][4] = 4;
q[32][5] = 22;
q[32][6] = 35;
q[32][7] = 63;
q[32][8] = 200;
q[32][9] = 372;
q[32][10] = 591;
q[32][11] = 1006;
q[32][12] = 1540;
q[32][13] = 1977;
q[32][14] = 2506;
q[32][15] = 2716;
q[32][16] = 2497;
q[32][17] = 2054;
q[32][18] = 1520;
q[32][19] = 1066;
q[32][20] = 579;
q[32][21] = 283;
q[32][22] = 106;
q[32][23] = 39;
q[32][24] = 14;
q[32][25] = 2;
q[33][1] = 1;
q[33][3] = 15;
q[33][5] = 23;
q[33][6] = 95;
q[33][7] = 52;
q[33][8] = 130;
q[33][9] = 469;
q[33][10] = 634;
q[33][11] = 1055;
q[33][12] = 1718;
q[33][13] = 2661;
q[33][14] = 3235;
q[33][15] = 3631;
q[33][16] = 3472;
q[33][17] = 3405;
q[33][18] = 2493;
q[33][19] = 1899;
q[33][20] = 1108;
q[33][21] = 611;
q[33][22] = 270;
q[33][23] = 114;
q[33][24] = 39;
q[33][25] = 14;
q[33][26] = 2;
q[34][2] = 1;
q[34][3] = 2;
q[34][4] = 4;
q[34][5] = 23;
q[34][6] = 36;
q[34][7] = 66;
q[34][8] = 213;
q[34][9] = 428;
q[34][10] = 693;
q[34][11] = 1277;
q[34][12] = 2105;
q[34][13] = 2979;
q[34][14] = 4116;
q[34][15] = 4873;
q[34][16] = 5173;
q[34][17] = 4835;
q[34][18] = 4082;
q[34][19] = 3121;
q[34][20] = 2091;
q[34][21] = 1262;
q[34][22] = 566;
q[34][23] = 304;
q[34][24] = 100;
q[34][25] = 30;
q[34][26] = 9;
q[34][27] = 1;
q[35][1] = 1;
q[35][3] = 16;
q[35][5] = 25;
q[35][6] = 108;
q[35][7] = 55;
q[35][8] = 140;
q[35][9] = 544;
q[35][10] = 772;
q[35][11] = 1295;
q[35][12] = 2241;
q[35][13] = 3779;
q[35][14] = 5120;
q[35][15] = 6288;
q[35][16] = 6733;
q[35][17] = 7345;
q[35][18] = 6286;
q[35][19] = 5259;
q[35][20] = 3578;
q[35][21] = 2331;
q[35][22] = 1261;
q[35][23] = 654;
q[35][24] = 302;
q[35][25] = 116;
q[35][26] = 38;
q[35][27] = 4;
q[35][28] = 1;
q[36][2] = 1;
q[36][3] = 2;
q[36][4] = 4;
q[36][5] = 24;
q[36][6] = 38;
q[36][7] = 67;
q[36][8] = 228;
q[36][9] = 470;
q[36][10] = 789;
q[36][11] = 1568;
q[36][12] = 2691;
q[36][13] = 4207;
q[36][14] = 6248;
q[36][15] = 8076;
q[36][16] = 9292;
q[36][17] = 10062;
q[36][18] = 9441;
q[36][19] = 8195;
q[36][20] = 6116;
q[36][21] = 4283;
q[36][22] = 2540;
q[36][23] = 1411;
q[36][24] = 639;
q[36][25] = 259;
q[36][26] = 91;
q[36][27] = 32;
q[36][28] = 5;
q[36][29] = 1;
q[37][1] = 1;
q[37][3] = 17;
q[37][5] = 26;
q[37][6] = 123;
q[37][7] = 57;
q[37][8] = 149;
q[37][9] = 606;
q[37][10] = 918;
q[37][11] = 1535;
q[37][12] = 2775;
q[37][13] = 5062;
q[37][14] = 7484;
q[37][15] = 10063;
q[37][16] = 11941;
q[37][17] = 13993;
q[37][18] = 13622;
q[37][19] = 12737;
q[37][20] = 10066;
q[37][21] = 7451;
q[37][22] = 4650;
q[37][23] = 2798;
q[37][24] = 1459;
q[37][25] = 669;
q[37][26] = 259;
q[37][27] = 90;
q[37][28] = 28;
q[37][29] = 4;
q[37][30] = 1;
q[38][2] = 1;
q[38][3] = 2;
q[38][4] = 4;
q[38][5] = 25;
q[38][6] = 39;
q[38][7] = 70;
q[38][8] = 237;
q[38][9] = 510;
q[38][10] = 880;
q[38][11] = 1844;
q[38][12] = 3362;
q[38][13] = 5487;
q[38][14] = 8840;
q[38][15] = 12402;
q[38][16] = 15713;
q[38][17] = 18508;
q[38][18] = 19225;
q[38][19] = 18704;
q[38][20] = 15759;
q[38][21] = 12511;
q[38][22] = 8640;
q[38][23] = 5448;
q[38][24] = 2955;
q[38][25] = 1419;
q[38][26] = 638;
q[38][27] = 251;
q[38][28] = 62;
q[38][29] = 20;
q[38][30] = 3;
q[38][31] = 1;
q[39][1] = 1;
q[39][3] = 18;
q[39][5] = 28;
q[39][6] = 138;
q[39][7] = 59;
q[39][8] = 154;
q[39][9] = 683;
q[39][10] = 1049;
q[39][11] = 1761;
q[39][12] = 3372;
q[39][13] = 6440;
q[39][14] = 10342;
q[39][15] = 14794;
q[39][16] = 19291;
q[39][17] = 24574;
q[39][18] = 26678;
q[39][19] = 27352;
q[39][20] = 24125;
q[39][21] = 20238;
q[39][22] = 14560;
q[39][23] = 9929;
q[39][24] = 5918;
q[39][25] = 3245;
q[39][26] = 1437;
q[39][27] = 632;
q[39][28] = 257;
q[39][29] = 58;
q[39][30] = 30;
q[39][31] = 5;
q[40][2] = 1;
q[40][3] = 2;
q[40][4] = 4;
q[40][5] = 26;
q[40][6] = 40;
q[40][7] = 71;
q[40][8] = 249;
q[40][9] = 552;
q[40][10] = 964;
q[40][11] = 2116;
q[40][12] = 3973;
q[40][13] = 6923;
q[40][14] = 11777;
q[40][15] = 17839;
q[40][16] = 24419;
q[40][17] = 31161;
q[40][18] = 35769;
q[40][19] = 38168;
q[40][20] = 36233;
q[40][21] = 31516;
q[40][22] = 24602;
q[40][23] = 17636;
q[40][24] = 11094;
q[40][25] = 6341;
q[40][26] = 3249;
q[40][27] = 1488;
q[40][28] = 594;
q[40][29] = 224;
q[40][30] = 69;
q[40][31] = 12;
q[40][32] = 6;
q[40][33] = 1;
q[40][34] = 1;
q[41][1] = 1;
q[41][3] = 19;
q[41][5] = 29;
q[41][6] = 155;
q[41][7] = 60;
q[41][8] = 163;
q[41][9] = 752;
q[41][10] = 1201;
q[41][11] = 1972;
q[41][12] = 3934;
q[41][13] = 7893;
q[41][14] = 13479;
q[41][15] = 20706;
q[41][16] = 29076;
q[41][17] = 39624;
q[41][18] = 47624;
q[41][19] = 52997;
q[41][20] = 51977;
q[41][21] = 48370;
q[41][22] = 39308;
q[41][23] = 29568;
q[41][24] = 20318;
q[41][25] = 12570;
q[41][26] = 6745;
q[41][27] = 3410;
q[41][28] = 1517;
q[41][29] = 592;
q[41][30] = 190;
q[41][31] = 67;
q[41][32] = 12;
q[41][33] = 6;
q[42][2] = 1;
q[42][3] = 2;
q[42][4] = 4;
q[42][5] = 27;
q[42][6] = 41;
q[42][7] = 73;
q[42][8] = 259;
q[42][9] = 586;
q[42][10] = 1039;
q[42][11] = 2333;
q[42][12] = 4584;
q[42][13] = 8408;
q[42][14] = 15027;
q[42][15] = 24203;
q[42][16] = 35657;
q[42][17] = 48980;
q[42][18] = 61370;
q[42][19] = 70776;
q[42][20] = 73917;
q[42][21] = 71166;
q[42][22] = 61695;
q[42][23] = 49246;
q[42][24] = 35210;
q[42][25] = 23147;
q[42][26] = 13603;
q[42][27] = 7264;
q[42][28] = 3365;
q[42][29] = 1494;
q[42][30] = 529;
q[42][31] = 172;
q[42][32] = 48;
q[42][33] = 13;
q[42][34] = 2;
q[43][1] = 1;
q[43][3] = 20;
q[43][5] = 31;
q[43][6] = 172;
q[43][7] = 62;
q[43][8] = 169;
q[43][9] = 832;
q[43][10] = 1345;
q[43][11] = 2161;
q[43][12] = 4501;
q[43][13] = 9392;
q[43][14] = 16828;
q[43][15] = 27411;
q[43][16] = 41085;
q[43][17] = 60172;
q[43][18] = 78231;
q[43][19] = 94408;
q[43][20] = 102051;
q[43][21] = 103375;
q[43][22] = 93040;
q[43][23] = 78390;
q[43][24] = 59373;
q[43][25] = 42003;
q[43][26] = 25607;
q[43][27] = 14784;
q[43][28] = 7425;
q[43][29] = 3560;
q[43][30] = 1456;
q[43][31] = 545;
q[43][32] = 187;
q[43][33] = 41;
q[43][34] = 9;
q[43][35] = 1;
q[43][37] = 1;
q[44][2] = 1;
q[44][3] = 2;
q[44][4] = 4;
q[44][5] = 28;
q[44][6] = 43;
q[44][7] = 75;
q[44][8] = 266;
q[44][9] = 621;
q[44][10] = 1099;
q[44][11] = 2531;
q[44][12] = 5205;
q[44][13] = 9816;
q[44][14] = 18406;
q[44][15] = 31342;
q[44][16] = 49148;
q[44][17] = 72276;
q[44][18] = 97566;
q[44][19] = 121866;
q[44][20] = 138034;
q[44][21] = 145259;
q[44][22] = 138908;
q[44][23] = 121820;
q[44][24] = 97347;
q[44][25] = 71258;
q[44][26] = 47526;
q[44][27] = 28944;
q[44][28] = 15733;
q[44][29] = 7839;
q[44][30] = 3485;
q[44][31] = 1386;
q[44][32] = 456;
q[44][33] = 138;
q[44][34] = 43;
q[44][35] = 11;
q[44][37] = 1;
q[45][1] = 1;
q[45][3] = 21;
q[45][5] = 32;
q[45][6] = 191;
q[45][7] = 64;
q[45][8] = 177;
q[45][9] = 896;
q[45][10] = 1509;
q[45][11] = 2333;
q[45][12] = 5023;
q[45][13] = 10830;
q[45][14] = 20309;
q[45][15] = 34926;
q[45][16] = 55332;
q[45][17] = 86259;
q[45][18] = 120262;
q[45][19] = 156256;
q[45][20] = 183102;
q[45][21] = 201412;
q[45][22] = 199383;
q[45][23] = 184745;
q[45][24] = 154720;
q[45][25] = 120321;
q[45][26] = 83655;
q[45][27] = 54131;
q[45][28] = 31240;
q[45][29] = 16776;
q[45][30] = 8051;
q[45][31] = 3415;
q[45][32] = 1323;
q[45][33] = 467;
q[45][34] = 129;
q[45][35] = 34;
q[45][36] = 9;
q[45][37] = 3;
q[45][38] = 1;
q[46][2] = 1;
q[46][3] = 2;
q[46][4] = 4;
q[46][5] = 29;
q[46][6] = 44;
q[46][7] = 77;
q[46][8] = 275;
q[46][9] = 652;
q[46][10] = 1152;
q[46][11] = 2716;
q[46][12] = 5718;
q[46][13] = 11105;
q[46][14] = 21855;
q[46][15] = 39092;
q[46][16] = 64799;
q[46][17] = 101109;
q[46][18] = 145815;
q[46][19] = 195273;
q[46][20] = 238707;
q[46][21] = 272301;
q[46][22] = 283526;
q[46][23] = 272208;
q[46][24] = 239578;
q[46][25] = 193853;
q[46][26] = 143658;
q[46][27] = 98241;
q[46][28] = 60485;
q[46][29] = 34252;
q[46][30] = 17352;
q[46][31] = 8094;
q[46][32] = 3234;
q[46][33] = 1196;
q[46][34] = 400;
q[46][35] = 122;
q[46][36] = 30;
q[46][37] = 9;
q[46][38] = 2;
q[47][1] = 1;
q[47][3] = 22;
q[47][5] = 34;
q[47][6] = 210;
q[47][7] = 66;
q[47][8] = 184;
q[47][9] = 980;
q[47][10] = 1678;
q[47][11] = 2473;
q[47][12] = 5473;
q[47][13] = 12223;
q[47][14] = 23928;
q[47][15] = 42780;
q[47][16] = 71104;
q[47][17] = 117295;
q[47][18] = 174975;
q[47][19] = 242480;
q[47][20] = 305890;
q[47][21] = 363024;
q[47][22] = 390899;
q[47][23] = 393949;
q[47][24] = 361662;
q[47][25] = 308987;
q[47][26] = 237470;
q[47][27] = 170994;
q[47][28] = 110954;
q[47][29] = 67179;
q[47][30] = 36631;
q[47][31] = 18248;
q[47][32] = 7817;
q[47][33] = 3378;
q[47][34] = 1152;
q[47][35] = 390;
q[47][36] = 102;
q[47][37] = 37;
q[47][38] = 5;
q[47][39] = 2;
q[48][2] = 1;
q[48][3] = 2;
q[48][4] = 4;
q[48][5] = 30;
q[48][6] = 45;
q[48][7] = 78;
q[48][8] = 283;
q[48][9] = 682;
q[48][10] = 1193;
q[48][11] = 2898;
q[48][12] = 6148;
q[48][13] = 12402;
q[48][14] = 25307;
q[48][15] = 47032;
q[48][16] = 81491;
q[48][17] = 135109;
q[48][18] = 206681;
q[48][19] = 294599;
q[48][20] = 387150;
q[48][21] = 473481;
q[48][22] = 533212;
q[48][23] = 555142;
q[48][24] = 533192;
q[48][25] = 473502;
q[48][26] = 385455;
q[48][27] = 290326;
q[48][28] = 199209;
q[48][29] = 126702;
q[48][30] = 72962;
q[48][31] = 38716;
q[48][32] = 18276;
q[48][33] = 7937;
q[48][34] = 3080;
q[48][35] = 1122;
q[48][36] = 369;
q[48][37] = 88;
q[48][38] = 25;
q[48][39] = 1;
q[49][1] = 1;
q[49][3] = 23;
q[49][5] = 35;
q[49][6] = 231;
q[49][7] = 67;
q[49][8] = 191;
q[49][9] = 1049;
q[49][10] = 1870;
q[49][11] = 2595;
q[49][12] = 5919;
q[49][13] = 13525;
q[49][14] = 27444;
q[49][15] = 50839;
q[49][16] = 88248;
q[49][17] = 152754;
q[49][18] = 241736;
q[49][19] = 355727;
q[49][20] = 480922;
q[49][21] = 610971;
q[49][22] = 709932;
q[49][23] = 770732;
q[49][24] = 768658;
q[49][25] = 714208;
q[49][26] = 605735;
q[49][27] = 478339;
q[49][28] = 345135;
q[49][29] = 231429;
q[49][30] = 140886;
q[49][31] = 79473;
q[49][32] = 39529;
q[49][33] = 18732;
q[49][34] = 7899;
q[49][35] = 3053;
q[49][36] = 1004;
q[49][37] = 347;
q[49][38] = 79;
q[49][39] = 28;
q[49][40] = 5;
q[49][41] = 1;
q[50][2] = 1;
q[50][3] = 2;
q[50][4] = 4;
q[50][5] = 31;
q[50][6] = 46;
q[50][7] = 80;
q[50][8] = 290;
q[50][9] = 713;
q[50][10] = 1229;
q[50][11] = 3052;
q[50][12] = 6558;
q[50][13] = 13475;
q[50][14] = 28460;
q[50][15] = 55138;
q[50][16] = 99528;
q[50][17] = 173252;
q[50][18] = 279494;
q[50][19] = 421721;
q[50][20] = 590808;
q[50][21] = 772602;
q[50][22] = 932349;
q[50][23] = 1048116;
q[50][24] = 1088643;
q[50][25] = 1048679;
q[50][26] = 931007;
q[50][27] = 767779;
q[50][28] = 581912;
q[50][29] = 408295;
q[50][30] = 262577;
q[50][31] = 155650;
q[50][32] = 84206;
q[50][33] = 41650;
q[50][34] = 18802;
q[50][35] = 7608;
q[50][36] = 2802;
q[50][37] = 915;
q[50][38] = 302;
q[50][39] = 72;
q[50][40] = 16;
q[50][41] = 1;
q[51][1] = 1;
q[51][3] = 24;
q[51][5] = 37;
q[51][6] = 252;
q[51][7] = 69;
q[51][8] = 196;
q[51][9] = 1143;
q[51][10] = 2056;
q[51][11] = 2710;
q[51][12] = 6308;
q[51][13] = 14754;
q[51][14] = 30989;
q[51][15] = 58772;
q[51][16] = 105749;
q[51][17] = 191727;
q[51][18] = 319951;
q[51][19] = 498003;
q[51][20] = 714780;
q[51][21] = 967286;
q[51][22] = 1202134;
q[51][23] = 1401515;
q[51][24] = 1509519;
q[51][25] = 1514507;
q[51][26] = 1398231;
q[51][27] = 1202059;
q[51][28] = 953722;
q[51][29] = 701564;
q[51][30] = 473028;
q[51][31] = 296832;
q[51][32] = 168322;
q[51][33] = 89584;
q[51][34] = 42688;
q[51][35] = 18904;
q[51][36] = 7428;
q[51][37] = 2637;
q[51][38] = 860;
q[51][39] = 272;
q[51][40] = 66;
q[51][41] = 18;
q[51][42] = 4;
q[52][2] = 1;
q[52][3] = 2;
q[52][4] = 4;
q[52][5] = 32;
q[52][6] = 47;
q[52][7] = 81;
q[52][8] = 298;
q[52][9] = 745;
q[52][10] = 1259;
q[52][11] = 3191;
q[52][12] = 6901;
q[52][13] = 14495;
q[52][14] = 31434;
q[52][15] = 62616;
q[52][16] = 117903;
q[52][17] = 214138;
q[52][18] = 362948;
q[52][19] = 576879;
q[52][20] = 856768;
q[52][21] = 1189558;
q[52][22] = 1533361;
q[52][23] = 1843149;
q[52][24] = 2058333;
q[52][25] = 2138082;
q[52][26] = 2056961;
q[52][27] = 1839030;
q[52][28] = 1525034;
q[52][29] = 1171497;
q[52][30] = 829114;
q[52][31] = 544029;
q[52][32] = 328981;
q[52][33] = 182528;
q[52][34] = 93480;
q[52][35] = 43488;
q[52][36] = 18542;
q[52][37] = 7216;
q[52][38] = 2523;
q[52][39] = 801;
q[52][40] = 207;
q[52][41] = 63;
q[52][42] = 10;
q[52][43] = 1;
q[52][44] = 1;
q[53][1] = 1;
q[53][3] = 25;
q[53][5] = 38;
q[53][6] = 275;
q[53][7] = 71;
q[53][8] = 202;
q[53][9] = 1217;
q[53][10] = 2272;
q[53][11] = 2806;
q[53][12] = 6672;
q[53][13] = 15866;
q[53][14] = 34337;
q[53][15] = 66474;
q[53][16] = 123450;
q[53][17] = 232776;
q[53][18] = 407879;
q[53][19] = 667037;
q[53][20] = 1013167;
q[53][21] = 1449930;
q[53][22] = 1920436;
q[53][23] = 2389245;
q[53][24] = 2757319;
q[53][25] = 2973365;
q[53][26] = 2962056;
q[53][27] = 2757412;
q[53][28] = 2377078;
q[53][29] = 1907196;
q[53][30] = 1411910;
q[53][31] = 974636;
q[53][32] = 615058;
q[53][33] = 363002;
q[53][34] = 195094;
q[53][35] = 96707;
q[53][36] = 43870;
q[53][37] = 18388;
q[53][38] = 6764;
q[53][39] = 2402;
q[53][40] = 717;
q[53][41] = 191;
q[53][42] = 51;
q[53][43] = 9;
q[53][44] = 1;
q[54][2] = 1;
q[54][3] = 2;
q[54][4] = 4;
q[54][5] = 33;
q[54][6] = 48;
q[54][7] = 83;
q[54][8] = 305;
q[54][9] = 777;
q[54][10] = 1289;
q[54][11] = 3306;
q[54][12] = 7225;
q[54][13] = 15354;
q[54][14] = 34073;
q[54][15] = 69746;
q[54][16] = 136044;
q[54][17] = 256877;
q[54][18] = 454500;
q[54][19] = 758480;
q[54][20] = 1187684;
q[54][21] = 1742791;
q[54][22] = 2382318;
q[54][23] = 3050538;
q[54][24] = 3640762;
q[54][25] = 4049178;
q[54][26] = 4192033;
q[54][27] = 4043343;
q[54][28] = 3631796;
q[54][29] = 3032711;
q[54][30] = 2345136;
q[54][31] = 1687039;
q[54][32] = 1124953;
q[54][33] = 691687;
q[54][34] = 394184;
q[54][35] = 206953;
q[54][36] = 99468;
q[54][37] = 43716;
q[54][38] = 17534;
q[54][39] = 6469;
q[54][40] = 2139;
q[54][41] = 681;
q[54][42] = 164;
q[54][43] = 27;
q[54][44] = 11;
q[55][1] = 1;
q[55][3] = 26;
q[55][5] = 40;
q[55][6] = 298;
q[55][7] = 73;
q[55][8] = 207;
q[55][9] = 1318;
q[55][10] = 2497;
q[55][11] = 2899;
q[55][12] = 6990;
q[55][13] = 16886;
q[55][14] = 37512;
q[55][15] = 73896;
q[55][16] = 140311;
q[55][17] = 275338;
q[55][18] = 502678;
q[55][19] = 860560;
q[55][20] = 1374224;
q[55][21] = 2073140;
q[55][22] = 2910576;
q[55][23] = 3847818;
q[55][24] = 4726771;
q[55][25] = 5446027;
q[55][26] = 5824555;
q[55][27] = 5827628;
q[55][28] = 5423762;
q[55][29] = 4713335;
q[55][30] = 3798415;
q[55][31] = 2857150;
q[55][32] = 1985213;
q[55][33] = 1286040;
q[55][34] = 766167;
q[55][35] = 424901;
q[55][36] = 215849;
q[55][37] = 102008;
q[55][38] = 43377;
q[55][39] = 17436;
q[55][40] = 6095;
q[55][41] = 2020;
q[55][42] = 569;
q[55][43] = 157;
q[55][44] = 34;
q[55][45] = 5;
q[55][46] = 2;
q[56][2] = 1;
q[56][3] = 2;
q[56][4] = 4;
q[56][5] = 34;
q[56][6] = 49;
q[56][7] = 84;
q[56][8] = 312;
q[56][9] = 809;
q[56][10] = 1315;
q[56][11] = 3412;
q[56][12] = 7479;
q[56][13] = 16103;
q[56][14] = 36456;
q[56][15] = 76409;
q[56][16] = 153081;
q[56][17] = 299842;
q[56][18] = 552282;
q[56][19] = 962617;
q[56][20] = 1580376;
q[56][21] = 2439281;
q[56][22] = 3525357;
q[56][23] = 4781004;
q[56][24] = 6063106;
q[56][25] = 7191681;
q[56][26] = 7963132;
q[56][27] = 8239749;
q[56][28] = 7955930;
q[56][29] = 7171806;
q[56][30] = 6016396;
q[56][31] = 4705372;
q[56][32] = 3423563;
q[56][33] = 2312324;
q[56][34] = 1451445;
q[56][35] = 844812;
q[56][36] = 453081;
q[56][37] = 224137;
q[56][38] = 102600;
q[56][39] = 42878;
q[56][40] = 16522;
q[56][41] = 5662;
q[56][42] = 1781;
q[56][43] = 482;
q[56][44] = 123;
q[56][45] = 26;
q[56][46] = 6;
q[56][47] = 1;
q[57][1] = 1;
q[57][3] = 27;
q[57][5] = 41;
q[57][6] = 323;
q[57][7] = 74;
q[57][8] = 214;
q[57][9] = 1400;
q[57][10] = 2755;
q[57][11] = 2979;
q[57][12] = 7305;
q[57][13] = 17848;
q[57][14] = 40560;
q[57][15] = 80870;
q[57][16] = 156496;
q[57][17] = 317488;
q[57][18] = 601588;
q[57][19] = 1073789;
q[57][20] = 1795058;
q[57][21] = 2842655;
q[57][22] = 4208837;
q[57][23] = 5880830;
q[57][24] = 7663771;
q[57][25] = 9386973;
q[57][26] = 10710235;
q[57][27] = 11463004;
q[57][28] = 11444692;
q[57][29] = 10701482;
q[57][30] = 9320082;
q[57][31] = 7588477;
q[57][32] = 5741359;
q[57][33] = 4058477;
q[57][34] = 2660101;
q[57][35] = 1624428;
q[57][36] = 916027;
q[57][37] = 479674;
q[57][38] = 230988;
q[57][39] = 103408;
q[57][40] = 41827;
q[57][41] = 15958;
q[57][42] = 5257;
q[57][43] = 1627;
q[57][44] = 471;
q[57][45] = 111;
q[57][46] = 36;
q[57][47] = 4;
q[58][2] = 1;
q[58][3] = 2;
q[58][4] = 4;
q[58][5] = 35;
q[58][6] = 50;
q[58][7] = 86;
q[58][8] = 318;
q[58][9] = 841;
q[58][10] = 1343;
q[58][11] = 3515;
q[58][12] = 7736;
q[58][13] = 16726;
q[58][14] = 38521;
q[58][15] = 82428;
q[58][16] = 169220;
q[58][17] = 342114;
q[58][18] = 651659;
q[58][19] = 1182778;
q[58][20] = 2028882;
q[58][21] = 3283152;
q[58][22] = 4989866;
q[58][23] = 7141238;
q[58][24] = 9579057;
q[58][25] = 12049803;
q[58][26] = 14199444;
q[58][27] = 15676328;
q[58][28] = 16197281;
q[58][29] = 15668763;
q[58][30] = 14155834;
q[58][31] = 11956416;
q[58][32] = 9427267;
q[58][33] = 6930291;
q[58][34] = 4750206;
q[58][35] = 3029613;
q[58][36] = 1795035;
q[58][37] = 986412;
q[58][38] = 502376;
q[58][39] = 236069;
q[58][40] = 102731;
q[58][41] = 40778;
q[58][42] = 14784;
q[58][43] = 4861;
q[58][44] = 1474;
q[58][45] = 403;
q[58][46] = 82;
q[58][47] = 23;
q[58][48] = 2;
q[58][49] = 1;
q[59][1] = 1;
q[59][3] = 28;
q[59][5] = 43;
q[59][6] = 348;
q[59][7] = 76;
q[59][8] = 219;
q[59][9] = 1509;
q[59][10] = 3017;
q[59][11] = 3052;
q[59][12] = 7608;
q[59][13] = 18753;
q[59][14] = 43532;
q[59][15] = 87217;
q[59][16] = 171443;
q[59][17] = 358520;
q[59][18] = 701897;
q[59][19] = 1300233;
q[59][20] = 2267232;
q[59][21] = 3754350;
q[59][22] = 5835554;
q[59][23] = 8586426;
q[59][24] = 11813396;
q[59][25] = 15318198;
q[59][26] = 18555590;
q[59][27] = 21139108;
q[59][28] = 22523621;
q[59][29] = 22542186;
q[59][30] = 21078072;
q[59][31] = 18475460;
q[59][32] = 15110300;
q[59][33] = 11568351;
q[59][34] = 8255368;
q[59][35] = 5501887;
q[59][36] = 3409347;
q[59][37] = 1969264;
q[59][38] = 1052508;
q[59][39] = 523725;
q[59][40] = 239754;
q[59][41] = 101947;
q[59][42] = 39537;
q[59][43] = 14177;
q[59][44] = 4542;
q[59][45] = 1353;
q[59][46] = 353;
q[59][47] = 89;
q[59][48] = 16;
q[59][49] = 5;
q[59][50] = 1;
q[60][2] = 1;
q[60][3] = 2;
q[60][4] = 3;
q[60][5] = 34;
q[60][6] = 47;
q[60][7] = 78;
q[60][8] = 302;
q[60][9] = 812;
q[60][10] = 1217;
q[60][11] = 3272;
q[60][12] = 7245;
q[60][13] = 15712;
q[60][14] = 37013;
q[60][15] = 79895;
q[60][16] = 167875;
q[60][17] = 346736;
q[60][18] = 678366;
q[60][19] = 1266558;
q[60][20] = 2241078;
q[60][21] = 3748388;
q[60][22] = 5903943;
q[60][23] = 8760872;
q[60][24] = 12206114;
q[60][25] = 15974874;
q[60][26] = 19609442;
q[60][27] = 22571394;
q[60][28] = 24339722;
q[60][29] = 24587542;
q[60][30] = 23250873;
q[60][31] = 20552576;
q[60][32] = 16986772;
q[60][33] = 13099723;
q[60][34] = 9429440;
q[60][35] = 6329481;
q[60][36] = 3948081;
q[60][37] = 2289058;
q[60][38] = 1230258;
q[60][39] = 613548;
q[60][40] = 282015;
q[60][41] = 119237;
q[60][42] = 46135;
q[60][43] = 16552;
q[60][44] = 5394;
q[60][45] = 1629;
q[60][46] = 435;
q[60][47] = 106;
q[60][48] = 24;
q[60][50] = 1;
q[60][51] = 1;

	scanf("%lld", &n);
	solve();
	return 0;
}