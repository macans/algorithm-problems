package Codeforces.R696;

import java.util.Scanner;

/**
 * @author zhangji05
 * Created on 2021-01-21
 */
public class DifferentDivisors {

    private static int[] getPrime(int n) {
        boolean[] isPrime = new boolean[n + 1];
        int[] prime = new int[n + 1];
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i]) {
                prime[cnt++] = i;
            }
            for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
                isPrime[i * prime[j]] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        return prime;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] prime = getPrime(1000000);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int d = scanner.nextInt();
            int right = 0;
            int left = 0;
            for (int i = 1; i < prime.length; i++) {
                if (prime[i] - prime[0] >= d) {
                    right = i;
                    break;
                }
            }

            while (left < right - 1 && prime[right] - prime[left] > d) {
                ++left;
            }
            System.out.println(prime[left] * prime[right]);
        }
        scanner.close();
    }
}
