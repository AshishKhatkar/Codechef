/*
ID: ashish1610
PROG: Chef and Left-Right
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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		ll ans=1;
		int len=str.length();
		for(int i=0;i<len;++i)
		{
			if(i&1)
			{
				if(str[i]=='l')
					ans=(2*ans-1)%MOD;
				else
					ans=(2*ans+1)%MOD;
			}
			else
			{
				if(str[i]=='l')
					ans=(2*ans)%MOD;
				else
					ans=(2*ans+2)%MOD;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
