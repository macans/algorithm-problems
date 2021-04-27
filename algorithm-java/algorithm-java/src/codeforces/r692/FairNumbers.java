package codeforces.r692;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 * @author zhangji05
 * Created on 2020-12-30
 */
public class FairNumbers {

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("/Users/zhangji05/Code/algorithm-problems/algorithm-java/algorithm-java/src/in.txt"));
        int t = input.nextInt();
        while (t-- > 0) {
            long n = input.nextLong();
            while (n < Long.MAX_VALUE) {
                if (isFair(n)) {
                    System.out.println(n);
                    break;
                }
                ++n;
            }
        }
        input.close();
    }

    private static boolean isFair(long x) {
        long y = x;
        while (y >= 10L) {
            if (y % 10L != 0L && x % (y % 10L) != 0L) {
                return false;
            }
            y /= 10L;
        }
        return true;
    }
}
