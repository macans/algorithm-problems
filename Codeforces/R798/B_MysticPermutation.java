package R798;

import java.io.File;
import java.util.Scanner;

/**
 * Created on 2022-06-11 0
 * 
 * @author macinchang
 */
public class B_MysticPermutation {

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
            int[] p = new int[n + 5];
            int[] q = new int[n + 5];
            q[0] = 1;
            for (int i = 1; i <= n; i++) {
                p[i] = scanner.nextInt();
                q[i] = i;
            }
            boolean no = false;
            for (int i = 1; i <= n; i++) {
                if (p[i] == q[i]) {
                    int tmp = q[i];
                    q[i] = q[i == n ? i - 1 : i + 1];
                    q[i == n ? i - 1 : i + 1] = tmp;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (p[i] == q[i]) {
                    no = true;
                }
            }
            if (no) {
                System.out.println(-1);
                return;
            }
            for (int i = 1; i <= n; i++) {
                System.out.print(q[i] + " ");
            }
            System.out.println();

        }
    }
}
