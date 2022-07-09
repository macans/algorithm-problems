package Practice;

import java.util.Scanner;
import java.io.File;

/**
 * 545C Dp
 * Created on 2022-07-05 01:00:48
 * 
 * @author macinchang
 */
public class Woodcutters {

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
            /*
             * x[i] h[i]
             * f[i][0] = max(f[i - 1][1], f[i - 1][2], f[i - 1][0])
             * f[i][1] = f[i - 1][0]
             * f[i][2]
             */
            int n = scanner.nextInt();
            int[][] tree = new int[n][2];
            for (int i = 0; i < n; i++) {
                tree[i][0] = scanner.nextInt();
                tree[i][1] = scanner.nextInt();
            }
            // 0 - keep, 1 - left, 2 - right
            int[][] f = new int[n][3];
            f[0][0] = 1;
            f[0][1] = 1;
            if (n == 1 || (tree[0][1] + tree[0][0] < tree[1][0])) {
                f[0][2] = 1;
            }
            for (int i = 1; i < n; i++) {
                // right
                f[i][2] = Math.max(f[i - 1][1] + 1, f[i - 1][0] + 1);
                if (tree[i - 1][0] + tree[i - 1][1] < tree[i][0]) {
                    f[i][2] = Math.max(f[i][2], f[i - 1][2] + 1);
                }

                // left
                if (tree[i][0] - tree[i][1] > tree[i - 1][0]) {
                    f[i][1] = Math.max(f[i - 1][0] + 1, f[i - 1][1] + 1);
                }
                if (tree[i][0] - tree[i][1] > tree[i - 1][0] + tree[i - 1][1]) {
                    f[i][1] = Math.max(f[i - 1][2] + 1, f[i][1]);
                }

                // keep
                f[i][0] = Math.max(f[i - 1][0], f[i - 1][1]);
                if (tree[i - 1][0] + tree[i - 1][1] < tree[i][0]) {
                    f[i][0] = Math.max(f[i][0], f[i - 1][2]);
                }
            }
            int ans = Math.max(f[n - 1][0], Math.max(f[n - 1][1], f[n - 1][2]));
            System.out.println(ans);
        }
    }
}
