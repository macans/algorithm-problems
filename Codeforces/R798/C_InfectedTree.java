package R798;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-10 00:01:36
 * 
 * @author macinchang
 */
public class C_InfectedTree {

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
        int[][] edges;
        int[] son;
        int[] dp;

        public void calculate(int x, int father) {
            if (x == 0) {
                return;
            }
            int left = 0, right = 0;
            for (int i = 1; i <= edges[x][0]; i++) {
                if (edges[x][i] == father) {
                    continue;
                }
                if (left == 0) {
                    left = edges[x][i];
                } else {
                    right = edges[x][i];
                }
            }
            calculate(left, x);
            calculate(right, x);
            son[x] = son[left] + son[right] + 1;
            if (left == 0 && right == 0) {
                dp[x] = 0;
            } else {
                dp[x] = Math.max(son[right] - 1 + dp[left], son[left] - 1 + dp[right]);
            }
        }

        public void solve(Scanner scanner) {
            /*
             * dp[i] 表示 i 感染后所能保留的最多节点数
             * son[i] 表示 i 的子节点数量
             * dp[i] = max(son[right[i]] + dp[left[i]], son[left[i]] + dp[right[i]])
             */
            int n = scanner.nextInt();
            int x, y;
            edges = new int[n + 1][5];
            son = new int[n + 1];
            dp = new int[n + 1];
            for (int i = 0; i < n - 1; i++) {
                x = scanner.nextInt();
                y = scanner.nextInt();
                edges[x][++edges[x][0]] = y;
                edges[y][++edges[y][0]] = x;
            }

            calculate(1, 0);
            System.out.println(dp[1]);

        }
    }
}
