
class Solution {
    public int clumsy(int n) {
        int ans = 0;
        if (n == 3) {
            return 6;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 1) {
            return 1;
        }
        while(n >= 4) {
            int temp = n * (n - 1) / (n - 2);
            if (ans == 0) {
                ans = temp;
            } else {
                ans -= temp;
            }
            ans += n - 3;
            n -= 4;
        }
        
        if (n == 3) {
            ans -= 6;
        }
        if (n == 2) {
            ans -= 2; 
        }
        if (n == 1) {
            ans -= 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.clumsy(10));;
    }
}