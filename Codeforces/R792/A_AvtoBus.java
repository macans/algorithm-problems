package R792;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-17 15:31:16
 * 
 * @author macinchang
 */
public class A_AvtoBus {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        Solver solver = new Solver(scanner);
        while (t-- > 0) {
            solver.solve();
        }
        scanner.close();
    }

    public static class Solver {
        private Scanner sc;

        Solver(Scanner scanner) {
            this.sc = scanner;
        }

        public void solve() {
            long n = sc.nextLong();
            if (n % 2 == 1 || n < 4) {
                System.out.println(-1);
                return;
            }
            long x = n / 4;

            long x1 = n / 6, y1 = n % 6;
            if (y1 == 2 || y1 == 4) {
                x1++;
            }
            System.out.println(x1 + " " + x);
        }
    }
}
