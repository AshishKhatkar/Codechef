/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
/*	fast input	*/
inline void inp(long long int &n) 
{
    	n=0;
	register long long int ch=getchar_unlocked();
	long long int sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
int main()
{
	long long int t;
	inp(t);
	while(t--)
	{
		long long int n;
		inp(n);
		long long int temp,ans=0;
		for(long long int i=0;i<n;++i)
		{
			inp(temp);
			ans=max(ans,temp+i);
			/*if(maxx<temp+i)
			{
				maxx=temp+i;
			}*/
		}
		//long long int ans=maxx;
		//ans=max(ans,n);
		cout<<ans<<endl;
	}
	return 0;
}
