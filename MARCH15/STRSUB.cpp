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
ll cnt[2][100005], len[100005], dp[100005];
int main()
{
	int t, i, j;
	ll ans, n, k, q, l, r;
	si(t);
	while(t--)
	{
		sl(n);
		sl(k);
		sl(q);
		string str;
		cin>>str;
		rep(i, 0, n - 1)
		{
			if(i)
			{
				cnt[0][i] = cnt[0][i - 1];
				cnt[1][i] = cnt[1][i - 1];
				cnt[str[i] - '0'][i]++;
			}
			else
			{
				cnt[0][i] = 0;
				cnt[1][i] = 0;
				cnt[str[i] - '0'][i]++;
			}
		}
		j = 0;
		rep(i, 0, n - 1)
		{
			while(j < n)
			{
				if(i == 0)
				{
					if(cnt[0][j] >= k + 1 || cnt[1][j] >= k + 1)
						break;
				}
				else
				{
					if(cnt[0][j] - cnt[0][i - 1] >= k + 1 || cnt[1][j] - cnt[1][i - 1] >= k + 1)
						break;
				}
				++j;
			}
			len[i] = j;
			if(i)
				dp[i] = dp[i - 1] + j - i;
			else
				dp[i] = j - i;
		}
		while(q--)
		{
			sl(l);
			sl(r);
			l--;
			r--;
			if(len[l] > r)
				pl(((r - l + 1) * 1LL * (r - l + 2)) / 2);
			else
			{
				int st = l, ed = r, mid;
				while(st <= ed)
				{
					mid = (st + ed) >> 1;
					if(st == mid)
					{
						if(len[ed] <= r)
							mid = ed;
						break;
					}
					if(len[mid] > r)
						ed = mid;
					else
						st = mid;
				}
				ans = ((r - mid) * 1LL * (r - mid + 1)) / 2 + dp[mid] - dp[l - 1];
				pl(ans);
			}
			pn;
		}
	}
	return 0;
}