package R806;

import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class D_DoubleStrings {

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
            Set<String> g = new HashSet<>();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = scanner.next();
                g.add(s[i]);
            }
            char[] res = new char[n];
            for (int i = 0; i < n; i++) {
                res[i] = '0';
                for (int j = 1; j < s[i].length(); j++) {
                    String s1 = s[i].substring(0, j);
                    String s2 = s[i].substring(j, s[i].length());
                    if (g.contains(s1) && g.contains(s2)) {
                        res[i] = '1';
                        break;
                    }
                }
            }
            System.out.println(res);
        }
    }
}
