package Practice;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-08 00:15:13
 * 
 * @author macinchang
 */
public class PotionsEasy {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        new Solver().solve(scanner);
        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            // f[i] = max(f[j]) + 1;
            // f[i][j] = max(f[k][j - 1] + a[i], f[k][j])
            /*
             * 5 -3 -2 -1 -1 -1 -1 -1
             * 
             * 10 -4 -6 5 -1 -1 -1 -1
             */
            int n = scanner.nextInt();
            long[] a = new long[n];
            long[][] f = new long[n][n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            f[0][1] = a[0] >= 0 ? a[0] : -1;
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= i + 1; j++) {
                    f[i][j] = i + 1 <= j ? -1 : f[i - 1][j];
                    if (f[i - 1][j - 1] >= 0 && f[i - 1][j - 1] + a[i] >= 0) {
                        f[i][j] = Math.max(f[i][j], f[i - 1][j - 1] + a[i]);
                    }
                }
            }

            long ans = 0;
            for (int i = n; i >= 1; i--) {
                if (f[n - 1][i] >= 0) {
                    ans = i;
                    break;
                }
            }
            System.out.println(ans);

        }
    }
}
