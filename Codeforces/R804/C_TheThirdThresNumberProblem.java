package R804;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-09 20:00:28
 * 
 * @author macinchang
 */
public class C_TheThirdThresNumberProblem {

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
            int a = 0, b = n / 2, c = (n + 1) / 2;
            if ((a ^ b) + (b ^ c) + (a ^ c) != n) {
                System.out.println(-1);
            } else {
                System.out.print(a + " " + b + " " + c);
                System.out.println();
            }
        }
    }
}
