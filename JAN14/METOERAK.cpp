/*
*	
*	Problem : Meteor
*	@author : ashish1610	
*
*/
#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	int n,m,k,index,count;
	inp(n);
	inp(m);
	inp(k);
	vector<pair<int,int> > v;
	v.resize(1001);
	int ar[1001][1001],ans[1001][1001], temp[1001], lt[1001], rt[1001], val[1001];
	for(int i=0;i<k;++i)
	{
		int x,y;
		inp(x);
		inp(y);
		ar[x][y]=1;
	}
	for(int i=1;i<=n;++i)
	{
		memset(temp, 0, sizeof(temp));
                memset(lt, 0, sizeof(lt));
                memset(rt, 0, sizeof(rt));
                index=0;
                for(int j=1;j<=m;++j)
                {
                        if (ar[i][j]==0) 
				val[j]++; 
			else 
				val[j] = 0;
			while(index>0 && v[index].first>=val[j])
				index--;
			v[++index].first=val[j];
			v[index].second=j;
                        if(index>1) 
				lt[j]=v[index-1].second; 
			else 
				lt[j] = 0;
                }
                index=0;
                for(int j=m;j>=1;--j)
                {
                        while(index>0 && v[index].first>=val[j])
				index--;
			v[++index].first=val[j];
			v[index].second=j;
                        if(index>1) 
				rt[j] = v[index-1].second; 
			else 
				rt[j] = m+1;
                }
                for(int j=1;j<=m;++j)
                        temp[i-val[j]+1] = max(temp[i-val[j]+1], rt[j]-lt[j]-1);
                count=0;
                for(int j=1;j<=i;++j)
                {
                        count=max(count,temp[j]);
                        temp[j]=(i-j+1)*count;
                }
                for(int j=i;j>=1;--j)
                        ans[i][j]=max(max(ans[i-1][j], ans[i][j+1]), temp[j]);
	}
	int q;
	inp(q);
	for(int i=0;i<q;++i)
	{
		int a,b;
		inp(a);
		inp(b);
		printf("%d\n",ans[b][a]);			
	}
	return 0;
}
