/*
ID: ashish1610
PROG: Cleaning tables
LANG: C++
*/
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
int main()
{
	int t,n,m,ans,c,j,mx,mx_index,k,ar[405],i,tab[205];
	inp(t);
	//scanf("%d",&t);
	bool again=false;
	list<int> v[405];
	while(t--)
	{
		ans=0;
		memset(tab,-1,sizeof(tab));
		for(i=0;i<405;++i)
			v[i].clear();
		inp(n);
		inp(m);
		//scanf("%d %d",&n,&m);
		for(i=0;i<m;++i)
		{
			inp(ar[i]);
			//scanf("%d",&ar[i]);
			v[ar[i]].push_back(i);
		}
		for(i=0;i<m;++i)
		{
			j=0;
			again=false;
			while(j<n && tab[j]!=-1)
			{
				if(tab[j]==ar[i])
				{
					again=true;
					break;
				}
				j++;
			}
			if(again)
			{
				v[ar[i]].pop_front();
			}
			else
			{
				if(j!=n)
					tab[j]=ar[i];
				else
				{
					mx=-1;
					mx_index=-1;
					for(k=0;k<n;++k)
					{
						if(v[tab[k]].size()==0)
						{
							mx_index=k;
							break;
						}
						if(mx<*v[tab[k]].begin())
						{
							mx=*v[tab[k]].begin();
							mx_index=k;
						}
					}
					if(mx_index!=-1)
						tab[mx_index]=ar[i];
				}
				ans++;
				v[ar[i]].pop_front();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
