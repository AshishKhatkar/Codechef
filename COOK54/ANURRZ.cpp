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
int dp[1005][1005], ar[1005];
int main()
{
	int t, i, n, j, k, val;
	ll ans;
	si(t);
	rep(i, 1, t)
	{
		si(n);
		rep(j, 1, n)
			si(ar[j]);
		dp[0][0] = 1;
		rep(j, 1, n)
		{
			val = 0;
			rrep(k, max(j, ar[j]), 1)
			{
				val += dp[j - 1][k - 1];
				if(val >= MOD)
					val %= MOD;
				dp[j][k] = 0;
				if(k <= ar[j])
					dp[j][k] += val;
			}
		}
		ans = 0;
		rep(j, 1, n)
			ans += dp[n][j];
		if(ans >= MOD)
			ans %= MOD;
		pl(ans);
		pn;
	}
	return 0;
}