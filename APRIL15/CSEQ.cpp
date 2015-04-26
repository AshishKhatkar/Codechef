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
#define MOD				1000003
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
ll fac[1000005];
void pre_compute()
{
	fac[0] = 1;
	int i;
	rep(i, 1, 1000003)
		fac[i] = (fac[i - 1] * i) % MOD;
}
vector<int> modBaseRep(int n)
{
	vector<int> res;
	while(n)
	{
		res.push_back(n % MOD);
		n /= MOD;
	}
	return res;
}
ll nCr(int n, int r)
{
	vector<int> nRep = modBaseRep(n);
	vector<int> rRep = modBaseRep(r);
	while(rRep.size() < nRep.size())
		rRep.push_back(0);
	int sz = rRep.size();
	assert(sz == (int)(nRep.size()));
	ll ans = 1, tmp;
	int i;
	rep(i, 0, sz - 1)
	{
		if(nRep[i] < rRep[i])
			return 0;
		tmp = fac[nRep[i]];
		tmp = (tmp * pow_mod(fac[rRep[i]], MOD - 2)) % MOD;
		tmp = (tmp * pow_mod(fac[nRep[i] - rRep[i]], MOD - 2)) % MOD;
		ans = (ans * tmp) % MOD;
	}
	return ans;
}
int main()
{
	int t;
	pre_compute();
	si(t);
	while(t--)
	{
		int n, l, r;
		si(n);
		si(l);
		si(r);
		r = r - l + 1;
		n = n + r;
		pl((nCr(n, r) - 1 + MOD) % MOD);
		pn;
	}
	return 0;
}