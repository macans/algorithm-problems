package R807;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-15 21:25:11
 * 
 * @author macinchang
 */
public class B {

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
            long[] a = new long[n];
            long ans = 0;
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
            }

            int j = 0;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] != 0) {
                    continue;
                }
                while (j < i && a[j] == 0) {
                    ++j;
                }
                if (j < i) {
                    a[j]--;
                    a[i]++;
                    ans++;
                }
            }
            for (int i = 0; i < n - 1; i++) {
                ans += a[i];
            }
            System.out.println(ans);
        }
    }
}