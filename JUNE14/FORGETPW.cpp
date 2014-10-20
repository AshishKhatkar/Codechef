/*
ID: ashish1610
PROG: Forget Password
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1000005],x,y;
int n,t,tmp[130];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(tmp,-1,sizeof(tmp));
		for(int i=0;i<n;++i)
		{
			scanf(" %c %c",&x,&y);
			tmp[x]=y;
		}
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;++i)
		{
			if(tmp[str[i]]!=-1)
				str[i]=tmp[str[i]];
		}
		int dec_pos=-1;
		for(int i=0;i<len;++i)
		{
			if(str[i]=='.')
			{
				dec_pos=i;
				break;
			}
		}
		int final_ans_pos1=0,final_ans_pos2=len-1;
		for(int i=0;(i<len && str[i]=='0');++i)
			final_ans_pos1++;
		for(int i=len-1;(i>=0 && str[i]=='0' && i>dec_pos && dec_pos!=-1);--i)
			final_ans_pos2--;
		if(str[final_ans_pos2]=='.')
			final_ans_pos2--;
		if(final_ans_pos2-final_ans_pos1 < 0)
			printf("0\n");
		else
		{
			for(int i=final_ans_pos1;i<=final_ans_pos2;++i)
				printf("%c",str[i]);
			printf("\n");
		}
	}
	return 0;
}
