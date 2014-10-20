/*
 * @author : ashish1610
 */
import java.util.*;
import java.io.*;
class strings 
{
	public static int inf = 1000000000;
	public static int[][] lev_dis=new int[2][100005];
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t--!=0)
		{
			String str=br.readLine();
			String str1=br.readLine();
			String [] tmp=br.readLine().split(" ");
			int a=Integer.parseInt(tmp[0]);
			int b=Integer.parseInt(tmp[1]);
			int k=Integer.parseInt(tmp[2]);
			int len1=str.length();
			int len2=str1.length();
			if(a==0)
				System.out.println("0");
			else if(len1>len2+k/a || len2>len1+k/a)
					System.out.println("-1");
			else
			{
				for(int i=0;i<=k/a;++i)
					lev_dis[0][i]=i*a;
				for(int i=k/a+1;i<=len2;++i)
					lev_dis[0][i]=inf;
				for(int i=1;i<=len1;++i)
				{
					int minx=Math.max(1, i-k/a);
					int maxx=Math.min(i+k/a, len2);
					lev_dis[i&1][0]=i*a;
					if(minx>1)
						lev_dis[i&1][minx-1]=inf;
					if(maxx<len2)
						lev_dis[i&1][maxx+1]=inf;
					for(int j=minx;j<=maxx;++j)
					{
						int cost=str.charAt(i-1)==str1.charAt(j-1) ? 0:b;
						lev_dis[i&1][j]=Math.min(Math.min(lev_dis[(i&1)^1][j]+a, lev_dis[i&1][j-1]+a), lev_dis[(i&1)^1][j-1]+cost);
					}
				}
				int ans=lev_dis[len1&1][len2];
				//System.out.println(ans);
				if(ans<=k)
					System.out.println(ans);
				else
					System.out.println("-1");
			}
		}
	}
}
