/*
ID: ashish1610
PROG: Fun with Rotation
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
ll ar[100005];
int main()
{
	ll n,m;
	inp(n);
	inp(m);
	for(int i=1;i<=n;++i)
		inp(ar[i]);
	ll ind=1;
	while(m--)
	{
		char str;
		ll tmp;
		cin>>str;
		inp(tmp);
		if(str=='R')
		{
			if(tmp-ind+1>0)
				printf("%lld\n",ar[tmp-ind+1]);
			else
				printf("%lld\n",ar[tmp-ind+n+1]);
		}
		else if(str=='C')
		{
			ind-=tmp;
			if(ind<=0)
				ind+=n;
		}
		else if(str=='A')
		{
			ind+=tmp;
			if(ind>n)
				ind-=n;
		}
	}
	return 0;
}
