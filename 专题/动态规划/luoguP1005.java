//写java的过程就很漫长了，什么都不知道的我
//1. 类的名字必须是Main，交上去的时候要改名字哦
//2. 测试用文件的时候，一定要加上throws IOException哦
//3. multiply只可以乘BigInteger类型，所以用BigInteger.valueOf()函数转换
//4. 这里dp的时候有个+1，所以如果不对dp[m+1]赋值的时候，是指针越界哦，因为第一个只是dp数组的指针声明，而不是变量的
//5. BigInteger里也有max函数，真是太棒了；若是double类型的话，可以用Math.max()
//6. ans.add()是返回一个BigInteger，必须要ans=ans.add()哦
//7. BigInteger输出用toString()
//8. memset函数，后来找到，如果数组不初始化就是0，对于其他的可以用Array.fill(array_name,value);
//9. 好啦，再有不会的和错误我就要疯掉了呢！
import java.util.*;
import java.math.*;
import java.lang.*;
import java.io.*;
public class P1005{
    public static void main(String[] args) throws IOException{
        // File file = new File("/Users/mrs_empress/Desktop/test/test/input");
        // Scanner cin = new Scanner(file);
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        int m=cin.nextInt();
        BigInteger []two=new BigInteger[100];
        two[0]=BigInteger.ONE;
        for(int i=1;i<=m;i++){
            two[i]=two[i-1].multiply(BigInteger.valueOf(2));
        }
        BigInteger ans=BigInteger.ZERO;
        BigInteger []a=new BigInteger[100];
        BigInteger []dp=new BigInteger[100];
        BigInteger x,y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[j]=cin.nextBigInteger();
                dp[j]=BigInteger.ZERO;
            }
            dp[m+1]=BigInteger.ZERO;
            for(int len=1;len<=m;len++){
                for(int j=1;j<=m;j++){
                    if(j+len-1>m) break;
                    x=dp[j+1].add(a[j].multiply(two[m-len+1]));
                    y=dp[j].add(a[j+len-1].multiply(two[m-len+1]));
                    dp[j]=x.max(y);
                    // System.out.println(x.toString()+ " "+y.toString());
                }
            }
            // System.out.println("dp1: "+dp[1].toString());
            ans=ans.add(dp[1]);
            // System.out.println("ans: "+ans.toString());
        }
        System.out.println(ans.toString());
    }
}