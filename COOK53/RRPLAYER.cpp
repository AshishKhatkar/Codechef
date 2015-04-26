/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	10000007
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		double ans = 1;
		for(int i=2; i<=n; ++i)
			ans = ans + (1.0 / i);
		ans = ans * n;
		cout<<ans<<endl;
	}
	return 0;
}