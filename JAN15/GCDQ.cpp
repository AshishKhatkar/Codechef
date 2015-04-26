/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll			long long int
#define vi			vector<int>
#define vl			vector<ll>
#define pii			pair<int,int>
#define pil			pair<int, ll>
#define pll			pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD			1000000007
#define rep(i, a, b)		for(i=a; i<=b; ++i)
#define rrep(i, a, b)		for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 			printf("\n")
/*	fast input	*/
inline void inp(int &n) 
{
    	n=0;
	register int ch=getchar_unlocked();
	int sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
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
int gcd_f[100005], gcd_b[100005], ar[100005];
int main()
{
	int t, i, n, q, j, l, r;
	inp(t);
	rep(i, 1, t)
	{
		inp(n);
		inp(q);
		rep(j, 1, n)
			inp(ar[j]);
		gcd_f[0] = 0;
		gcd_f[1] = ar[1];
		rep(j, 2, n)
			gcd_f[j] = __gcd(gcd_f[j - 1], ar[j]);
		gcd_b[n] = ar[n];
		gcd_b[n + 1] = 0;
		rrep(j, n - 1, 1)
			gcd_b[j] = __gcd(gcd_b[j + 1], ar[j]);
		rep(j, 1, q)
		{
			inp(l);
			inp(r);
			pi(__gcd(gcd_f[l - 1], gcd_b[r + 1]));
			pn;
		}
	}
	return 0;
}