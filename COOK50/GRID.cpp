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
char str[1005][1005];
bool ar[1005][1005],ar1[1005][1005];
int main()
{
	ll t;
	sl(t);
	while(t--)
	{
		memset(ar,false,sizeof(ar));
		memset(ar1,false,sizeof(ar));
		ll n,ans=0;
		sl(n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>str[i][j];
		for(int i=0;i<n;++i)
		{
			for(int j=n-1;j>=0;--j)
			{
				if(str[i][j]=='.')
					ar1[i][j]=true;
				else
					break;
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=n-1;j>=0;--j)
			{
				if(str[j][i]=='.')
					ar[j][i]=true;
				else
					break;
			}
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(ar[i][j] && ar1[i][j])
					ans++;
		pl(ans);
	}
	return 0;
}
