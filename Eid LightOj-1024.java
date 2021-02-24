import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new  Scanner(System.in);
        int t;
        int n,a;

        t=sc.nextInt();
        for(int i=1;i<=t;i++) {
            n=sc.nextInt();
            int[] arr=new int[n];
            for(int j=0;j<n;j++) {
                arr[j]=sc.nextInt();
            }
            BigInteger result=lcm(arr,n);
            System.out.println("Case "+i+": "+result);
            System.gc();
        }
        sc.close();

    }

    public static BigInteger lcm(int[] arr,int n)
    {
        BigInteger l=BigInteger.valueOf(arr[0]);
         for(int i=1;i<n;i++) {
             BigInteger r=BigInteger.valueOf(arr[i]);
              BigInteger val=gcd(l,r);
              l=l.multiply(r).divide(val);
         }
         return l;
    }
    public static BigInteger  gcd(BigInteger a,BigInteger b)
    {
        //System.out.println(a+" "+b);
        if(a.mod(b).equals(BigInteger.ZERO))return b;
        return gcd(b,a.mod(b));
    }

}

