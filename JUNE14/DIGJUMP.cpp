/*
ID: ashish1610
PROG: Digit Jump
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[100005];
bool finished[100005];
vector<int> v[15];
int main()
{
	memset(finished,false,sizeof(finished));
	memset(ans,0,sizeof(ans));
	string str;
	cin>>str;
	for(int i=0;i<str.length();++i)
		v[str[i]-'0'].push_back(i);
	ans[0]=0;
	queue<int> q;
	q.push(0);
	finished[0]=true;
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		if(n!=0 && !finished[n-1])
		{
			ans[n-1]=ans[n]+1;
			finished[n-1]=true;
			q.push(n-1);
		}
		if(n!=str.length()-1 && !finished[n+1])
		{
			ans[n+1]=ans[n]+1;
			finished[n+1]=true;
			q.push(n+1);
		}
		for(int i=0;i<v[str[n]-'0'].size();++i)
		{
			if(!finished[v[str[n]-'0'][i]])
			{
				ans[v[str[n]-'0'][i]]=ans[n]+1;
				finished[v[str[n]-'0'][i]]=true;
				q.push(v[str[n]-'0'][i]);
			}
		}
		v[str[n]-'0'].clear();
	}
	printf("%d\n",ans[str.length()-1]);
	return 0;
}
