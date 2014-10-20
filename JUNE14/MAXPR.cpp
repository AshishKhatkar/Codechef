/*
ID: ashish1610
PROG: Maxim and Progressions
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
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
int ar[200005];
ll dp1[105][205],dp2[105][205],diff[105][2];
ll exp_pow(ll a, ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2)
			res=(res*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return res;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n;
		inp(n);
		for(int i=0;i<n;++i)
			inp(ar[i]);
		for(int i=0;i<105;++i)
		{
			for(int j=0;j<205;++j)
			{
				dp1[i][j]=0;
				dp2[i][j]=0;
			}
		}
		int com_diff,tmp1,tmp2;
		for(int i=0;i<n;++i)
		{
			tmp1=ar[i];
			tmp2=1;
			dp2[tmp1][0]++;
			diff[tmp2][0]=tmp1;
			diff[tmp2][1]=0;
			tmp2++;
			for(int j=1;j<=100;++j)
			{
				com_diff=tmp1-j+100;
				diff[tmp2][0]=tmp1;
				diff[tmp2][1]=com_diff;
				dp2[tmp1][com_diff]+=(dp1[j][com_diff]+dp1[j][0]);
				if(dp2[tmp1][com_diff]>=MOD)
					dp2[tmp1][com_diff]-=MOD;
				tmp2++;
			}
			for(int j=1;j<tmp2;++j)
			{
				tmp1=diff[j][0];
				com_diff=diff[j][1];
				dp1[tmp1][com_diff]+=dp2[tmp1][com_diff];
				if(dp1[tmp1][com_diff]>=MOD)
					dp1[tmp1][com_diff]-=MOD;
				dp2[tmp1][com_diff]=0;
			}
		}
		ll ans=0;
		for(int i=1;i<=100;++i)
		{
			for(int j=0;j<=200;++j)
			{
				ans=(ans+dp1[i][j]);
				if(ans>=MOD)
					ans-=MOD;
			}
		}
		ll total=exp_pow(2,n)-1;
		ans=(total-ans+MOD)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
