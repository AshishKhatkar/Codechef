/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
class HELPLIRA 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        int n=Integer.parseInt(str);
        int i;
        int[] ar=new int[n];
        int max_index=0,min_index=0;
        for(i=0;i<n;++i)
        {
            String[] str1=br.readLine().split(" ");
            int x1=Integer.parseInt(str1[0]);
            int y1=Integer.parseInt(str1[1]);
            int x2=Integer.parseInt(str1[2]);
            int y2=Integer.parseInt(str1[3]);
            int x3=Integer.parseInt(str1[4]);
            int y3=Integer.parseInt(str1[5]);
            ar[i]=Math.abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
            if(ar[i]<=ar[min_index])
            {
                min_index=i;
            }
            if(ar[i]>=ar[max_index])
            {
                max_index=i;
            }
        }
        min_index+=1;
        max_index+=1;
        System.out.println(min_index+" "+max_index);
    }
}
