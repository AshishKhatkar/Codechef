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
	int t, i, j;
	si(t);
	rep(i, 1, t)
	{
		ll s, c, k;
		sl(s);
		sl(c);
		sl(k);
		if(s == 0)
		{
			if(k != 1)
				printf("0\n");
			else
			{
				ll res = 0;
				rep(j, 0, c - 1)
					res += (1LL << (j + 1));
				pl(res);
				pn;
			}
		}
		else if(c == 0)
		{
			if(k > s)
				printf("0\n");
			else
			{
				ll res = (1LL << (s - k + 1)) + 1LL;
				pl(res);
				pn;
			}
		}
		else
		{
			if(k == 1)
			{
				ll res = (1LL << s) + 1LL;
				if(s <= c)
				{
					rep(j, s, c)
						res = res + (1LL << j);
				}
				pl(res);
				pn;
			}
			else if(k > s)
				printf("0\n");
			else
			{
				ll res = (1LL << (s - k + 1)) + 1LL;
				if(c >= s - k + 1)
					res = res + (1LL << (s - k + 1));
				pl(res);
				pn;
			}
		}
	}
	return 0;
}