/**
 *
 * @author ashish1610
 */
import java.io.*;
class ERROR 
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            String str=br.readLine();
            if(str.contains("101")||str.contains("010"))
            {
                System.out.println("Good");
            }
            else
            {
                System.out.println("Bad");
            }
        }
    }
}
