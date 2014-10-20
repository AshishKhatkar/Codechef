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
		long long int temp,count1=0,count0=0,count2=0;
		for(int i=0;i<n;++i)
		{
			inp(temp);
			if(temp==1)
				count1++;
			else if(temp==0)
				count0++;
			else if(temp==2)
				count2++;
		}
		n=n-count1-count0;
		long long int ans=(n*(n-1))/2-(count2*(count2-1))/2;
		cout<<ans<<endl;
	}
	return 0;
}
