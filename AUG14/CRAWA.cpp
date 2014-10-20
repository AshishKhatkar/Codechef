/*
ID: ashish1610
PROG: The leaking robot
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
/*	fast input	*/
inline void inp(ll &n) 
{
    	n=0;
	register ll ch=getchar_unlocked();
	ll sign=1;
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
	ll t,x,y;
	inp(t);
	//scanf("%d",&t);
	while(t--)
	{
		//ll x,y;
		//scanf("%lld %lld",&x,&y);
		inp(x),inp(y);
		bool done=false;
		/*origin*/
		if(x==0 && y==0)
		{
			printf("YES\n");
			done=true;
		}
		/*vertical axis*/
		else if(x==0)
		{
			if((y>0 && y%2==0) || (y<0 && (-1*y)%2==0))
			{
				printf("YES\n");
				done=true;
			}
		}
		/*horizontal axis*/
		else if(y==0)
		{
			if((x>0 && x%2==1) || (x<0 && (-1*x)%2==0))
			{
				printf("YES\n");
				done=true;
			}
		}
		/*1st quadrant*/
		else if(x>0 && y>0)
		{
			if((x%2==1 && x-y+1>=0) || (y%2==0 && y-x-1>=0))
			{
				printf("YES\n");
				done=true;
			}
		}
		/*2nd quadrant*/
		else if(x<0 && y>0)
		{
			if(((-1*x)%2==0 && (-1*x)-y>=0) || (y%2==0 && (-1*x)-y<=0))
			{
				printf("YES\n");
				done=true;
			}
		}
		/*3rd quadrant*/
		else if(x<0 && y<0)
		{
			if(((-1*x)%2==0 && (-1*x)-(-1*y)>=0) || ((-1*y)%2==0 && (-1*y)-(-1*x)>=0))
			{
				printf("YES\n");
				done=true;
			}
		}
		/*4th quadrant*/
		else if(x>0 && y<0)
		{
			if((x>2 && x%2==1 && (-1*y)-x+1<=0) || ((-1*y)%2==0 && (-1*y)-x+1>=0))
			{
				printf("YES\n");
				done=true;
			}
		}
		if(!done)
			printf("NO\n");
	}
	return 0;
}
