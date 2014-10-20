/*
*	
*	Problem : Bon Appetit
*	@author : ashish1610	
*
*/
#include<bits/stdc++.h>
using namespace std;
/*Fast input*/
inline void inp(long long int &n) 
{
    	n=0;
	long long int ch=getchar_unlocked();
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
struct person
{
	long long int s;
	long long int f;
	long long int p;
};
bool person_sort(const person &a, const person &b)
{
	if(a.p!=b.p)
		return a.p<b.p;
	if(a.s!=b.s)
		return a.s<b.s;
	return a.f<b.f;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k,i,ans=0,temp,temp1;
		inp(n);
		inp(k);
		person per[n+1];
		for(i=0;i<n;++i)
		{
			inp(per[i].s);
			inp(per[i].f);
			inp(per[i].p);
		}
		n++;
		per[i].p=1000000001;
		per[i].s=1000000001;
		per[i].f=1000000001;
		sort(per,per+n,person_sort);
		temp=0;
		temp1=per[0].p;
		for(i=1;i<n;++i)
		{
			if(per[temp].p<per[i].p)
			{
				temp=i;
				ans++;
			}
			else if(per[temp].f<=per[i].s)
			{
				temp=i;
				ans++;
			}
			else if(per[temp].f>per[i].f)
			{
				temp=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
