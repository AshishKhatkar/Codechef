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
int cst[1005];
int main()
{
	int t, i, j, n, u, v, m, k, ans;
	si(t);
	rep(i, 1, t)
	{
		ans = 0;
		si(n);
		si(m);
		rep(j, 0, n - 1)
			si(cst[j]);
		ans = 0;
		rep(j, 1, m)
		{
			si(u);
			si(v);
			u--;
			v--;
			ans += min(cst[u], cst[v]);
		}
		pi(ans);
		pn;
	}
	return 0;
}