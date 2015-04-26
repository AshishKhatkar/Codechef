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
vector<int>fact[1005];
void fac(int n)
{
	int ind = n, i;
	rep(i, 2, (int)(sqrt(n)))
	{
		int val = 1;
		while(n % i == 0)
		{
			n /= i;
			val *= i;
		}
		if(val != 1)
			pb(fact[ind], val);
	}
	if(n >= 2)
		pb(fact[ind], n);
}
void pre_compute()
{
	int i, j;
	rep(i, 2, 1000)
		fac(i);
}
int main()
{
	pre_compute();
	int t, i;
	si(t);
	rep(i, 1, t)
	{
		ll n, m, l, r, j, k, var;
		sl(n);
		sl(m);
		sl(l);
		sl(r);
		ll poss_ans = pow_mod(m, n);
		poss_ans = (poss_ans * (r - l + 1)) % MOD;
		rep(j, l, r)
		{
			ll val = 0;
			rep(k, 1, (1 << fact[j].size()) - 1)
			{
				int v1 = -1, v2 = -1, v3 = -1, v4 = -1, cnt_bits = 0;
				rep(var, 0, fact[j].size() - 1)
				{
					if(k & (1 << var))
					{
						cnt_bits++;
						if(v1 == -1)
							v1 = fact[j][var];
						else if(v2 == -1)
							v2 = fact[j][var];
						else if(v3 == -1)
							v3 = fact[j][var];
						else
							v4 = fact[j][var];
					}
				}
				ll cnt1 = 0;
				if(v1 != -1 && v2 != -1 && v3 != -1 && v4 != -1)
				{
					int val1;
					rep(val1, 1, m)
					{
						if((val1 % v1) && (val1 % v2) && (val1 % v3) && (val1 % v4))
							cnt1++;
					}
				}
				else if(v1 != -1 && v2 != -1 && v3 != -1)
				{

					int val1;
					rep(val1, 1, m)
					{
						if((val1 % v1) && (val1 % v2) && (val1 % v3))
							cnt1++;
					}
				}
				else if(v1 != -1 && v2 != -1)
				{
					int val1;
					rep(val1, 1, m)
					{
						if((val1 % v1) && (val1 % v2))
							cnt1++;
					}
				}
				else if(v1 != -1)
				{
					int val1;
					rep(val1, 1, m)
					{
						if((val1 % v1))
							cnt1++;
					}
				}
				if(cnt1 == 0)
					continue;
				if(cnt_bits & 1)
					val = (val + pow_mod(cnt1, n)) % MOD;
				else
					val = (val - pow_mod(cnt1, n) + MOD) % MOD;
			}
			poss_ans = (poss_ans - val + MOD) % MOD;
		}
		pl(poss_ans);
		pn;
	}
	return 0;
}