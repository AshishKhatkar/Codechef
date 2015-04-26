/*
ID: ashish1610
PROG:
LANG: C++
Question same as ADVEDIST on SPOJ
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
int main()
{
	int t;
	si(t);
	while(t--)
	{
		string str, str1;
		cin>>str>>str1;
		int len = str.length();
		int len1 = str1.length();
		assert(len >= 1 && len <= 100);
		assert(len1 >= 1 && len1 <= 100);
		int dp[len + 1][len1 + 1];
		int i, j, k;
		rep(i, 0, len)
			dp[i][0] = i;
		rep(i, 0, len1)
			dp[0][i] = i;
		str = "*" + str;
		str1 = "*" + str1;
		rep(i, 1, len)
		{
			rep(j, 1, len1)
			{
				// assert(str[i] >= 'a' && str[i] <= 'z');
				// assert(str1[j] >= 'a' && str1[j] <= 'z');
				if(str[i] == str1[j])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(dp[i][j], min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
				rrep(k, i - 1, 1)
				{
					if(str[i] == str1[j - 1] && str[k] == str1[j] && j >= 2)
						dp[i][j] = min(dp[i][j], dp[k - 1][j - 2] + i - k);
				}
			}
		}
		int ans = dp[len][len1];
		swap(len, len1);
		int dp1[len + 1][len1 + 1];
		rep(i, 0, len)
			dp1[i][0] = i;
		rep(i, 0, len1)
			dp1[0][i] = i;
		swap(str, str1);
		rep(i, 1, len)
		{
			rep(j, 1, len1)
			{
				// assert(str[i] >= 'a' && str[i] <= 'z');
				// assert(str1[j] >= 'a' && str1[j] <= 'z');
				if(str[i] == str1[j])
					dp1[i][j] = dp1[i - 1][j - 1];
				else
					dp1[i][j] = dp1[i - 1][j - 1] + 1;
				dp1[i][j] = min(dp1[i][j], min(dp1[i][j - 1] + 1, dp1[i - 1][j] + 1));
				rrep(k, i - 1, 1)
				{
					if(str[i] == str1[j - 1] && str[k] == str1[j] && j >= 2)
						dp1[i][j] = min(dp1[i][j], dp1[k - 1][j - 2] + i - k);
				}
			}
		}
		pi(min(ans, dp1[len][len1]));
		pn;
	}
	return 0;
}