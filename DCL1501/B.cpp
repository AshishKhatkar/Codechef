// /*
// ID: ashish1610
// PROG:
// LANG: C++
// */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll				long long int
// #define vi				vector<int>
// #define vl				vector<ll>
// #define	pii				pair<int,int>
// #define pil				pair<int, ll>
// #define pll				pair<ll, ll>
// #define pli 			pair<ll, int>
// #define pb(v, a)		v.push_back(a)
// #define mp(a, b)		make_pair(a, b)
// #define MOD				1000000007
// #define rep(i, a, b)	for(i=a; i<=b; ++i)
// #define rrep(i, a, b)	for(i=a; i>=b; --i)
// #define si(a)			scanf("%d", &a)
// #define sl(a)			scanf("%lld", &a)
// #define pi(a)			printf("%d", a)
// #define pl(a)			printf("%lld", a)
// #define pn 				printf("\n")
// ll pow_mod(ll a, ll b)
// {
// 	ll res = 1;
// 	while(b)
// 	{
// 		if(b & 1)
// 			res = (res * a) % MOD;
// 		a = (a * a) % MOD;
// 		b >>= 1;
// 	}
// 	return res;
// }
// /*	fast input	*/
// inline void inp(int &n) 
// {
//     	n=0;
// 	register int ch=getchar_unlocked();
// 	int sign=1;
//     	while(ch<'0'||ch>'9')
// 	{
// 		if(ch=='-')
// 			sign=-1; 
// 		ch=getchar_unlocked();
// 	}
//     	while(ch>='0'&&ch<='9')
//             n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
//     	n=n*sign;
// }
// int k[200005], l[200005];
// bool flag[400005];
// int lowerB(int low, int high, int key, vector<int> v)
// {
// 	while(low <= high)
// 	{
// 		int mid = (low + high) >> 1;
// 		if(v[mid] > key)
// 			high = mid - 1;
// 		else if(v[mid] < key)
// 			low = mid + 1;
// 		else
// 			return mid;
// 	}
// 	return high;
// }
// int main()
// {
// 	int n;
// 	inp(n);
// 	int i, j;
// 	rep(i, 0, n - 1)
// 	{
// 		inp(l[i]);
// 		flag[l[i]] = true;
// 		flag[2 * l[i]] = true;
// 	}
// 	sort(l, l + n);
// 	vector<int> v(l, l + n);
// 	vector<int>::iterator it = unique(v.begin(), v.end());
// 	v.resize(distance(v.begin(), it));
// 	n = v.size();
// 	int m;
// 	inp(m);
// 	rep(i, 0, m - 1)
// 		inp(k[i]);
// 	int ans = 0;
// 	sort(k, k + m);
// 	// for(int i=1;i<n;i++) 
// 	// 	flag[v[0]+v[i]]=true;
// 	for(int i=n-2;i>=0;i--) 
// 		flag[v[n-1]+v[i]]=true;
// 	for(int i=1; i<n; ++i)
// 		flag[v[i] + v[i - 1]] = true;
// 	for(int i=0;i<min(1000,n);i++) 
// 		for(int j=i+1;j<n;j++) 
// 			flag[v[i]+v[j]]=true;
// 	int idx = 0;
// 	int pointer = 0;
// 	while(idx < m && k[idx] < l[0])
// 		idx++;
// 	rep(i, idx, m - 1)
// 	{
// 		if(k[i] > 2 * v[n - 1])
// 			break;
// 		if(flag[k[i]])
// 			ans++;
// 		// else
// 		// {
// 		// 	while(pointer<n && v[pointer]<k[i]) pointer++;
// 		// 		pointer--;
// 		// 	int tmp1 = 0, tmp2 = pointer;
// 		// 	bool backchodi = false;
// 		// 	while(tmp1 <= tmp2)
// 		// 	{
// 		// 		if(v[tmp1] + v[tmp2] == k[i])
// 		// 		{
// 		// 			backchodi = true;
// 		// 			flag[v[tmp1] + v[tmp2]] = true;
// 		// 			break;
// 		// 			tmp1 ++;
// 		// 			tmp2 --;
// 		// 		}
// 		// 		else if(v[tmp1] + v[tmp2] < k[i])
// 		// 		{
// 		// 			flag[v[tmp1] + v[tmp2]] = true;
// 		// 			tmp1++;
// 		// 		}
// 		// 		else
// 		// 		{
// 		// 			flag[v[tmp1] + v[tmp2]] = true;
// 		// 			tmp2--;
// 		// 		}
// 		// 	}
// 		// 	if(backchodi)
// 		// 		ans++;
// 		// }
// 	}
// 	pi(ans);
// 	pn;
// 	return 0;
// }
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
int main()
{
	int ans=0;
	for(int i=1; i<=127; ++i)
	{
		string str="";
		int tmp=i;
		while(tmp)
		{
			if(tmp&1)
				str = str + '1';
			else
				str = str + '0';
			tmp /= 2;
		}
		string str1 = str;
		reverse(str.begin(), str.end());
		if(str == str1)
			ans++;
		// cout<<str<<endl;
	}
	cout<<ans<<endl;
	return 0;
}