/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int A,B,C,t;	
	cin>>t;
	while(cin>>A>>B>>C)
	{
		bool possible=false;
		int x,y,z;
		for(x=1;x<=100&&!possible;++x)
		{
			for(y=1;y<=100&&!possible;++y)
			{
				for(z=1;z<=100&&!possible;++z)
				{
					if(x+y+z==A && x*y*z==B && x*x+y*y+z*z==C)
					{
						cout<<x<<" "<<y<<" "<<z<<endl;
						possible=true;
					}
				}
			}
		}
		if(!possible)
			cout<<"No solution."<<endl;
	}
	return 0;
}
