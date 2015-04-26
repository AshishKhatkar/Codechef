/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
char str[200005];
/* Code for generator 1 taken from problem itself */
/* ------------------ start here ---------------------*/
unsigned X; // we assume that unsigned is a 32bit integer type
void srand1(unsigned S)
{
	X = S;
}
unsigned nextInteger1(void)
{
	X = X * 1103515245 + 12345;
	return (X >> 16) % 32768; // as 65536 = 2 ^ 16 (just to make division faster)
}
int generator1(int N, unsigned S)
{
	srand1(S);
	for(int i=1;i<=N;i++)
	{
		if(str[i - 1] - '0' != nextInteger1() % 2)
			return 0;
		// A[i] = nextInteger1() % 2;
	}
	return 1;
}
/* ------------------ end here -----------------------*/

/* Code for generator 2 taken from problem itself */
/* ------------------ start here ---------------------*/
unsigned x, y, z, w; // we assume that unsigned is a 32bit integer type
void srand2(unsigned S)
{
	x = S;
	y = x * S;
	z = y * S;
	w = z * S;
}
unsigned nextInteger2(void)
{
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
}
int generator2(int N, unsigned S)
{
	srand2(S);
	for(int i=1;i<=N;i++)
	{
		if(str[i - 1] - '0' != nextInteger2() % 2)
			return 0;
		// A[i] = nextInteger2() % 2; 
	}
	return 1;
}
/* ------------------ end here -----------------------*/
int main()
{
	int t, i, j;
	si(t);
	rep(i, 1, t)
	{
		scanf("%s", str);
		int len = strlen(str);//.length();
		bool flag = false;
		// as for generator1 we are taking mod with 32768. I think s upto 32768 will suffice for generator1
		// and i guess s upto 2^19 will work for both generator1 and generator2.
		// 2^19 didn't worked for generator2 :(
		// 32768 didn't worked for large cases. :(
		// 2^19 will only work for generator1
		// did more investigation and as we are doing division y 2^16 that is shifting 16 bits than s that will suffice will be 2^17 - 1;
		rep(j, 0, (1 << 17) - 1)
		{
			if(generator1(len, j))
			{
				flag = true;
				printf("LCG\n");
				break;
			}
		}
		if(!flag)
			printf("Xorshift\n");
	}
	return 0;
}