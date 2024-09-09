import java.util.Arrays;
import java.util.Comparator;

public class Sample {

    public static void main(String[] args) {
        int[][] num = new int[10][10];
        Arrays.sort(num, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0] && a[1] == b[1]) {
                    return 1;
                }
                if (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1])) {
                    return 1;
                }
                return -1;
            }
        });
    }
}