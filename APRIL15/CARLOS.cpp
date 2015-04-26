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
int ar[200005];
bool conn[205][205];
int dp[200005][205];
int main()
{
	int t;
	si(t);
	while(t--)
	{
		memset(conn, false, sizeof(conn));
		int m, k, n, x, y, i, j, l;
		si(m);
		si(k);
		si(n);
		rep(i, 0, k - 1)
		{
			si(x);
			si(y);
			conn[x][y] = true;
			conn[y][x] = true;
		}
		rep(i, 1, n)
			si(ar[i]);
		/* Compute transitive closure of graph */
		rep(l, 1, m)
			rep(i, 1, m)
				rep(j, 1, m)
					conn[i][j] = conn[i][j] || (conn[i][l] && conn[l][j]);
		// dp[i][j] denotes min no of inversions such that ith position have value less than equal to j
		rep(j, 1, m)
		{
			if(ar[1] == j)
				dp[1][j] = 0;
			else if(conn[ar[1]][j])
			{
				if(j == 1)
					dp[1][j] = 1;
				else
					dp[1][j] = min(dp[1][j - 1], 1);
			}
			else if(j == 1)
				dp[1][j] = INT_MAX;
			else
				dp[1][j] = dp[1][j - 1];
		}
		rep(i, 2, n)
		{
			int val = ar[i];
			rep(j, 1, m)
			{
				if(val == j)
				{
					if(dp[i - 1][j] == INT_MAX)
					{
						if(j == 1)
							dp[i][j] = INT_MAX;
						else
							dp[i][j] = dp[i][j - 1];
					}
					else if(j == 1)
						dp[i][j] = dp[i - 1][j];
					else
						dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
				}
				else if(conn[val][j])
				{
					if(dp[i - 1][j] == INT_MAX)
					{
						if(j == 1)
							dp[i][j] = INT_MAX;
						else
							dp[i][j] = dp[i][j - 1];
					}
					else if(j == 1)
						dp[i][j] = dp[i - 1][j] + 1;
					else
						dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1]);
				}
				else if(j == 1)
					dp[i][j] = INT_MAX;
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
		assert(dp[n][m] >= 0);
		if(dp[n][m] == INT_MAX)
			printf("-1\n");
		else
		{
			pi(dp[n][m]);
			pn;
		}
	}
	return 0;
}