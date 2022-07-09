package R804;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-09 20:17:02
 * 
 * @author macinchang
 */
public class AlmostTernaryMatrix {

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
            int n = scanner.nextInt(), m = scanner.nextInt();
            int[][] a = new int[n][m];
            a[0][0] = 1;
            a[0][1] = 0;
            a[1][0] = 0;
            a[1][1] = 1;
            for (int i = 2; i < m; i++) {
                int diff = (a[1][i - 1] ^ a[1][i - 2]) + (a[1][i - 1] ^ a[0][i - 1]);
                if (diff == 2) {
                    a[1][i] = a[1][i - 1];
                } else {
                    a[1][i] = 1 ^ a[1][i - 1];
                }
                diff = (a[0][i - 1] ^ a[0][i - 2]) + (a[0][i - 1] ^ a[1][i - 1]);
                if (diff == 2) {
                    a[0][i] = a[0][i - 1];
                } else {
                    a[0][i] = 1 ^ a[0][i - 1];
                }
            }
            for (int i = 2; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int tmp = a[i - 1][j] ^ a[i - 2][j];
                    if (j != m - 1) {
                        tmp += a[i - 1][j] ^ a[i - 1][j + 1];
                    }
                    if (j != 0) {
                        tmp += a[i - 1][j] ^ a[i - 1][j - 1];
                    }
                    if (tmp == 2) {
                        a[i][j] = a[i - 1][j];
                    } else {
                        a[i][j] = 1 ^ a[i - 1][j];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(a[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}
