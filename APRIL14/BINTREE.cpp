/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long long int x,y;
		cin>>x>>y;
		if(x==y)
			cout<<0<<endl;
		else
		{
			long long int p_x=x,p_y=y,ans=0;
			/*if(x>y)
				p_x/=2;
			else if(x<y)
				p_y/=2;*/
			//if(p_y==0)
			//	p_y=1;
			while(p_x!=p_y)
			{
				if(p_x<p_y)
					p_y/=2;
				else if(p_x>p_y)
					p_x/=2;
				ans++;
			}
			//long long int ans=(long long int)(log(x)/log(2))+(long long int)(log(y)/log(2))-2*(long long int)(log(p_x)/log(2));
			//cout<<p_x<<" "<<p_y<<" "<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}
