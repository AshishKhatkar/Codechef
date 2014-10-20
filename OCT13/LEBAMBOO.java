/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
class LEBAMBOO
{
    public static void main(String[] args)throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        int t = Integer.parseInt(str);
        for(int i=0;i<t;++i)
        {
            int flag=-1,count=0;
            String str1=br.readLine();
            int n=Integer.parseInt(str1);
            int[] a=new int[n];
            int[] b=new int[n];
            int[] c=new int[n];
            String[] str2=br.readLine().split(" ");
            for(int j=0;j<n;++j)
            {
                a[j]=Integer.parseInt(str2[j]);
            }
            String[] str3=br.readLine().split(" ");
            for(int k=0;k<n;++k)
            {
                b[k]=Integer.parseInt(str3[k]);
            }
            for(int l=0;l<n;++l)
            {
                c[l]=a[l]-b[l];
            }
            if(n==1)
            {
                if(a[0]>=b[0])
                {
                    flag=1;
                    count=a[0]-b[0];
                }
                else
                {
                    flag=0;
                }
            }
            else
            {
                while(true)
                {
                    Arrays.sort(c);
                    if((c[0]==0)&&(c[n-1]==0))
                    {
                        break;
                    }
                    for(int m=0;m<n-1;++m)
                    {
                        c[m]++;
                    }
                    c[n-1]--;
                    count++;
                    flag=1;
                    if(count>=50)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        flag=1;
                    }
                }
            }
            if((flag==0)||(count>=50))
            {
                System.out.println(-1);
            }
            else
            {
                System.out.println(count);
            }
        }
    }
} 
