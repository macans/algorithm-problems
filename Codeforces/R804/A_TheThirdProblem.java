package R804;

import java.util.Scanner;
import java.io.File;

/**
 * <https://codeforces.com/contest/1699/problems>
 * p[x] 为 x 的在原置换中的坐标, t[x] 为 x 在新置换中的坐标
 * 对于 0：
 * mex(p[0]) = 1, mex(t[0]) = 1, 因此 p[0] = t[0]
 * 对于 1：
 * mex(p[1]) = 0, mex(t[1]) = 0, 因此 p[1] = t[1]
 * 对于 2：
 * 若 p[2] < p[0] < p[1], 则 mex(p[2], p[0]) = 1, mex(0, p[2]) = 0, 因此 p[2] = t[2]
 * 若 p[2] > p[1] > p[0], 同理使得 p[2] = t[2]
 * 若 p[0] < p[2] < p[1], 则使 t[2] 满足 t[0] < t[2] < t[1] 即可
 * 对于 k > 2 的情况，与 2 作类似的处理
 * Created on 2022-07-09 20:45:13
 * 
 * @author macinchang
 */
public class A_TheThirdProblem {

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
            int[] a = new int[n];
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
                p[a[i]] = i;
            }
            if (n == 1) {
                System.out.println(1);
                return;
            }
            int left = Math.min(p[0], p[1]), right = Math.max(p[0], p[1]);
            long ans = 1;
            long mod = 1000000007L;
            for (int i = 2; i < n; i++) {
                if (p[i] > left && p[i] < right) {
                    ans = (ans * (right - left + 1 - i)) % mod;
                } else {
                    left = Math.min(left, p[i]);
                    right = Math.max(right, p[i]);
                }
            }
            System.out.println(ans);
        }
    }
}
