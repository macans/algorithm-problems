package R804;


import java.util.Scanner;
import java.io.File;

/**
 * Created on  2022-07-09 20:45:13 
 * 
 * @author macinchang
 */
public class TheThirdProblem {

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
            
        }
    }
}

