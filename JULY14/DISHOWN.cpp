/*
ID: ashish1610
PROG: Dish Owner
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct dish
{
	int own;
	int score;
};
int par[10005];
int find_par(int i)
{
	while(i!=par[i])
	{
		par[i]=par[par[i]];
		i=par[i];
	}
	return i;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=10000;++i)
			par[i]=i;
		int n;
		scanf("%d",&n);
		dish ds[n+1];
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&ds[i].score);
			ds[i].own=i;
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				int d;
				scanf("%d",&d);
				int ans=find_par(d);
				printf("%d\n",ans);
			}
			else
			{
				int x,y;
				scanf("%d %d",&x,&y);
				int p1=find_par(x);
				int p2=find_par(y);
				if(p1==p2)
					printf("Invalid query!\n");
				else
				{
					if(ds[p1].score>ds[p2].score)
						par[p2]=p1;
					else if(ds[p1].score<ds[p2].score)
						par[p1]=p2;
				}
			}
		}
	}
	return 0;
}
