import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] arg) {
		Scanner cin = new Scanner(System.in);
		int T;
		T = cin.nextInt();
		for(int i = 1; i <= T; ++i) {
			BigInteger a = cin.nextBigInteger(), b = cin.nextBigInteger();
			System.out.println("Case " + i + ":\n" + a + " + " + b + " = " + a.add(b));
			if(i != T)	System.out.println();
		}
	}
}

