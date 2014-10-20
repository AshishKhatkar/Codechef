/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll ar[200005];
int main() 
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>ar[i];
	ll dp[n+1];
	dp[1]=0;
	for(int i=2;i<=n;++i)
	{
		dp[i]=LONG_MAX;
		for(int j=1;(i-j)>0;j*=2)
			dp[i]=min(dp[i],dp[i-j]+abs(ar[i]-ar[i-j]));
	}
	cout<<dp[n]<<endl;
	return 0;
}
