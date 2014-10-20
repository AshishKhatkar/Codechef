/*
ID: ashish1610
PROG: Chef and Frogs
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
/*	fast input	*/
inline void inp(long long int &n) 
{
    n=0;
	register long long int ch=getchar_unlocked();
	long long int sign=1;
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
bool compare(pair<int,ll> p1, pair<int,ll> p2)
{
	return p1.second<p2.second;
}
int main()
{
	ll n,k,p;
	inp(n);
	inp(k);
	inp(p);
	pair<int,ll> ar[n];
	for(int i=0;i<n;++i)
	{
		inp(ar[i].second);
		ar[i].first=i;
	}
	sort(ar,ar+n,compare);
	int ans[n];
	ans[ar[0].first]=1;
	for(int i=1;i<n;++i)
	{
		if(ar[i].second-ar[i-1].second>k)
			ans[ar[i].first]=ans[ar[i-1].first]+1;
		else
			ans[ar[i].first]=ans[ar[i-1].first];
	}
	int x,y;
	while(p--)
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		if(ans[x]==ans[y])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
