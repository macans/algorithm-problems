package Practice;

import java.util.Scanner;
import java.io.File;

/**
 * https://codeforces.com/problemset/problem/1385/D
 * 
 * Created on 2022-07-06 20:05:12
 * 
 * @author macinchang
 */
public class AGoodString {

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
            char[] s = scanner.next().toCharArray();
            int[][] f = new int[n][26], d = new int[n][26];
            int m = n;
            while (m > 0) {
                for (int i = 0; i < m; i++) {
                    for (int ch = 0; ch < 26; ch++) {
                        if (n == m) {
                            if (s[i] != ch + 'a') {
                                f[i][ch] = 1;
                                d[i][ch] = 1;
                            }
                            continue;
                        }
                        if (ch + 'a' == 'z') {
                            f[i][ch] = Integer.MAX_VALUE;
                        } else {
                            f[i][ch] = Math.min(d[i * 2][ch] + f[i * 2 + 1][ch + 1],
                                    f[i * 2][ch + 1] + d[i * 2 + 1][ch]);

                        }
                        d[i][ch] = d[i * 2][ch] + d[i * 2 + 1][ch];
                    }
                }
                m >>= 1;
            }
            System.out.println(f[0][0]);
        }
    }
}
