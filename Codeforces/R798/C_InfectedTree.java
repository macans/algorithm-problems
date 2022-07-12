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
        int[] left, right, son;

        public void solve(Scanner scanner) {
            /*
             * dp[i] 表示 i 感染后所能保留的最多节点数
             * son[i] 表示 i 的子节点数量
             */
            int n = scanner.nextInt();
            int x, y;
            left = new int[n];
            right = new int[n];
            son = new int[n];
            for (int i = 0; i < n - 1; i++) {
                x = scanner.nextInt();
                y = scanner.nextInt();
                if (left[x] == 0) {
                    left[x] = y;
                } else {
                    right[x] = y;
                }
            }

        }
    }
}
