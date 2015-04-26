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
ll ar[100005], fact[10000005][2];
int main()
{
	int n, m, i;
	si(n);
	si(m);
	rep(i, 0, n - 1)
		sl(ar[i]);
	fact[1][0] = 1;
	fact[1][1] = 1;
	rep(i, 2, m - 1)
	{
		fact[i][0] = (i * fact[i - 1][0]) % m;
		fact[i][1] = (fact[i - 1][1] + i * fact[i][0]) % m;
	}
	ll ans = 0, val, tmp;
	rep(i, 0, n - 1)
	{
		if(ar[i] >= m)
			val = fact[m - 1][1];
		else
			val = fact[ar[i]][1];
		if(ar[i] & 1)
		{
			tmp = (ar[i] % m);
			tmp = (tmp * tmp) % m;
			tmp = (tmp * (((ar[i] + 1) / 2) % m)) % m;
		}
		else
		{
			tmp = (ar[i] % m);
			tmp = (tmp * ((ar[i] + 1) % m)) % m;
			tmp = (tmp * ((ar[i] / 2) % m)) % m;
		}
		ans = (ans + val + tmp) % m;
	}
	pl(ans);
	pn;
	return 0;
}