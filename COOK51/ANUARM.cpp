/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int ar[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,tmp,minx=INT_MAX,maxx=INT_MIN;
		cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>tmp;
			minx=min(minx,tmp);
			maxx=max(maxx,tmp);
		}
		for(int i=0;i<n;++i)
			cout<<max(abs(minx-i),abs(maxx-i))<<" ";
		cout<<endl;
	}
	return 0;
}
