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
inline void inp(I &n) 
{
    	n=0;
	I ch=getchar_unlocked();
	I sign=1;
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
	I n,i,j;
	inp(n);
	I ar[n+1][n+1],arr[n+1][n+1][11];
	RESET(arr,0);
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			inp(ar[i][j]);
		}
	}
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			arr[i][j][ar[i][j]]++;
			I k;
			FOR(k,1,11)
			{
				arr[i][j][k]+=arr[i-1][j][k]+arr[i][j-1][k]-arr[i-1][j-1][k];
			}
		}
	}
	I q;
	inp(q);
	W(q)
	{
		I x1,x2,y1,y2;
		inp(x1),inp(y1),inp(x2),inp(y2);
		I ans=0;
		FOR(i,1,11)
		{
			I temp = arr[x2][y2][i]-arr[x1-1][y2][i]-arr[x2][y1-1][i]+arr[x1-1][y1-1][i];
			if(temp>0)
			{
				ans++;
			}
		}
		pin(ans);
	} 
	return 0;
}
