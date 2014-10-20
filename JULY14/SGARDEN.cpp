/*
ID: ashish1610
PROG: Garden Game
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD	1000000007
#define ll	long long int
ll fact[100005],ar[100005],ar1[100005];
bool marked[100005];
/*	fast input	*/
inline void inp(long long int &n) 
{
    	n=0;
	register long long int ch=getchar_unlocked();
	long long int sign=1;
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
ll pow_mod(ll x, ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
		y/=2;
	}
	return res;
}
void factorize(ll n)
{
	ll res=0;
	for(int i=2;i<=(ll)sqrt(n);++i)
	{
		res=0;
		while(n%i==0)
		{
			res++;
			n/=i;
		}
		fact[i]=max(fact[i],res);
	}
	if(n>=2 && fact[n]==0)
		fact[n]=1;
}
int main()
{
	ll t,n,i,cnt,tmp,mx,ans;
	inp(t);
	while(t--)
	{
		inp(n);
		for(i=1;i<=n;++i)
			inp(ar[i]);
		memset(marked,false,sizeof(marked));
		memset(fact,0,sizeof(fact));
		memset(ar1,0,sizeof(ar1));
		cnt=0;
		for(i=1;i<=n;++i)
		{
			if(!marked[i])
			{
				marked[i]=true;
				int tmp=ar[i];
				ar1[cnt]=1;
				while(!marked[tmp])
				{
					ar1[cnt]++;
					marked[tmp]=true;
					tmp=ar[tmp];
				}
				cnt++;
			}
		}
		mx=0;
		for(i=0;i<cnt;++i)
		{
			factorize(ar1[i]);
			mx=max(ar1[i],mx);
		}
		ans=1;
		for(i=1;i<=mx;++i)
		{
			if(fact[i]>0)
				ans=(ans*pow_mod(i,fact[i]))%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
