package R778;

import java.util.Scanner;

// <https://codeforces.com/contest/1654/problems>
public class A_Maximum_Cake_Tastiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int t = scanner.nextInt();
            while (t-- > 0) {
                int n = scanner.nextInt();
                long a = Long.MIN_VALUE, b = Long.MIN_VALUE;
                for (int i = 0; i < n; i++) {
                    long x = scanner.nextLong();
                    if (x > a) {
                        b = a;
                        a = x;
                    } else if (x == a) {
                        b = a;
                    } else {
                        b = Math.max(x, b);
                    }
                }
                System.out.println(a + b);
            }
        }
        scanner.close();
    }
}
