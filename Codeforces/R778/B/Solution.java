
package R778.B;

import java.util.Scanner;

/**
 * @author macinchang
 * Created on 2022-03-20 19:55:03
 */

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean[] cnt = new boolean[26];
        int head;
        while(scanner.hasNext()) {
            int t = scanner.nextInt();
            while(t-- > 0) {
                for(int i = 0; i < 26; i++) {
                    cnt[i] = false;
                }
                head = 0;
                String s = scanner.next();
                for(int i = s.length() - 1; i >= 0; i--) {
                    if(!cnt[s.charAt(i) - 'a']){
                        head = i;
                        cnt[s.charAt(i) - 'a'] = true;
                    }
                }
                String ans = s.substring(head);
                System.out.println(ans);
            }
        }
        scanner.close();
    }
}
