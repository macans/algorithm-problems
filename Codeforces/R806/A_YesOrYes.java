package R806;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class A_YesOrYes {

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
            String s = scanner.next();
            String yes = "yes";
            System.out.println(yes.equals(s.toLowerCase()) ? "YES" : "NO");
        }
    }
}
