/*
ID: ashish1610
PROG: Chef and Rectangle Genome
LANG: C++
*/
#include<bits/stdc++.h>
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
int main()
{
	int t,i,j,n,m,k;
	inp(t);
	while(t--)
	{
		inp(n),inp(m),inp(k);
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
				printf("A");
			printf("\n");
		}
	}
	return 0;
}
