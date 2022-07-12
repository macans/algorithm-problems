package R113;

import java.util.Scanner;
import java.io.File;

/**
 * 166E
 * ABC 实际上是等价的三个点，维护一个状态即可
 * 另外有 log(n) 的做法是矩阵快速幂
 * 找到一个矩阵使得
 * [ a1, a2       [ dp[0]       [ dp[1]
 *   a3, a4]  *    dp[1] ]   =    dp[2] ]

 
 * Created on 2022-07-05 14:16:16
 * 
 * @author macinchang
 */
public class E_Tetrahedron {

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
            // ABCD -> 0123
            int n = scanner.nextInt();
            long mod = 1000000007L;
            long[][] dp = new long[2][2];
            dp[0][1] = 1;
            int i;
            int p = 0;
            for (i = 1; i <= n; i++) {
                dp[p ^ 1][1] = (dp[p][0] * 3) % mod;
                dp[p ^ 1][0] = (dp[p][0] * 2 + dp[p][1]) % mod;
                p ^= 1;
            }
            System.out.println(dp[p][1]);

        }
    }
}
