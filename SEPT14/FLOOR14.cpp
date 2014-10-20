/*
ID: ashish1610
PROG: Flooring
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*	fast input	*/
inline void inp(ll &n) 
{
    	n=0;
	register ll ch=getchar_unlocked();
	ll sign=1;
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
ll compute(ll n, ll mod)
{
	mod*=30;
	n%=mod;
	ll res=(((((n*(n+1))%mod)*(2*n+1))%mod)*((3*n*n+3*n-1+mod)%mod))%mod;
	res/=30;
	return res;
}
int main()
{
	ll t,n,m,ans,lft,rgt,tmp;
	inp(t);
	while(t--)
	{
		inp(n);
		inp(m);
		ans=0,lft=1;
		while(lft<=n)
		{
			tmp=n/lft;
			rgt=n/tmp;
			rgt++;
			tmp%=m;
			ans=(ans+tmp*((compute(rgt-1, m)-compute(lft-1,m)+m)%m))%m;
			lft=rgt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
