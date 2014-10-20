/*
ID: ashish1610
PROG: Chef and Subarray
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ar[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",&ar[i]);
	ll prod=1;
	int ans=0,tmp=0;
	for(int i=0;i<n;++i)
	{
		prod*=ar[i];
		if(prod==0)
		{
			ans=max(ans,tmp);
			tmp=0;
			prod=1;
		}
		else
			tmp++;
	}
	ans=max(tmp,ans);
	printf("%d\n",ans);
	return 0;
}
