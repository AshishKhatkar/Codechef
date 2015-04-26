/*
ID: ashish1610
PROG:
LANG: C++
Algorithm Reference : https://sites.google.com/site/indy256/algo/sparse_table_rmq
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int ar[100005];
int logTable[100005];
int rmq[30][100005];
int pow2[30];
void generateRMQTable(int n)
{
	int i, j;
	pow2[0] = 1;
	rep(i, 1, 29)
		pow2[i] = pow2[i - 1] << 1;
	logTable[1] = 0;
	rep(i, 2, n)
		logTable[i] = logTable[i >> 1] + 1;
	rep(i, 0, n - 1)
		rmq[0][i] = i;
	for(j = 1; pow2[j] < n; ++j)
	{
		for(i = 0; i + pow2[j] <= n; ++i)
		{
			int x = rmq[j - 1][i];
			int y = rmq[j - 1][i + (pow2[j - 1])];
			rmq[j][i] = ar[x] >= ar[y] ? x : y;
		}
	}
}
int rmqQuery(int i, int j)
{
	int logInd = logTable[j - i];
	int x = rmq[logInd][i];
	int y = rmq[logInd][j - (pow2[logInd]) + 1];
	return ar[x] >= ar[y] ? x : y;
}
int main()
{
	int n, i;
	si(n);
	rep(i, 0, n - 1)
		si(ar[i]);
	generateRMQTable(n);
	int m, x1, y1;
	si(m);
	si(x1);
	si(y1);
	ll ans = 0;
	while(m--)
	{
		ans += ar[rmqQuery(min(x1, y1), max(x1, y1))];
		x1 = (x1 + 7);
		if(x1 >= n - 1)
			x1 %= (n - 1);
		y1 = (y1 + 11);
		if(y1 >= n)
			y1 %= n;
	}
	pl(ans);
	pn;
	return 0;
}