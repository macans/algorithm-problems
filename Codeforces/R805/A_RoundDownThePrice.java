package R805;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-10 22:33:23
 * 
 * @author macinchang
 */
public class A_RoundDownThePrice {

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
            int[] ten = new int[10];
            ten[0] = 1;
            for(int i = 1; i < 10; i++) {
                ten[i] = ten[i - 1] * 10;
            }
            int n = scanner.nextInt();
            for(int i = 9; i >= 0; i--) {
                if(ten[i] <= n) {
                    System.out.println(n - ten[i]);
                    break;
                }
            }
        }
    }
}
