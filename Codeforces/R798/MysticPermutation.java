package R798;

import java.io.File;
import java.util.Scanner;

/**
 * Created on 2022-06-11 0
 * 
 * @author macinchang
 */
public class MysticPermutation {

    public static void main(String[] args) throws Exception {
        File inFile = new File("/Users/zhangji05/Code/algorithm-problems/in.txt");
        Scanner scanner = new Scanner(inFile);
        // Scanner scanner = new Scanner(System.in);
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
            int[] pos = new int[n + 5];
            for (int i = 1; i <= n; i++) {
                p[i] = scanner.nextInt();
                q[i] = i;
                pos[i] = i;
            }

            for (int i = 1; i <= n; i++) {
                if (p[i] != q[i]) {
                    continue;
                }
                for (int j = 1; j <= n; j++) {
                    if (pos[j] > i) {
                        int tmp = q[i];
                        q[i] = q[pos[j]];
                        q[pos[j]] = tmp;
                        tmp = pos[j];
                        pos[j] = i;
                        pos[q[pos[j]]] = tmp;
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                System.out.print(q[i] + " ");
            }
            System.out.println();

        }
    }
}
