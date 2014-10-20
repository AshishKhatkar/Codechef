/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
class CAOS1 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String c = br.readLine();
        int t = Integer.parseInt(c);
        int i;
        for(i=0;i<t;++i)
        {
            String [] d = br.readLine().split(" ");
            int R = Integer.parseInt(d[0]);
            int C = Integer.parseInt(d[1]);
            String [][] ch = new String[R][C];
            int j,k,count=0;
            for(j=0; j<R; ++j)
            {
                String str = br.readLine();
                for(k=0; k<C; ++k)
                {
                    ch[j][k] = str.substring(k,k+1);
                }
            }
            int l,m;
            for(l=2; l<R-2;++l)
            {
                for(m=2; m<C-2; ++m)
                {
                    int ar[] = {0,0,0,0};
                    if(ch[l][m].equals("^"))
                    {
                        int w,x,y,z;
                        for(w=m-1; w>=0; --w)
                        {
                            if(ch[l][w].equals("#"))
                            {
                                break;
                            }
                            else
                            {
                                ar[0]++;
                            }
                        }
                        for(x=m+1; x<C; ++x)
                        {
                            if(ch[l][x].equals("#"))
                            {
                                break;
                            }
                            else
                            {
                                ar[1]++;
                            }
                        }
                        for(y=l-1; y>=0; --y)
                        {
                            if(ch[y][m].equals("#"))
                            {
                                break;
                            }
                            else
                            {
                                ar[2]++;
                            }
                        }
                        for(z=l+1; z<R; ++z)
                        {
                            if(ch[z][m].equals("#"))
                            {
                                break;
                            }
                            else
                            {
                                ar[3]++;
                            }
                        }
                        int min = ar[0],a;
                        for(a=1; a<4;++a)
                        {
                            if(ar[a]<min)
                            {
                                min=ar[a];
                            }
                        }
                        if(min>1)
                        {
                            count++;
                        }
                    }
                }
            }
            System.out.println(count);
        }
    }  
}
