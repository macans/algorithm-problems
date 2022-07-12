package R806;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class F_YetAnotherProblemAboutSatisfyingAnInequality {

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
            int[] a = new int[n + 1];
            long[] cnt = new long[n + 1];
            long totalCnt = 0L;
            for (int i = 1; i <= n; i++) {
                a[i] = scanner.nextInt();
                if (i > a[i] && a[i] != 0) {
                    ++totalCnt;
                    if (a[i] <= n) {
                        ++cnt[a[i]];
                    }
                }
            }
            long ans = 0;
            int j = 1;
            for (int i = 1; i <= n; i++) {
                if (i <= a[i]) {
                    continue;
                }
                for (; j <= i; j++) {
                    totalCnt -= cnt[j];
                }
                ans += totalCnt;
            }
            System.out.println(ans);
        }
    }
}
