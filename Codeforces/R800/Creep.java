package R800;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-17 01:05:18
 * 
 * @author macinchang
 */
public class Creep {

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
            int a, b;
            a = scanner.nextInt();
            b = scanner.nextInt();
            String s = "";
            int n = a + b;
            for (int i = 0; i < n;) {
                if (a > 0 && b <= 0) {
                    s += "0";
                    --a;
                    ++i;
                } else if (a <= 0 && b > 0) {
                    s += "1";
                    --b;
                    ++i;
                } else {
                    s += "10";
                    --a;
                    --b;
                    i += 2;
                }
            }
            System.out.println(s);
        }
    }
}
