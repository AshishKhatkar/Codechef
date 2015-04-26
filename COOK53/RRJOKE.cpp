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
		int x, y;
		ll xor_val = 0;
		for(int i=1; i<=n; ++i)
		{
			cin>>x>>y;
			xor_val ^= i;
		}
		cout<<xor_val<<endl;
	}
	return 0;
}