package R806;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class GG {

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
            long k = scanner.nextLong();
            long[] a = new long[n], sum = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
                if (i == 0) {
                    sum[0] = a[0];
                } else {
                    sum[i] = sum[i - 1] + a[i];
                }
            }
            long ans = 0;
            for (int i = 0; i <= n; i++) {
                long cur = i != 0 ? sum[i - 1] - k * i : 0;
                int t = 1;
                for (int j = i; j < Math.min(n, i + 32); j++) {
                    cur += (a[j] >> t);
                    t++;
                }
                ans = Math.max(cur, ans);
            }
            System.out.println(ans);
        }
    }
}
