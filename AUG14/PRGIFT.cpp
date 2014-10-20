/*
ID: ashish1610
PROG: Chef and Gift
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,tmp,e_cnt=0;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&tmp);
			if(!(tmp&1))
				e_cnt++;
		}
		if(k==0 && e_cnt==n)
			printf("NO\n");
		else if(k==0)
			printf("YES\n");
		else if(e_cnt>=k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
