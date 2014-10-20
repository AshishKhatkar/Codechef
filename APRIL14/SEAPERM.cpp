/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,s;
		cin>>n>>k>>s;
		int ar[n+1];
		vector<int>temp;
		for(int i=1;i<=n;++i)
		{
			cin>>ar[i];
			temp.push_back(ar[i]);
		}
		sort(temp.begin(),temp.end());
		//reverse(temp.begin(),temp.end());
		bool mark[n+1];
		memset(mark,false,sizeof(mark));
		for(int i=0;i<n;++i)
		{
			int pos=0;
			for(int j=1;j<=n;++j)
			{
				if(temp[i]==ar[j] && !mark[j])
				{
					pos=j;
					mark[j]=true;
					break;
				}
			}
			cout<<pos<<" ";
		}
		cout<<endl;
	}
	return 0;
}
