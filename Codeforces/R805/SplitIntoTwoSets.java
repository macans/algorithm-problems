package R805;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-11 00:00:19
 * 
 * @author macinchang
 */
public class SplitIntoTwoSets {

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
        class Edge {
            int from, to;
            Edge next;

            Edge(int from, int to, Edge next) {
                this.from = from;
                this.to = to;
                this.next = next;
            }
        }

        public void solve(Scanner scanner) {
            int n = scanner.nextInt();
            int x, y;
            int[] in = new int[n + 1];
            boolean flag = true;
            Edge[] edges = new Edge[n + 1];
            for (int i = 0; i < n; i++) {
                x = scanner.nextInt();
                y = scanner.nextInt();
            }
            for (int i = 1; i <= n; i++) {
                if (in[i] != 2) {
                    flag = false;
                }
            }
            System.out.println(flag ? "YES" : "NO");
        }
    }
}
