/*
ID: ashish1610
PROG: RRSUM
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	ll n,m,q;
	cin>>n>>m;
	while(m--)
	{
		cin>>q;
		if(q>(3*n) || q<(n+2))
			cout<<0<<endl;
		else
		{
			if(q<=2*n+1)
				cout<<(q-1-n)<<endl;
			else
				cout<<(3*n+1-q)<<endl;
		}
	}
	return 0;
}
