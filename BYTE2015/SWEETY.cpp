/*
ID: ashish1610
PROG:
LANG: C++
Same as ROCK on spoj
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
int dp[205];
int main()
{
	int t, i, j, k;
	si(t);
	rep(i, 1, t)
	{
		string str;
		cin>>str;
		int len = str.length();
		rep(j, 0, 204)
			dp[j] = INT_MIN;
		dp[len] = 0;
		int res = 0;
		rep(j, 0, len - 1)
		{
			if(str[j] == '1')
			{
				int tmp = res;
				rrep(k, 2 * len, 1)
				{
					dp[k] = dp[k - 1] + 1;
					if(k > len && dp[k] > res)
						res = dp[k];
				}
				dp[len] = max(dp[len], tmp);
			}
			else
			{
				int tmp = res;
				rep(k, 0, 2 * len - 1)
				{
					dp[k] = dp[k + 1] + 1;
					if(k > len && dp[k] > res)
						res = dp[k];
				}
				dp[len] = max(dp[len], tmp);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}