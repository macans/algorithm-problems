import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=391 lang=java
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
    boolean[] mask;

    public boolean isRectangleCover(int[][] rectangles) {
        int totalArea = 0;
        Set<String> points = new HashSet<>();
        String tmp;
        int[] cornerPoints = new int[4];
        cornerPoints[0] = Integer.MAX_VALUE;
        cornerPoints[1] = Integer.MAX_VALUE;
        cornerPoints[2] = Integer.MIN_VALUE;
        cornerPoints[3] = Integer.MIN_VALUE;
        for (int i = 0; i < rectangles.length; i++) {
            cornerPoints[0] = Math.min(cornerPoints[0], rectangles[i][0]);
            cornerPoints[1] = Math.min(cornerPoints[1], rectangles[i][1]);
            cornerPoints[2] = Math.max(cornerPoints[2], rectangles[i][2]);
            cornerPoints[3] = Math.max(cornerPoints[3], rectangles[i][3]);

            totalArea += (rectangles[i][3] - rectangles[i][1])
                    * (rectangles[i][2] - rectangles[i][0]);

            tmp = rectangles[i][0] + " " + rectangles[i][1];
            if (!points.add(tmp)) {
                points.remove(tmp);
            }

            tmp = rectangles[i][0] + " " + rectangles[i][3];
            if (!points.add(tmp)) {
                points.remove(tmp);
            }

            tmp = rectangles[i][2] + " " + rectangles[i][3];
            if (!points.add(tmp)) {
                points.remove(tmp);
            }

            tmp = rectangles[i][2] + " " + rectangles[i][1];
            if (!points.add(tmp)) {
                points.remove(tmp);
            }
        }
        if (points.size() != 4
                || !points.contains(cornerPoints[0] + " " + cornerPoints[1])
                || !points.contains(cornerPoints[0] + " " + cornerPoints[3])
                || !points.contains(cornerPoints[2] + " " + cornerPoints[3])
                || !points.contains(cornerPoints[2] + " " + cornerPoints[1])) {
            return false;
        }
        return totalArea == (cornerPoints[3] - cornerPoints[1]) * (cornerPoints[2] - cornerPoints[0]);

    }
}
// @lc code=end
