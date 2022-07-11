package R805;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-10 22:33:23
 * 
 * @author macinchang
 */
public class TrainAndQueries {

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
        boolean[] c;

        public void solve(Scanner scanner) {
            int n = scanner.nextInt(), m = scanner.nextInt();
            HashMap<Integer, ArrayList<Integer>> edge = new HashMap<>();
            int x;
            for (int i = 0; i < n; i++) {
                x = scanner.nextInt();
                if (edge.get(x) == null) {
                    edge.put(x, new ArrayList<Integer>());
                }
                edge.get(x).add(i);
            }
            int y;
            int left, right;
            for (int i = 0; i < m; i++) {
                x = scanner.nextInt();
                y = scanner.nextInt();
                left = edge.get(x) == null ? Integer.MAX_VALUE : edge.get(x).get(0);
                right = edge.get(y) == null ? Integer.MIN_VALUE : edge.get(y).get(edge.get(y).size() - 1);
                if (left < right) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
