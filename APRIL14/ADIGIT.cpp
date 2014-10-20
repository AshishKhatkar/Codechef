/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
long long int dp[100005][10];
int main()
{
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	int ar[n];
	for(int i=0;i<n;++i)
	{
		ar[i]=str[i]-'0';
	}
	//long long int dp[n][10];
	memset(dp,0,sizeof(dp));
	//dp[0][ar[0]]=ar[0];
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<10;++j)
			dp[i][j]=dp[i-1][j]+abs(j-ar[i-1]);
	}
	/*for(int i=0;i<n;++i)
	{
		cout<<dp[i][ar[i]]<<" ";
	}
	cout<<endl;*/
	while(m--)
	{
		int x;
		cin>>x;
		cout<<dp[x-1][ar[x-1]]<<endl;
	}
	return 0;
}
