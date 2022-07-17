package R802;


import java.util.Scanner;
import java.io.File;

/**
 * Created on  2022-06-19 18:22:27 
 * 
 * @author macinchang
 */
public class A_OptimalPath {

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
            long n = scanner.nextLong(), m = scanner.nextLong();
            long tmp = n * ((n - 1) * m + 2) / 2;
            long a = tmp + (m - 1L) * n + m * (m + 1) / 2L - m;
            long b = tmp + m * (n- 1L) * m + m * (m + 1) / 2L - (m * (n - 1L) + 1);
            System.out.println(Math.min(a, b));
        }
    }
}
