package Edu92;

import java.util.Scanner;
import java.io.File;

/**
 * Created on  2022-07-06 00:17:08 
 * 
 * @author macinchang
 */
public class C_GoodString {

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
            char[] a = scanner.next().toCharArray();
            int n = a.length;
            int ans = Integer.MIN_VALUE;
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    int cnt = 0;
                    boolean even = false;
                    for(int k = 0; k < n; k++) {
                        if((even && a[k] == i + '0')
                        || (!even && a[k] == j + '0')) {
                            ++cnt;
                            even = !even;
                        }
                    }
                    if(i == j || !even) {
                        ans = Math.max(ans, cnt);
                    }
                }
            }
            System.out.println(n - ans);
        }
    }
}

