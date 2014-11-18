/*
ID: ashish1610
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2_subtask3(int n, vector<int> ar[])
{
	vector<int> tmp;
	for(int cnt=0;cnt<n;++cnt)
	{
		for(int i=0;i<n;++i)
		{
			tmp.clear();
			int j=0;
			while(j!=i)
			{
				tmp.push_back(ar[cnt][j]);
				j++;
			}
			tmp.push_back(n);
			while(j!=n-1)
			{
				tmp.push_back(ar[cnt][j]);
				j++;
			}
			vector<int>sol[n];
			bool flag=true;
			bool matched[n];
			memset(matched,false,sizeof(matched));
			for(int j=0;j<n;++j)
			{
				for(int k=0;k<n;++k)
				{
					if(j==k)
						continue;
					if(tmp[j]>tmp[k])
						sol[j].push_back(tmp[k]);
					else
						sol[j].push_back(tmp[k]-1);
				}
				bool found=false;
				for(int k=0;k<n;++k)
				{
					if(ar[k]==sol[j] && !matched[k])
					{
						found=true;
						matched[k]=true;
						break;
					}
				}
				if(!found)
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				for(int i=0;i<n;++i)
					cout<<tmp[i]<<" ";
				cout<<endl;
				return;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,tmp;
		cin>>n;
		vector<int> ar[n];
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n-1;++j)
			{
				cin>>tmp;
				ar[i].push_back(tmp);
			}
		}
		solve_subtask1_subtask2_subtask3(n,ar);
	}
	return 0;
}