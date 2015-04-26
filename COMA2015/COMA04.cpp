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
ll ar[205], dp[205][205];
int main()
{
	int t, i, j, k, l;
	si(t);
	rep(i, 1, t)
	{
		int n, q, tmp;
		si(n);
		si(q);
		memset(dp, 0, sizeof(dp));
		rep(j, 1, n)
			sl(ar[j]);
		rep(j, 1, n)
			dp[j][1] = 1;
		rep(j, 1, n)
		{
			rep(k, 1, j - 1)
			{
				if(ar[j] > ar[k])
				{
					rep(l, 2, n)
					{
						dp[j][l] += dp[k][l - 1];
						dp[j][l] %= MOD;
					}
				}
			}
		}
		while(q--)
		{
			si(tmp);
			ll ans = 0;
			rep(j, 1, n)
			{
				ans += dp[j][tmp];
				ans %= MOD;
			}
			pl(ans);
			pn;
		}
	}
	return 0;
}