/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
class Main3 
{
    public static int check(int l)
    {
        while(l>0)
        {
            if(l%10==4 || l%10==7)
            {
                return 1;
            }
            else
            {
                l/=10;
            }
        }
        return 0;
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        int t=Integer.parseInt(str);
        int i;
        for(i=0;i<t;++i)
        {
            String str1=br.readLine();
            int n=Integer.parseInt(str1);
            int j,count=0;
            for(j=1;j<=Math.sqrt(n);++j)
            {
                if(n%j==0)
                {
                    if(j!=(n/j))
                    {
                        count=count+check(j)+check(n/j);
                    }
                    else
                    {
                        count=count+check(j);
                    }
                }
            }
            System.out.println(count);
        }
    }
}
