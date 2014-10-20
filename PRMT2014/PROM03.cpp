/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
long long int ans[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int main()
{
	int t,n;
	cin>>t;
	while(cin>>n)
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
