package R807;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-15 21:25:11
 * 
 * @author macinchang
 */
public class D {

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
            int n = scanner.nextInt();
            char[] s = scanner.next().toCharArray(), t = scanner.next().toCharArray();
            int[] ss = new int[n - 1], tt = new int[n - 1];
            if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
                System.out.println(-1);
                return;
            }
            int cnts = 0, cntt = 0;
            for (int i = 1; i < n; i++) {
                ss[i - 1] = (s[i] - '0') ^ (s[i - 1] - '0');
                tt[i - 1] = (t[i] - '0') ^ (t[i - 1] - '0');
                cnts += ss[i - 1] == 1 ? 1 : 0;
                cntt += tt[i - 1] == 1 ? 1 : 0;
            }
            if (cnts != cntt) {
                System.out.println(-1);
                return;
            }
            int i = 0, j = 0;
            long ans = 0L;
            while (i < n - 1 && j < n - 1) {
                while (i < n - 1 && ss[i] != 1) {
                    ++i;
                }
                while (j < n - 1 && tt[j] != 1) {
                    ++j;
                }
                if (i < n - 1 && j < n - 1) {
                    ans += Math.abs(i - j);
                    ++i;
                    ++j;
                }
            }
            System.out.println(ans);
        }
    }
}