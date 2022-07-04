package R306;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-17 23:36:49
 * 
 * @author macinchang
 */
public class DivisibilityByEight {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        new Solver().solve(scanner);
        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            String str = scanner.next();
            char[] s = str.toCharArray();
            int n = s.length;
            int tmp;
            if (n == 1) {
                tmp = s[0] - '0';
                if (tmp % 8 == 0) {
                    System.out.println("YES");
                    System.out.println(tmp);
                } else {
                    System.out.println("NO");
                }
                return;
            }
            if (n == 2) {
                tmp = (s[0] - '0') * 10 + s[1] - '0';
                int tmp1 = tmp / 10;
                int tmp2 = tmp % 10;

                if (tmp % 8 == 0) {
                    System.out.println("YES");
                    System.out.println(tmp);
                } else if (tmp1 % 8 == 0) {
                    System.out.println("YES");
                    System.out.println(tmp1);
                }
                if (tmp2 % 8 == 0) {
                    System.out.println("YES");
                    System.out.println(tmp2);
                } else {
                    System.out.println("NO");
                }
                return;
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {

                        for (int ii = 0; ii < 2; ii++) {
                            for (int jj = 0; jj < 2; jj++) {
                                for (int kk = 0; kk < 2; kk++) {
                                    if (ii == 0 && jj == 0 && kk == 0) {
                                        continue;
                                    }
                                    int x = 1;
                                    tmp = 0;
                                    if (ii != 0) {
                                        tmp = s[i] - '0';
                                        x = 10;
                                    }
                                    if (jj != 0) {
                                        tmp = x * tmp + s[j] - '0';
                                        x = 10;
                                    }
                                    if (kk != 0) {
                                        tmp = x * tmp + s[k] - '0';
                                    }
                                    if (tmp % 8 == 0) {
                                        System.out.println("YES");
                                        System.out.println(tmp);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            System.out.println("NO");
        }
    }
}