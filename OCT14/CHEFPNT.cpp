/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int ar[105][105];
//white 0
//black 1
//red 2
vector<pair<pair<int,int>,int> >lr,ud,rl,du,lr1,ud1,rl1,du1,lr2,ud2,lr3,ud3,lr4,ud4,lr5,ud5,lr6,ud6,lr7,ud7,lr8,ud8,lr9,ud9;
bool flag1=true,flag2=true;
bool check_lr(int ind, int m, int cpy[105][105])
{
	for(int i=1;i<=m;++i)
		if(cpy[ind][i]==0)
			return true;
	return false;
}
bool check_ud(int ind, int n, int cpy[105][105])
{
	for(int i=1;i<=n;++i)
		if(cpy[i][ind]==0)
			return true;
	return false;
}
int compute_left_right(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					lr2.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr2.size();
}
int compute_up_down(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					ud2.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud2.size();
}
int compute_left_right2(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					lr3.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr3.size();
}
int compute_up_down2(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					ud3.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud3.size();
}
int compute_left_right3(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					lr4.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr4.size();
}
int compute_up_down3(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					ud4.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud4.size();
}
int compute_left_right4(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					lr5.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr5.size();
}
int compute_up_down4(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					ud5.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud5.size();
}
int compute_left_right5(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					lr6.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr6.size();
}
int compute_up_down5(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					ud6.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud6.size();
}
int compute_left_right6(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					lr7.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr7.size();
}
int compute_up_down6(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					ud7.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud7.size();
}
int compute_left_right7(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					lr8.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr8.size();
}
int compute_up_down7(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					ud8.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud8.size();
}
int compute_left_right8(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					lr9.push_back(make_pair(make_pair(i,j),0));
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						copy_ar[i][k]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr9.size();
}
int compute_up_down8(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					ud9.push_back(make_pair(make_pair(i,j),1));
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						copy_ar[k][j]=2;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud9.size();
}
int compute_topleft(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						lr.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k<=m;++k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						lr.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k<=n;++k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr.size();
}
int compute_topright(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=1;i<=n;++i)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						ud.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k>=1;--k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						ud.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k<=n;++k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud.size();
}
int compute_bottomleft(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=1;j<=m;++j)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						rl.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k<=m;++k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						rl.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k>=1;--k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return rl.size();
}
int compute_bottomright(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int i=n;i>=1;--i)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int j=m;j>=1;--j)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						du.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k>=1;--k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						du.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k>=1;--k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return du.size();
}
int compute_topleft1(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						lr1.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k<=m;++k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						lr1.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k<=n;++k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return lr1.size();
}
int compute_topright1(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=1;j<=m;++j)
	{
		//while(check_ud(j,n,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k<=n;++k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						ud1.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k>=1;--k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						ud1.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k<=n;++k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag2=false;
	return ud1.size();
}
int compute_bottomleft1(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=1;i<=n;++i)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k<=m;++k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						rl1.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k<=m;++k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						rl1.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k>=1;--k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return rl1.size();
}
int compute_bottomright1(int n, int m)
{
	int copy_ar[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			copy_ar[i][j]=ar[i][j];
	for(int j=m;j>=1;--j)
	{
		//while(check_lr(i,m,copy_ar))
		{
			for(int i=n;i>=1;--i)
			{
				if(copy_ar[i][j]==0)
				{
					int ans1=0;
					for(int k=j;k>=1;--k)
					{
						if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
							break;
						ans1++;
					}
					int ans2=0;
					for(int k=i;k>=1;--k)
					{
						if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
							break;
						ans2++;
					}
					if(ans1>ans2)
					{
						du1.push_back(make_pair(make_pair(i,j),0));
						for(int k=j;k>=1;--k)
						{
							if(copy_ar[i][k]==1 || copy_ar[i][k]==2)
								break;
							copy_ar[i][k]=2;
						}	
					}
					else
					{
						du1.push_back(make_pair(make_pair(i,j),1));
						for(int k=i;k>=1;--k)
						{
							if(copy_ar[k][j]==1 || copy_ar[k][j]==2)
								break;
							copy_ar[k][j]=2;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(copy_ar[i][j]==0)
				flag1=false;
	return du1.size();
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k,x,y;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ar[i][j]=0;
	for(int i=0;i<k;++i)
	{
		cin>>x>>y;
		ar[x][y]=1;
	}
	int ans1=compute_topleft(n,m);
	int ans2=compute_topright(n,m);
	int ans3=compute_bottomleft(n,m);
	int ans4=compute_bottomright(n,m);
	int ans5=compute_topleft1(n,m);
	int ans6=compute_topright1(n,m);
	int ans7=compute_bottomleft1(n,m);
	int ans8=compute_bottomright1(n,m);
	int ans9=compute_left_right(n,m);
	int ans10=compute_up_down(n,m);
	int ans11=compute_left_right2(n,m);
	int ans12=compute_up_down2(n,m);
	int ans13=compute_left_right3(n,m);
	int ans14=compute_up_down3(n,m);
	int ans15=compute_left_right4(n,m);
	int ans16=compute_up_down4(n,m);
	int ans17=compute_left_right5(n,m);
	int ans18=compute_up_down5(n,m);
	int ans19=compute_left_right6(n,m);
	int ans20=compute_up_down6(n,m);
	int ans21=compute_left_right7(n,m);
	int ans22=compute_up_down7(n,m);
	int ans23=compute_left_right8(n,m);
	int ans24=compute_up_down8(n,m);
	
	int fans1=min(ans1,min(ans2,min(ans3,ans4)));
	int fans2=min(ans5,min(ans6,min(ans7,ans8)));
	int fans3=min(ans9,min(ans10,min(ans11,ans12)));
	int fans4=min(ans13,min(ans14,min(ans15,ans16)));
	int fans5=min(ans17,min(ans18,min(ans19,ans20)));
	int fans6=min(ans21,min(ans22,min(ans23,ans24)));
	int ans=min(fans1,min(fans2,min(fans3,min(fans4,min(fans5,fans6)))));
	//assert(flag1 && flag2);
	if(ans1==ans)
	{
		cout<<ans1<<endl;
		for(int i=0;i<lr.size();++i)
			cout<<lr[i].first.first<<" "<<lr[i].first.second<<" "<<lr[i].second<<"\n";
	}
	else if(ans2==ans)
	{
		cout<<ans2<<endl;
		for(int i=0;i<ud.size();++i)
			cout<<ud[i].first.first<<" "<<ud[i].first.second<<" "<<ud[i].second<<"\n";
	}
	else if(ans3==ans)
	{
		cout<<ans3<<endl;
		for(int i=0;i<rl.size();++i)
			cout<<rl[i].first.first<<" "<<rl[i].first.second<<" "<<rl[i].second<<"\n";
	}
	else if(ans4==ans)
	{
		cout<<ans4<<endl;
		for(int i=0;i<du.size();++i)
			cout<<du[i].first.first<<" "<<du[i].first.second<<" "<<du[i].second<<"\n";
	}
	else if(ans5==ans)
	{
		cout<<ans5<<endl;
		for(int i=0;i<lr1.size();++i)
			cout<<lr1[i].first.first<<" "<<lr1[i].first.second<<" "<<lr1[i].second<<"\n";
	}
	else if(ans6==ans)
	{
		cout<<ans6<<endl;
		for(int i=0;i<ud1.size();++i)
			cout<<ud1[i].first.first<<" "<<ud1[i].first.second<<" "<<ud1[i].second<<"\n";
	}
	else if(ans7==ans)
	{
		cout<<ans7<<endl;
		for(int i=0;i<rl1.size();++i)
			cout<<rl1[i].first.first<<" "<<rl1[i].first.second<<" "<<rl1[i].second<<"\n";
	}
	else if(ans8==ans)
	{
		cout<<ans8<<endl;
		for(int i=0;i<du1.size();++i)
			cout<<du1[i].first.first<<" "<<du1[i].first.second<<" "<<du1[i].second<<"\n";
	}
	else if(ans9==ans)
	{
		cout<<ans9<<endl;
		for(int i=0;i<lr2.size();++i)
			cout<<lr2[i].first.first<<" "<<lr2[i].first.second<<" "<<lr2[i].second<<"\n";
	}
	else if(ans10==ans)
	{
		cout<<ans10<<endl;
		for(int i=0;i<ud2.size();++i)
			cout<<ud2[i].first.first<<" "<<ud2[i].first.second<<" "<<ud2[i].second<<"\n";
	}
	else if(ans11==ans)
	{
		cout<<ans11<<endl;
		for(int i=0;i<lr3.size();++i)
			cout<<lr3[i].first.first<<" "<<lr3[i].first.second<<" "<<lr3[i].second<<"\n";
	}
	else if(ans12==ans)
	{
		cout<<ans12<<endl;
		for(int i=0;i<ud3.size();++i)
			cout<<ud3[i].first.first<<" "<<ud3[i].first.second<<" "<<ud3[i].second<<"\n";
	}
	else if(ans13==ans)
	{
		cout<<ans13<<endl;
		for(int i=0;i<lr4.size();++i)
			cout<<lr4[i].first.first<<" "<<lr4[i].first.second<<" "<<lr4[i].second<<"\n";
	}
	else if(ans14==ans)
	{
		cout<<ans14<<endl;
		for(int i=0;i<ud4.size();++i)
			cout<<ud4[i].first.first<<" "<<ud4[i].first.second<<" "<<ud4[i].second<<"\n";
	}
	else if(ans15==ans)
	{
		cout<<ans15<<endl;
		for(int i=0;i<lr5.size();++i)
			cout<<lr5[i].first.first<<" "<<lr5[i].first.second<<" "<<lr5[i].second<<"\n";
	}
	else if(ans16==ans)
	{
		cout<<ans16<<endl;
		for(int i=0;i<ud5.size();++i)
			cout<<ud5[i].first.first<<" "<<ud5[i].first.second<<" "<<ud5[i].second<<"\n";
	}
	else if(ans17==ans)
	{
		cout<<ans17<<endl;
		for(int i=0;i<lr6.size();++i)
			cout<<lr6[i].first.first<<" "<<lr6[i].first.second<<" "<<lr6[i].second<<"\n";
	}
	else if(ans18==ans)
	{
		cout<<ans18<<endl;
		for(int i=0;i<ud6.size();++i)
			cout<<ud6[i].first.first<<" "<<ud6[i].first.second<<" "<<ud6[i].second<<"\n";
	}
	else if(ans19==ans)
	{
		cout<<ans19<<endl;
		for(int i=0;i<lr7.size();++i)
			cout<<lr7[i].first.first<<" "<<lr7[i].first.second<<" "<<lr7[i].second<<"\n";
	}
	else if(ans20==ans)
	{
		cout<<ans20<<endl;
		for(int i=0;i<ud7.size();++i)
			cout<<ud7[i].first.first<<" "<<ud7[i].first.second<<" "<<ud7[i].second<<"\n";
	}
	else if(ans21==ans)
	{
		cout<<ans21<<endl;
		for(int i=0;i<lr8.size();++i)
			cout<<lr8[i].first.first<<" "<<lr8[i].first.second<<" "<<lr8[i].second<<"\n";
	}
	else if(ans22==ans)
	{
		cout<<ans22<<endl;
		for(int i=0;i<ud8.size();++i)
			cout<<ud8[i].first.first<<" "<<ud8[i].first.second<<" "<<ud8[i].second<<"\n";
	}
	else if(ans23==ans)
	{
		cout<<ans23<<endl;
		for(int i=0;i<lr9.size();++i)
			cout<<lr9[i].first.first<<" "<<lr9[i].first.second<<" "<<lr9[i].second<<"\n";
	}
	else if(ans24==ans)
	{
		cout<<ans24<<endl;
		for(int i=0;i<ud9.size();++i)
			cout<<ud9[i].first.first<<" "<<ud9[i].first.second<<" "<<ud9[i].second<<"\n";
	}
	return 0;
}
