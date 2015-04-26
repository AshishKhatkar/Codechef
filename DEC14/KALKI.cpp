/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*Minimum Spanning Tree*/
struct node
{
	int src,dest;
	float wght;
};
int par[405],rnk[405];
int Find(int nd)
{
	if(par[nd]!=nd)
		par[nd]=Find(par[nd]);
	return par[nd];
}
void Union(int nd1, int nd2)
{
	int x=Find(nd1);
	int y=Find(nd2);
	if(rnk[x]<rnk[y])
		par[x]=y;
	else if(rnk[x]>rnk[y])
		par[y]=x;
	else
	{
		par[y]=x;
		rnk[x]++;
	}
}
bool compare(node n1, node n2)
{
	if(n1.wght == n2.wght)
		return n1.src > n2.src;
	return n1.wght < n2.wght;
}
vector<node> mst;
void kruskal(vector<node> g, int n)
{
	for(int i=0;i<n;++i)
	{
		par[i]=i;
		rnk[i]=0;
	}
	sort(g.begin(),g.end(),compare);
	int cnt=0,cnt1=0;
	while(cnt!=n-1)
	{
		node ne=g[cnt1++];
		int x=Find(ne.src);
		int y=Find(ne.dest);
		if(x!=y)
		{
			mst.push_back(ne);
			Union(x,y);
			cnt++;
		}
	}
}
void solve_subtask(vector<node> graph, int n)
{
	mst.clear();
	kruskal(graph, n);
	for(int i=0; i<mst.size(); ++i)
		cout<<mst[i].src + 1<<" "<<mst[i].dest + 1<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<node> graph;
		node nd;
		int n;
		cin>>n;
		int x[n], y[n];
		for(int i=0; i<n; ++i)
			cin>>x[i]>>y[i];
		for(int i=0; i<n; ++i)
		{
			for(int j=i+1; j<n; ++j)
			{
				nd.src = i;
				nd.dest = j;
				ll x1 = (x[i] - x[j]) * (x[i] - x[j]);
				ll y1 = (y[i] - y[j]) * (y[i] - y[j]);
				nd.wght = (sqrt(x1 + y1));
				graph.push_back(nd);
			}
		}
		solve_subtask(graph, n);
	}
	return 0;
}