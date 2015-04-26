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
ll num[1000015], den[1000015];
void pre_compute()
{
	int i;
	num[0] = 1;
	rep(i, 1, 1000014)
		num[i] = (num[i - 1] * 1LL * i) % MOD;
	rep(i, 0, 1000014)
		den[i] = pow_mod(num[i], MOD - 2);
}
int main()
{
	pre_compute();
	int t, i;
	si(t);
	rep(i, 1, t)
	{
		int n;
		si(n);
		if(n < 6)
			printf("FIGHT\n");
		else
		{
			ll res = num[n - 1];
			res = (res * den[n - 6]) % MOD;
			res = (res * den[5]) % MOD;
			pl(res);
			pn;
		}
	}
	return 0;
}