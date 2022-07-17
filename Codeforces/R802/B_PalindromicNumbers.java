package R802;

import java.util.Scanner;
import java.io.File;
import java.math.BigInteger;

/**
 * Created on 2022-06-19 17:52:58
 * 
 * @author macinchang
 */
public class B_PalindromicNumbers {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        while (t-- > 0) {
            new Solver().solve(scanner);
        }
        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            int len = scanner.nextInt();
            String s = scanner.next();
            BigInteger a = new BigInteger(s);

            if (s.charAt(0) == '1') {
                StringBuilder x1001 = new StringBuilder();
                x1001.append('1');
                for (int i = 1; i < len; i++) {
                    x1001.append('0');
                }
                x1001.append('1');
                BigInteger b = new BigInteger(x1001.toString());
                BigInteger ans = b.subtract(a);
                System.out.println(ans.toString());

            } else {
                StringBuilder x1111 = new StringBuilder();
                for (int i = 0; i < len + 1; i++) {
                    x1111.append('1');
                }
                BigInteger b = new BigInteger(x1111.toString());
                BigInteger ans = b.subtract(a);
                System.out.println(ans.toString());
            }

        }
    }
}
