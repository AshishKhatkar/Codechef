/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> v[n+1];
	map<int,int> ma;
	int x,y;
	for(int i=0;i<p;++i)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	bool flag,flag1;
	int ans,present_sum,prev_sum,a,b,prev_a,prev_b;
	for(int i=1;i<=n;++i)
	{
		if(v[i].size()==0)
			cout<<m-1<<endl;
		else
		{
			flag=flag1=false;
			ans=0;		
			ma.clear();
			for(int j=0;j<v[i].size();++j)
				ma[v[i][j]]++;
			map<int,int> :: iterator it;
			for(it=ma.begin();it!=ma.end();++it)
			{
				a=it->first;
				b=it->second;
				present_sum=a+b;
				if(!flag)
				{
					if(a>1)
						ans+=present_sum-1;
					flag=true;
				}
				else if(flag)
				{
					if((prev_b>1 && (a-prev_a)>1) || prev_sum>present_sum)
					{
						flag1=true;
						break;
					}
					ans+=present_sum-prev_sum;
				}
				prev_a=a;
				prev_b=b;
				prev_sum=present_sum;
			}
			if(flag1 || (a+b>a+1 && a<m))
				cout<<-1<<endl;
			else if(a<m)
				cout<<ans+m-a-b<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}
