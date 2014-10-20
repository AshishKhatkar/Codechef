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
//long long int ar[3000005];
long long int mapped[1000005];
int main()
{
	int t;
	long long int mod=1000000;
	scanf("%d",&t);
	while(t--)
	{
		memset(mapped,0,sizeof(mapped));
		long long int n;
		int a,b,c,d;
		inp(n);
		scanf("%d %d %d %d",&a,&b,&c,&d);
		//priority_queue<long long int, std::vector<long long int>, std::greater<long long int> >q;
		//ar[0]=d;
		long long int temp=d;
		mapped[d]++;
		//q.push(d);
		long long int suma=0,sumb=0,index=1,maxx=d;
		for(long long int i=1;i<n;++i)
		{
			temp=(a*temp*temp+b*temp+c)%mod;
			mapped[temp]++;
			maxx=max(maxx,temp);
			//q.push(ar[i]);
			/*if(ar[i]<ar[i-1])
			{
				
				index=0;
			}
			if(index&1)
			{
				sumb+=ar[i];
				index++;
			}
			else
			{
				suma+=ar[i];
				index++;
			}*/
		}
		bool flag=false;
		for(long long int i=maxx;i>0;--i)
		{
			if(mapped[i]%2==0 && mapped[i]!=0)
			{
				//cout<<i<<" ";
				suma=suma+(mapped[i]/2)*i;
				sumb=sumb+(mapped[i]/2)*i;
			}
			else if(mapped[i]!=0)
			{
				if(!flag)
				{
					//cout<<i<<" ";
					suma=suma+(mapped[i]/2+1)*i;
					sumb=sumb+(mapped[i]/2)*i;
					flag=true;
				}
				else
				{
					//cout<<i<<" ";
					suma=suma+(mapped[i]/2)*i;
					sumb=sumb+(mapped[i]/2+1)*i;
					flag=false;
				}
			}
		}
		//cout<<endl;
		/*for(long long int i=0;i<n;++i)
		{
			long long int temp=q.top();
			q.pop();
			//cout<<temp<<" ";
			if(i&1)
				sumb+=temp;
			else
				suma+=temp;
		}*/
		//cout<<endl;
		/*for(long long int i=0;i<n;++i)
			cout<<ar[i]<<" ";
		cout<<endl;
		for(int i=0;i<n;++i)
		{
			if(i%2)
				sumb+=ar[i];
			else
				suma+=ar[i];
		}*/
		cout<<abs(suma-sumb)<<endl;
	}
	return 0;
}
