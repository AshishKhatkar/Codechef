/*
ID: ashish1610
PROG:
LANG: C++
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
ll dp[15][305][1805];
ll f(int r, int b, int l)
{
	if(b == 1)
	{
		if(r == 4 || r == 6)
		{
			dp[l][b][r] = 1;
			return dp[l][b][r];
		}
		if(r == 0 && l == 0)
		{
			dp[l][b][r] = 1;
			return dp[l][b][r];
		}
		if(r == 0 && l > 0)
		{
			dp[l][b][r] = 2;
			return dp[l][b][r];
		}
		return 0;
	}
	if(dp[l][b][r] != -1)
		return dp[l][b][r];
	ll res = 0;
	if(b > 0)
	{
		if(r >= 6)
			res = (res + f(r - 6, b - 1, l)) % MOD;
		if(r >= 4)
			res = (res + f(r - 4, b - 1, l)) % MOD;
		if(l > 0)
			res = (res + f(r, b - 1, l - 1)) % MOD;
		if(r >= 0)
			res = (res + f(r, b - 1, l)) % MOD;
	}
	dp[l][b][r] = res;
	return dp[l][b][r];
}
int main()
{
	int t, i, j, k;
	si(t);
	memset(dp, -1, sizeof(dp));
	rep(i, 1, t)
	{
		int r, b, l;
		si(r);
		si(b);
		si(l);
		if((r & 1) || r > 6 * b)
			printf("0\n");
		else
		{
			ll ans = f(r, b, l);
			pl(ans);
			pn;
		}
	}
	return 0;
}