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
char str[1000005];
ll cnt[4][1000005];
ll dp[4][4][1000005];
map<char, int> mp;
map<int, char> mp1;
int main()
{
	mp['c'] = 0;
	mp['h'] = 1;
	mp['e'] = 2;
	mp['f'] = 3;
	mp1[0] = 'c';
	mp1[1] = 'h';
	mp1[2] = 'e';
	mp1[3] = 'f';
	scanf("%s", str);
	int len = strlen(str), l, r, i, j, k;
	char ch1, ch2;
	cnt[mp[str[0]]][0] = 1;
	rep(i, 1, len - 1)
	{
		rep(j, 0, 3)
			cnt[j][i] = cnt[j][i - 1];
		cnt[mp[str[i]]][i]++;
	}
	rep(i, 1, len - 1)
	{
		rep(j, 0, 3)
		{
			rep(k, 0, 3)
			{
				dp[j][k][i] = dp[j][k][i - 1];
				if(mp1[k] == str[i])
					dp[j][k][i] += cnt[j][i - 1];
			}
		}
	}
	int q;
	si(q);
	while(q--)
	{
		scanf(" %c %c", &ch1, &ch2);
		si(l);
		si(r);
		l--;
		r--;
		ll res = dp[mp[ch1]][mp[ch2]][r] - dp[mp[ch1]][mp[ch2]][l - 1] - cnt[mp[ch1]][l - 1] * (cnt[mp[ch2]][r] - cnt[mp[ch2]][l - 1]);
		pl(res);
		pn;
	}
	return 0;
}