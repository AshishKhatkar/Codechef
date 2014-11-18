/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define ld	long double
#define MOD	1000000007
/*Matrix Exponentiation*/
typedef vector<vector<ld> > matrix;
const int K=26;
matrix mul(matrix A, matrix B)
{
	matrix C(K,vector<ld>(K));
	for(int i=0;i<K;++i)
		for(int j=0;j<K;++j)
			for(int k=0;k<K;++k)
				C[i][j]=(C[i][j]+A[i][k]*B[k][j]);
	return C;
}
matrix mat_pow(matrix A, int p)
{
	if(p==1)
		return A;
	if(p&1)
		return mul(A,mat_pow(A,p-1));
	matrix tmp=mat_pow(A,p/2);
	return mul(tmp, tmp);
}
void solve_subtask1_subtask2_subtask3(string str, ld probab[26][26], vector<string> ls, ll n, ll k)
{
	matrix pro(K,vector<ld>(K));
	for(int i=0;i<K;++i)
		for(int j=0;j<K;++j)
			pro[i][j]=probab[i][j];
	matrix res=mat_pow(pro,k);
	ld ans=0;
	sort(ls.begin(),ls.end());
	vector<string>::iterator it=unique(ls.begin(),ls.end());
	ls.erase(it,ls.end());
	for(int i=0;i<ls.size();++i)
	{
		if(ls[i].length()!=str.length())
			continue;
		ld tmp=1;
		for(int j=0;j<str.length();++j)
			tmp=tmp*res[str[j]-'a'][ls[i][j]-'a'];
		ans+=tmp;
	}
	printf("%.10Lf\n",ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		string str;
		cin>>str;
		ld prob[26][26];
		for(int i=0;i<26;++i)
			for(int j=0;j<26;++j)
				cin>>prob[i][j];
		vector<string> word_list;
		string tmp;
		for(int i=0;i<n;++i)
		{
			cin>>tmp;
			word_list.push_back(tmp);
		}
		solve_subtask1_subtask2_subtask3(str,prob,word_list,n,k);
	}
	return 0;
}