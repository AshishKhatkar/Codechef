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
int main()
{
	int t, i, len, ans1, ans2, char_cnt, j;
	si(t);
	rep(i, 1, t)
	{
		string str;
		cin>>str;
		len = str.length();
		ans1 = 0;
		ans2 = 0;
		for(int j = 1; j < len; j += 2)
		{
			if(str[j - 1] == '+' && str[j] == '+')
			{
				ans1++;
				ans2++;
			}
			else if(str[j - 1] == '-' && str[j] == '-')
			{
				ans1++;
				ans2++;
			}
			else if(str[j - 1] == '-' && str[j] == '+')
				ans1 += 2;
			else if(str[j - 1] == '+' && str[j] == '-')
				ans2 += 2;
		}
		if((len & 1) && str[len - 1] == '-')
			ans1++;
		else if((len & 1) && str[len - 1] == '+')
			ans2++;
		pi(min(ans1, ans2));
		pn;
	}
	return 0;
}