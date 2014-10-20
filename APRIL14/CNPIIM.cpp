/*	ashish1610	*/
/*	hardcoded code already submitted : http://www.codechef.com/viewsolution/3680462 */
#include<bits/stdc++.h>
using namespace std;
int cnt[1562501];
long long int dp[1562501];
long long int final_ans[2501];
void pre_compute()
{
	/*	storing counts of i*j	*/
	long long int j;
	for(long long int i=1;i<1562501;++i)
	{
		j=1;
		while(i*j<1562501)
		{
			cnt[i*j]++;
			j++;
		}
	}
	/*	storing total count in another array	*/
	dp[1]=cnt[1];
	for(long long int i=2;i<1562501;++i)
	{
		dp[i]=dp[i-1]+cnt[i];
	}
	/*	computing ans	*/
	final_ans[0]=0;
	final_ans[1]=0;
	final_ans[2]=0;
	long long int x,y,ans;
	for(int i=3;i<=2500;++i)
	{
		x=1;
		y=i-1;
		ans=0;
		while(x<=y)
		{
			/*
			*	for x==y consider this case
			*	2	1
			*	3	2
			*	here 2 2 will be counted only once if it was say 1 3 than it would lead to twice
			*	1	1	or	3	1
			* 	1	3		1	1
			*	thats why when x!=y we count all the cases twice.
			*	and for x==y we count them only once.
			*/
			if(x!=y)
				ans+=(2*dp[x*y-1]);
			else
				ans+=dp[x*y-1];
			x++;
			y--;
		}
		final_ans[i]=ans;
	}

}
int main()
{
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	memset(final_ans,0,sizeof(final_ans));
	pre_compute();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<final_ans[n]<<endl;
	}
	return 0;
}
