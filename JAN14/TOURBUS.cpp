/*
*	
*	Problem : Byteland Tours
*	@author : ashish1610
*
*/
#include<bits/stdc++.h>
using namespace std;
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
int direction(pair<int,int> p, pair<int,int> q, pair<int,int> r);
bool check_intersection(pair<int,int> p1, pair<int,int> q1, pair<int,int> p2, pair<int,int> q2);
int main()
{
	int n;
	inp(n);
	vector<pair<int,int> > v;
	pair<int,int> temp;
	for(int i=0;i<n;++i)
	{
		inp(temp.first);
		inp(temp.second);
		v.push_back(temp);
	}
	bool ar[n][n];
	memset(ar,false,sizeof(ar));
	char ch[n][n];
	bool visited[n];
	memset(visited,false,sizeof(visited));
	int ans[3001][101],count=0,flag,x,y;
	for(int i=0;i<n;++i)
		cin>>ch[i];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(ch[i][j]=='Y'&&(!ar[i][j]))
			{
				ar[i][j]=true;
				ar[j][i]=true;
				ans[count][0]=1;
				ans[count][1]=i;
				ans[count][2]=j;
				visited[i]=true;
				visited[j]=true;
				x=i;
				y=j;
				flag=1;
				while(flag)
				{
					flag=0;
					for(int k=0;k<n;++k)
					{
						if(ch[y][k]=='Y'&&(!ar[y][k])&&(!visited[k]))
						{
							bool a=false;
							for(int w=1;w<ans[count][0];++w)
							{
								a=check_intersection(v[y],v[k],v[ans[count][w]],v[ans[count][w+1]]);
								if(a)
									break;
							}
							if(!a)
							{
								ans[count][0]++;
								int temp=ans[count][0];
								ans[count][temp+1]=k;
								visited[k]=true;
								ar[y][k]=true;
								ar[k][y]=true;
								flag=1;
								x=y;
								y=k;
							}
						}
					}
				}
				if(!ar[x][y] && ch[x][y]=='Y')
				{
					ans[count][0]++;
					ans[count][ans[count][0]+1]=y;
				}
				count++;
				memset(visited,false,sizeof(visited));
			}
		}
	}
	printf("%d\n",count);
	for(int i=0;i<count;++i)
	{
		printf("%d ",ans[i][0]);
		for(int j=1;j<=ans[i][0]+1;++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
int direction(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
	int value=(q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second);
	if(value==0) 
		return 0;
	return (value>0)? 1: 2;
}
bool check_intersection(pair<int,int> p1, pair<int,int> q1, pair<int,int> p2, pair<int,int> q2)
{
	int d1 = direction(p1, q1, p2);
	int d2 = direction(p1, q1, q2);
	int d3 = direction(p2, q2, p1);
	int d4 = direction(p2, q2, q1); 
	if (d1 != d2 && d3 != d4)
		return true;
	else 
		return false;
}
