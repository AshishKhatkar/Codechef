/*
ID: ashish1610
PROG: Reverse
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
struct node
{
	int dis;
	int val;
	node(int a, int b)
	{
		dis=a;
		val=b;
	}
};
bool operator<(const node& n1, const node& n2)
{
	return n1.dis<n2.dis;
}
vector<node> adj[100005];
bool visited[100005];
int ans[100005];
int dijkstra(int n)
{
	priority_queue<node> q;
	q.push(node(0,1));
	ans[1]=0;
	while(!q.empty())
	{
		node tp=q.top();
		q.pop();
		if(visited[tp.val])
			continue;
		visited[tp.val]=true;
		for(int i=0;i<adj[tp.val].size();++i)
		{
			if(ans[adj[tp.val][i].val] > ans[tp.val]+adj[tp.val][i].dis)
			{
				ans[adj[tp.val][i].val]=ans[tp.val]+adj[tp.val][i].dis;
				q.push(node(-1*ans[adj[tp.val][i].val], adj[tp.val][i].val));
			}
		}
	}
	if(visited[n])
		return ans[n];
	return -1;
}
int main()
{
	for(int i=0;i<=100005;++i)
		ans[i]=INT_MAX;
	memset(visited,false,sizeof(visited));
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		adj[y].push_back(node(1,x));//reverse
		adj[x].push_back(node(0,y));//normal
	}
	printf("%d\n",dijkstra(n));
	return 0;
}
