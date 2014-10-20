/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
long long int fib_series[44]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170};
int main()
{
	long long int t,i,n,ind;
	scanf("%lld",&t);
	while(cin>>n)
	{
		ind=43;
		for(i=43;i>=0;--i)
		{
			if(fib_series[i]<=n)
			{
				ind=i;
				break;
			}
		}
		for(i=ind;i>=0;--i)
		{
			if(fib_series[i]<=n)
			{
				printf("1");
				n-=fib_series[i];
			}
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
} 
