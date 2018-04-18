import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] arg) {
        Scanner cin = new Scanner(System.in);
        int cnt;
        BigInteger ans[] = new BigInteger[10005];
        ans[1] = ans[2] = ans[3] = ans[4] = BigInteger.ONE;
        while(cin.hasNext()) {
            cnt = cin.nextInt();
            for(int i = 5; i <= cnt; ++i)
                ans[i] = ans[i - 1].add(ans[i - 2].add(ans[i - 3].add(ans[i - 4])));
            System.out.println(ans[cnt]);
        }
    }
}