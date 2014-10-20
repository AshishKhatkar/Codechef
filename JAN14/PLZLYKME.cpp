/*
*	
*	Problem : Please Like Me
*	@author : ashish1610	
*
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int l,d,s,c,ans;
		cin>>l>>d>>s>>c;
		ans=s;
		c+=1;
		d--;
		while(d!=0)
		{
			ans*=c;
			d--;
			if(ans>=l)
				break;
		}
		if(ans>=l)
			cout<<"ALIVE AND KICKING\n";
		else
			cout<<"DEAD AND ROTTING\n";
	}
	return 0;
}
