/*
* @author ashish1610
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
class CASOS3 
{
    public static boolean correct_point(int x1,int y1,int x2,int y2)
    {
        return (x1>x2 || y1>y2)?false:true;
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        int i,z;
        for(z=0;z<t;++z)
        {
            int dnp[][][][]=new int[25][25][25][25];
            int array[][]=new int[25][25];
            int volcano_points[][]=new int[25][25];
            String[] str=br.readLine().split(" ");
            int n=Integer.parseInt(str[0]);
            int m=Integer.parseInt(str[1]);
            int j;
            for(j=0;j<n;++j)
            {
                String str1=br.readLine();
                int k;
                for(k=0;k<str1.length();++k)
                {
                    if(str1.substring(k,k+1).equals("#"))
                    {
                        array[j][k]=1;
                    }
                }
            }
            int a,b;
            for(a=2;a<n-2;++a)
            {
                for(b=2;b<m-2;++b)
                {
                    if((array[a][b]==1) || (array[a-1][b]==1) || (array[a-2][b]==1) || (array[a+1][b]==1) || (array[a+2][b]==1))
                    {
                        volcano_points[a][b] = 1;
                    }
                    if((volcano_points[a][b]==1) || (array[a][b-1]==1) || (array[a][b-2]==1) || (array[a][b+1]==1) || (array[a][b+2]==1))
                    {
                        volcano_points[a][b] = 1;
                    }
                    volcano_points[a][b] ^= 1;
                }
            }
            for(a = 1; a <= n; a++)
            {
		for(b = 1; b <= m; b++)
		{
                    for(i = 0; i < n-a+1; i++)
                    {
                        for(j = 0; j < m-b+1; j++)
                        {
                            ArrayList<Integer> s=new ArrayList<>();
                            for(int x = i; x < i+a; x++)
                            {
                                for(int y = j; y < j+b; y++)
				{
                                    if (volcano_points[x][y]==1)
                                    {
                                        int num = 0;
					if (correct_point(i,j,x-1,y-1))
                                        {
                                            num ^= dnp[i][j][x-1][y-1];
                                        }
					if (correct_point(x+1,j,i+a-1,y-1))
                                        {
                                            num ^= dnp[x+1][j][i+a-1][y-1];
                                        }
                                        if (correct_point(i,y+1,x-1,j+b-1))
                                        {
                                            num ^= dnp[i][y+1][x-1][j+b-1];
                                        }
					if (correct_point(x+1,y+1,i+a-1,j+b-1))
                                        {
                                            num ^= dnp[x+1][y+1][i+a-1][j+b-1];
                                        }
					s.add(num);
                                    }
                                }
                            }   
                            int p = 0;
                            while(s.indexOf(p) != -1)
                            {
                                p++;
                            }
                            dnp[i][j][i+a-1][j+b-1] = p;
                        }
                    }
                }
            }
            if(dnp[0][0][n-1][m-1]!=0)
            {
                System.out.println("Asuna");
            }
            else
            {
                System.out.println("Kirito");
            }
        }
    }
}
 
