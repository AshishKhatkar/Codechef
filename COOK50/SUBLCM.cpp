/*
ID: ashish1610
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
#define sl(i)	scanf("%lld",&i)
#define pl(i)	printf("%lld\n",i)
ll ar[100005];
ll prime[1000005],prime_cnt[1000005],cnt=0,tmp[1000005];
void sieve()
{
	memset(prime,0,sizeof(prime));
	memset(prime_cnt,0,sizeof(prime_cnt));
	prime[0]=1;
	prime[1]=1;
	cnt=0;
	for(int i=2;i<=1000000;++i)
	{
		if(prime[i]==0)
		{
			prime_cnt[i]=cnt;
			cnt++;
			for(int j=2*i;j<=1000000;j+=i)
				prime[j]=i;
		}
	}
}
int main()
{
	sieve();
	ll t;
	sl(t);
	while(t--)
	{
		ll n;
		sl(n);
		for(int i=0;i<n;++i)
			sl(ar[i]);
		for(int i=0;i<cnt;++i)
			tmp[i]=-1;
		ll ans=0,ind=-1,tmp_ind,j,tmp1;
		for(int i=0;i<n;++i)
		{
			tmp_ind=-1;
			j=ar[i];
			while(j>1)
			{
				tmp1=prime[j];
				if(tmp1==0)
					tmp1=j;
				tmp_ind=max(tmp[prime_cnt[tmp1]],tmp_ind);
				tmp[prime_cnt[tmp1]]=i;
				while(j%tmp1==0)
					j/=tmp1;
			}
			if(tmp_ind!=-1)
				ind=max(ind,tmp_ind);
			ans=max(ans,i-ind);
		}
		if(ans>=2)
			pl(ans);
		else
			pl(-1LL);
	}
	return 0;
}
