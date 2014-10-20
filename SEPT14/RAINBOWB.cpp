/*
ID: ashish1610
PROG: Chef and Rainbow Array 2
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll ans[1000005];
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
	ans[0]=ans[1]=ans[2]=ans[3]=ans[4]=ans[5]=0;
	ans[6]=1;
	for(int i=7;i<=1000000;++i)
		ans[i]=(7*(ans[i-1]-ans[i-6]+MOD)%MOD + 21*(ans[i-5]-ans[i-2]+MOD)%MOD + 35*(ans[i-3]-ans[i-4]+MOD)%MOD + ans[i-7])%MOD;ll n;
	inp(n);
	if(n&1)
		printf("%lld\n",ans[n>>1]);
	else
		printf("%lld\n",ans[(n>>1)-1]);
	return 0;
}
