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
bool blocked[1005][1005];
ll dp[1005][1005];
int main()
{
	memset(blocked, false, sizeof(blocked));
	int n, m, p, i, j, u, v;
	si(n);
	si(m);
	si(p);
	rep(i, 1, p)
	{
		si(u);
		si(v);
		blocked[u][v] = true;
	}
	memset(dp, 0, sizeof(dp));
	if(blocked[1][1])
		printf("0\n");
	else
	{
		dp[1][1] = 1;
		rep(i, 1, n)
		{
			rep(j, 1, m)
			{
				if(i == 1 && j == 1)
					continue;
				if(!blocked[i][j])
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
				else
					dp[i][j] = 0;
			}
		}
		pl(dp[n][m]);
		pn;
	}
	return 0;
}