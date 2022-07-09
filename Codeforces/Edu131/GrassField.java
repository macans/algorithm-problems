package Edu131;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-08 22:33:24
 * 
 * @author macinchang
 */
public class GrassField {

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
            int a, b, c, d;
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            d = scanner.nextInt();
            if (a + b + c + d == 0) {
                System.out.println(0);
            }

            else if (a != 0 && b != 0 && c != 0 && d != 0) {
                System.out.println(2);
            } else {
                System.out.println(1);
                ;
            }

        }
    }
}
