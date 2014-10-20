/*
*
*	ashish1610
*
*/

/**************HEADERS*****************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>

using namespace std;

/**************MACROS*****************/

#define PB			push_back
#define MP			make_pair
#define RESET(n,m)		memset(n,m,sizeof(n))
#define	INF			INT_MAX
#define ALL(x)			x.begin(),x.end()
#define vi			vector<int>
#define vl			vector<long long int>
#define pii			pair<int, int>
#define pll			pair<long long int, long long int>
#define I			int
#define LLI			long long int
#define LI			long int
#define F			float
#define D			double
#define SL(n)			strlen(n)
#define max3(a,b,c)		max(a,max(b,c))
#define min3(a,b,c)		min(a,min(b,c))
#define FOR(i,n,m)		for(i=n;i<m;++i)
#define REP(i,n)		FOR(i,0,n)
#define REPI(i,n)		for(i=n;i>=0;--i)
#define W(n)			while(n--)
#define si(n)			scanf("%d",&n)
#define sl(n)			scanf("%lld",&n)
#define sf(n)			scanf("%f",&n)
#define slf(n)			scanf("%lf",&n);
#define si2(n,m)		scanf("%d %d",&n,&m)
#define sl2(n,m)		scanf("%lld %lld",&n,&m)
#define si3(n,m,p)		scanf("%d %d %d",&n,&m,&p)
#define sf2(n,m)		scanf("%f %f",&n,&m)
#define sf3(n,m,p)		scanf("%f %f %f",&n,&m)
#define ss(n)			scanf("%s",&n)
#define sc(n)			scanf(" %c",&n)
#define pis(n)			printf("%d ",n)
#define pin(n)			printf("%d\n",n)
#define pln(n)			printf("%lld\n",n)
#define pin2(n,m)		printf("%d %d\n",n,m)
#define pfs(n)			printf("%f ",n)
#define pfn(n)			printf("%f\n",n)
#define pf6s(n)			printf("%.6f ",n)
#define pf6n(n)			printf("%.6f\n",n)
#define pfn2(n,m)		printf("%f %f\n",n,m)
#define pf6n2(n,m)		printf("%.6f %.6f\n",n,m)
#define plfs(n)			printf("%lf ",n)
#define plfn(n)			printf("%lf\n",n)
#define plf6s(n)		printf("%.6lf ",n)
#define plf6n(n)		printf("%.6lf\n",n)
#define plfn2(n,m)		printf("%lf %lf\n",n,m)
#define plf6n2(n,m)		printf("%.6lf %.6lf\n",n,m)
#define pcs(n)			printf("%c ",n)
#define pcn(n)			printf("%c\n",n)
#define pss(n)			printf("%s ",n)
#define psn(n)			printf("%s\n",n)

/*Fast Input*/
inline void inp(LLI &n) 
{
    	n=0;
	LLI ch=getchar_unlocked();
	LLI sign=1;
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
	LLI t;
	inp(t);
	W(t)
	{
		LLI n,k,i;
		inp(n),inp(k);
		LLI ar[n];
		REP(i,n)
		{
			inp(ar[i]);
		}
		LLI lr[n],rl[n];
		LLI temp=ar[0];
		lr[0]=ar[0];
		FOR(i,1,n)
		{
			temp+=ar[i];
			if(temp<ar[i])
			{
				temp=ar[i];
			}
			lr[i]=max(lr[i-1],temp);
		}
		temp=ar[n-1];
		rl[n-1]=ar[n-1];
		REPI(i,n-2)
		{
			temp+=ar[i];
			if(temp<ar[i])
			{
				temp=ar[i];
			}
			rl[i]=max(rl[i+1],temp);
		}
		LLI ans=lr[0]+rl[n-1];
		REP(i,n-k-1)
		{
			if((lr[i]+rl[i+k+1])>ans)
			{
				ans=lr[i]+rl[i+k+1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
