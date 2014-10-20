/*
ID: ashish1610
PROG: RRCOPY
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		set<int>ans;
		int n,x;
		cin>>n;
		while(n--)
		{
			cin>>x;
			ans.insert(x);
		}
		cout<<ans.size()<<endl;
	}
	return 0;
}
