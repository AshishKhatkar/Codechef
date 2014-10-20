/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<6 || n&1 || n==10)
			cout<<"RIDICULOUS\n";
		else if(n==6 || n==12 || n==18)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}
