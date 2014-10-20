/*	ashish1610	*/
/*	Algorithm : Either the offer belongs to the optimal solution or it doesn't	*/
/*	Brute Force	*/
#include<bits/stdc++.h>
using namespace std;
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
int ans;
bool offer_chosen[25], conflicts[25][25];
void compute_sol(int offer, int m)
{
	if(offer==0)
	{
		int temp_ans;
		bool flag=false;
		for(int i=1;i<=m;++i)
		{
			for(int j=i+1;j<=m;++j)
			{
				if(offer_chosen[i] && offer_chosen[j] && conflicts[i][j])
				{
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(!flag)
		{
			temp_ans=0;
			for(int i=1;i<=m;++i)
				if(offer_chosen[i])
					temp_ans++;
			ans=max(ans,temp_ans);
		}
	}
	else
	{
		/*	this offer belongs to the optimal solution	*/
		offer_chosen[offer]=true;
		compute_sol(offer-1,m);
		/*	or it doesn't belong to the optimal solution	*/
		offer_chosen[offer]=false;
		compute_sol(offer-1,m);
	}
}
int main()
{
	int n,m;
	inp(n);
	inp(m);
	//cin>>n>>m;
	bool stamps[m+1][n+1];
	memset(stamps,false,sizeof(stamps));
	memset(conflicts,false,sizeof(conflicts));
	memset(offer_chosen,false,sizeof(offer_chosen));
	for(int i=1;i<=m;++i)
	{
		int temp;
		inp(temp);
		//cin>>temp;
		for(int j=1;j<=temp;++j)
		{
			int temp1;
			inp(temp1);
			//cin>>temp1;
			stamps[i][temp1]=true;
		}
	}
	/*	marking conflicts	*/
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(stamps[j][k] && stamps[i][k])
				{
					conflicts[i][j]=true;
					conflicts[j][i]=true;
				}
			}
		}
	}
	ans=0;
	compute_sol(m,m);
	cout<<ans<<endl;
	return 0;
}
