package R806;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class E_MirrorGrid {

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
            /*
             * 90: f[i][j] = f[j][n - 1 - i]
             */
            int n = scanner.nextInt();
            char[][] s = new char[n][n];
            for (int i = 0; i < n; i++) {
                s[i] = scanner.next().toCharArray();
            }
            int[] cnt = new int[2];
            boolean[][] mask = new boolean[n][n];
            int ans = 0;
            int tmp, x, y;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mask[i][j]) {
                        continue;
                    }
                    cnt[0] = 0;
                    cnt[1] = 0;
                    x = i;
                    y = j;
                    // 0
                    cnt[s[x][y] - '0']++;
                    mask[x][y] = true;

                    tmp = x;
                    x = y;
                    y = n - 1 - tmp;
                    // 90
                    cnt[s[x][y] - '0']++;
                    mask[x][y] = true;

                    tmp = x;
                    x = y;
                    y = n - 1 - tmp;
                    // 180
                    cnt[s[x][y] - '0']++;
                    mask[x][y] = true;

                    tmp = x;
                    x = y;
                    y = n - 1 - tmp;
                    // 270
                    cnt[s[x][y] - '0']++;
                    mask[x][y] = true;

                    ans += Math.min(cnt[0], cnt[1]);
                }
            }

            System.out.println(ans);

        }
    }
}
