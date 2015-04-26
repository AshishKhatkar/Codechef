/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
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
/* all subtasks */
/* ans for each n we have (m / d) choices so ans is (m / d) ^ n but we need to exclude duplicate calculations */
int dp[10000005];
void solve_subtask1_subtask2_subtask3(int n, int m, int l, int r)
{
	int low, high, cnt;
	for(low = m >> 1, high = m, cnt = 1; low != high; cnt++, high = low, low = m / (cnt + 1))
	{
		int val = pow_mod(cnt, n);
		for(int i = high + high; i <= m; i += high)
			val = (val - dp[i] + MOD) % MOD;
		for(int i = low + 1; i <= high; ++i)
			dp[i] = val;
	}
	if(high >= l)
	{
		for(int i = high; i >= l; --i)
		{
			dp[i] = pow_mod(m / i, n);
			for(int j = i + i; j <= m; j += i)
				dp[i] = (dp[i] - dp[j] + MOD) % MOD;
		}
	}
	ll res = 0;
	for(int i = l; i <= r; ++i)
		res = (res + dp[i]) % MOD;
	cout<<res<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, l, r;
		cin>>n>>m>>l>>r;
		solve_subtask1_subtask2_subtask3(n, m, l, r);
	}
	return 0;
}