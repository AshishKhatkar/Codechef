/*
ID: ashish1610
PROG: Chef and Functions
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
#define inf	1000000000
ll exp_pow(ll a, ll b)
{
	ll res=1;	
	while(b)
	{
		if(b%2)
			res=res*a;
		a=a*a;
		b/=2;
	}
	return res;
}
ll ar[10005],n,q,x,t,val,k,pr,ans,lim,ith_root,cnt=0,pre[60];
double temp;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(pre,0,sizeof(pre));
		cnt=0;
		scanf("%lld %lld",&n,&q);
		scanf("%lld",&ar[0]);
		ar[0]=(ar[0]+MOD)%MOD;
		pre[0]=ar[0];
		for(int i=1;i<n;++i)
		{
			scanf("%lld",&ar[i]);
			ar[i]=(ar[i]+MOD)%MOD;
			/*	nth_root from 60 onwards will be 1 so no need to calculate them	*/
			if(i>59)
				cnt=(cnt+ar[i])%MOD;
			else
				pre[i]=(ar[i]+pre[i-1])%MOD;
		}
		while(q--)
		{
			ans=cnt;
			pr=0;
			scanf("%lld",&x);
			ith_root=x;
			ans=(ans+(ar[0]*(x%MOD)))%MOD;
			lim=min(60LL,n);
			for(int i=2;i<=lim;++i)
			{
				ith_root=(ll)pow((float)x,1.0/(i));
				/* to make sure inbuilt pow is correct	*/
				while(exp_pow(ith_root+1,i)<=x)
					ith_root++;
				if(ith_root==1)
				{
					val=pre[lim-1]-pre[pr];
					ans=(ans+val+MOD)%MOD;
					break;
				}
				else
				{
					/*Caclulating for how many values ith_root will be same*/
					temp=log2(x)/log2(ith_root);
					while((log2(x))-((temp+1.0)*log2(ith_root))>0.000001)
						temp=temp+1.0;
					k=(ll)temp;
					if(k>lim)
						k=lim;
					val=pre[k-1]-pre[pr];
					ans=(ans+(((ith_root)%MOD)*(val+MOD))%MOD)%MOD;
					i=k;
					pr=i-1;
				}
			}
			if(q==0)
				printf("%lld\n",ans);
			else
				printf("%lld ",ans);
		}
	}
	return 0;
}
