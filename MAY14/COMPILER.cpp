/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int cnt1=0,cnt2=0,ans=0;
		for(int i=0;i<str.length();++i)
		{
			if(str[i]=='<')
				cnt1++;
			else if(str[i]=='>' && cnt1==0)
				break;
			else if(str[i]=='>')
			{
				cnt2+=2;
				cnt1--;
			}
			if(cnt1==0)
			{
				ans+=cnt2;
				cnt2=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
