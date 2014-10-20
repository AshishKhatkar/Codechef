/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int capital_a[26],capital_b[26],small_a[26],small_b[26],integ_a[10],integ_b[10];
		memset(capital_a,0,sizeof(capital_a));
		memset(capital_b,0,sizeof(capital_b));
		memset(small_a,0,sizeof(small_a));
		memset(small_b,0,sizeof(small_b));
		memset(integ_a,0,sizeof(integ_a));
		memset(integ_b,0,sizeof(integ_b));
		for(int i=0;i<str1.length();++i)
		{
			if((int)str1[i]>=97 && (int)str1[i]<=122)
				small_a[(int)str1[i]-97]++;
			else if((int)str1[i]>=65 && (int)str1[i]<=90)
				capital_a[(int)str1[i]-65]++;
			else
				integ_a[(int)str1[i]-48]++;
		}
		for(int i=0;i<str2.length();++i)
		{
			if((int)str2[i]>=97 && (int)str2[i]<=122)
				small_b[(int)str2[i]-97]++;
			else if((int)str2[i]>=65 && (int)str2[i]<=90)
				capital_b[(int)str2[i]-65]++;
			else
				integ_b[(int)str2[i]-48]++;
		}
		int ans=0;
		for(int i=0;i<26;++i)
		{
			ans+=min(capital_a[i],capital_b[i]);
			ans+=min(small_a[i],small_b[i]);
		}
		for(int i=0;i<10;++i)
			ans+=min(integ_a[i],integ_b[i]);
		cout<<ans<<endl;
	}
	return 0;
}
