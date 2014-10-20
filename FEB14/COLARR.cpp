/*	ashish1610	*/
#include <bits/stdc++.h>
using namespace std;
/*	fast input	*/
inline void inp(int &n) 
{
    	n=0;
	register int ch=getchar_unlocked();
	int sign=1;
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
/*	main program	*/
int main() 
{
	int t;
	inp(t);
	while(t--)
	{
		int n,m,k;
		inp(n);
		inp(m);
		inp(k);
		int ar[n+1],ar1[n+1][m+1],ar2[n+1][m+1],v[n];
		for(int i=1;i<n+1;++i)
			inp(ar[i]);
		/*	points matrix input	*/
		for(int i=1;i<n+1;++i)
			for(int j=1;j<m+1;++j)
				inp(ar1[i][j]);
		/*	cost matrix input	*/
		for(int i=1;i<n+1;++i)
			for(int j=1;j<m+1;++j)
				inp(ar2[i][j]);
		int ans=0;
		/*	
		*	we create array of integers in which we store the result obtained by painting ith cell with jth color 
		*	for all i=0 to n-1 v[i]=(max(vi,ar1[i][j]-ar2[i][j]-ar1[i][ar[i]-1] over all j=0 to m-1)
		*/
		for(int i=1;i<n+1;++i)
		{
			ans+=ar1[i][ar[i]];
			int vi=0;
			for(int j=1;j<m+1;++j)
				vi=max(vi,ar1[i][j]-ar2[i][j]-ar1[i][ar[i]]);
			v[i-1]=vi;			
			//cout<<ans<<endl;
		}
		sort(v,v+n);
		/*	reversing	*/
		int start=0,end=n-1;
		while(start<end)
		{
			swap(v[start],v[end]);
			start++;
			end--;
		}
		/*
		*	after sorting & reversing we just need to calculate the ans by adding all the result where i<k
		*/
		for(int i=0;i<n;++i)
		{
			//cout<<v[i]<<" ";
			if(i<k)
				ans+=v[i];
		}
		/*
		*	finally ans includes the points we get for painting ith cell with (ar[i]-1)th color and the sum over the result
		*	stored in sorted v for all i<k
		*/
		printf("%d\n",ans);
	}
	return 0;
}
