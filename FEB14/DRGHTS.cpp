/*	ashish1610	*/
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
/*	main program	*/
/*
*	using dfs to calculate the pairs (I hope this works. God help me :) )
*/
vector<int> adj_list[50001];
bool visited[50001];
/* fucking mistake of long long int >:o This mistake costed me a lot. My first submission in itself was correct
*/
long long int ans2_v,ans1_v;
int ar[50001];
bool dfs(int n)
{
	visited[n]=true;
	if(!ar[n])
	{
		/*	if ar[n]=0 we will only increment count for room if there is any draught passing through that room
		*	this is checked by boolean variable temp
		*/
		bool temp=false;
		for(int i=0;i<adj_list[n].size();++i)
		{
			if(!visited[adj_list[n][i]])
				temp|=dfs(adj_list[n][i]);
		}
		if(temp)
			ans2_v++;
		return temp;
	}
	else 
	{
		/*	if ar[n]=1 we will increment count for both pairs and rooms with draught passing through it 
		*/
		ans1_v++;
		ans2_v++;
		for(int i=0;i<adj_list[n].size();++i)
		{
			if(!visited[adj_list[n][i]])
				dfs(adj_list[n][i]);
		}
		return true;
	}
}
/*	This was how I tried to achieve this in my earlier submissions but got WA :( It was correct but fucking long long int costed me WA's
int dfs(int n)
{
	int temp=0;
	visited[n]=true;
	if(ar[n]==1)
		ans1_v[cnt]++;
	for(int i=0;i<adj_list[n].size();++i)
	{
		if(!visited[adj_list[n][i]])
			temp=temp|dfs(adj_list[n][i]); 
	}
	if(!temp)
	{
		if((ar[n]==1)&&(ans1_v[cnt]>1))
		{
			ans2_v[n]=1;
			return 1;
		}
		else
		{
			ans2_v[n]=0;
			return 0;
		}
	}
	else
	{
		ans2_v[n]=1;
		return 1;
	} 
}
*/
int main()
{
	memset(visited,false,sizeof(visited));
	int n,m;
	inp(n);
	inp(m);
	for(int i=1;i<=n;++i)
		inp(ar[i]);
	for(int i=0;i<m;++i)
	{
		int x,y;
		inp(x);
		inp(y);
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	ans1_v=0;
	ans2_v=0;
	long long int ans1=0,ans2=0;
	for(int i=1;i<=n;++i)
	{
		/*	if the node is not visited and ar[i]=1 we will do dfs from that node to find the pairs and rooms with draughts
		*/
		if(ar[i]&&!visited[i])
		{
			ans1_v=0;
			ans2_v=0;
			dfs(i);
			/*	no.of pairs = no. of ways to select 2 rooms to make pair 
			*	from the no.of rooms with 1 by doing dfs from i
			*	and 
			*	rooms with draught = ans2_v if there exist draught staring from i i.e if no.of rooms with 1 by doing dfs from 
			*	i is > 1
			*/ 
			ans1+=((ans1_v*(ans1_v-1))/2);
			if(ans1_v>1)
				ans2+=ans2_v;
		}
	}
	/*	This was part from wrong submission made earlier. was correct fucking long long int costed me too many WA's
	for(int i=1;i<=n;++i)
		if(ans2_v[i]==1)
			ans2++;
	for(int i=1;i<=cnt;++i)
		ans1+=(ans1_v[i]*(ans1_v[i]-1))/2;
	*/
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
