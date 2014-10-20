/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ar[n];
		for(int i=0;i<n;++i)
			cin>>ar[i];
		ll ans=0;
		int ind=0;
		for(int i=0;i<n;++i)
		{
			if(ar[i]<0)
			{
				while(ar[i]!=0)
				{
					for(int j=ind;j<n;++j)
					{
						if(ar[ind]==0)
							ind++;
						if(ar[j]>0)
						{
							if(ar[j]>=abs(ar[i]))
							{
								ans+=abs((j-i)*ar[i]);
								ar[j]+=ar[i];
								ar[i]=0;
							}
							else
							{
								ans+=abs((j-i)*ar[j]);
								ar[i]+=ar[j];
								ar[j]=0;
							}
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
