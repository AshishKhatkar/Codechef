/*
ID: ashish1610
PROG: Little Elephant and Painting
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll 	long long int
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
double ncr[105][105],cnt[105][105],sm[105];
int ind[105];
void pascal()
{
	int i,j;
	ncr[0][0]=1.0;
	for(i=1;i<=100;++i)
	{
		ncr[0][i]=0.0;
		ncr[i][0]=ncr[i-1][0]/2.0;
	}
	for(i=1;i<=100;++i)
		for(j=1;j<=i;++j)
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])/2.0;
}
int main()
{
	memset(ncr,0,sizeof(ncr));
	pascal();
	int t,n,k,c,l,r,i,j,m;
	double ans=0;
	inp(t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		inp(n),inp(c),inp(k);
		sm[0]=1.0;
		sm[1]=0.0;
		for(i=0;i<c;++i)
		{
			cnt[1][i]=1;
			sm[1]+=(i*1.0)/c;
		}
		for(i=2;i<=100;++i)
		{
			sm[i]=0;
			for(j=0;j<c;++j)
				for(m=0;m<c;++m)
					cnt[i][(m*j)%c]+=cnt[i-1][j];
			for(j=0;j<c;++j)
				sm[i]+=(j*cnt[i][j]);
			for(j=1;j<=i;++j)
				sm[i]/=c;
		}
		memset(ind,0,sizeof(ind));
		while(k--)
		{
			inp(l),inp(r);
			for(i=l;i<=r;++i)
				ind[i]++;
		}
		ans=0;
		for(i=1;i<=n;++i)
			for(j=0;j<=ind[i];++j)
				ans+=(ncr[ind[i]][j]*sm[j]);
		printf("%0.9f\n",ans);
	}
	return 0;
}
