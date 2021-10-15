
/**
 * @author macinchang
 * Created on  2021-08-05 16:27:06 
 */

import java.util.*;
import java.util.stream.Collectors;

public class ElevatorAlgorithm {

    public static void main(String[] args) {
        scan(arr, head, direction);
    }

    static void scan(List<Integer> arr, int head, boolean direction) {
        int seek_count = 0;
        int distance, cur_track;

        List<Integer> left = arr.stream()
        .filter(x -> x < head).collect(Collectors.toList());

        List<Integer> right = arr.stream().filter(x -> x > head).collect(Collectors.toList());

        int run = 2;
        while (run-- > 0) {
            if (direction == "left") {
                for (int i = left.size() - 1; i >= 0; i--) {
                    cur_track = left.get(i);

                    // appending current track to seek sequence
                    seek_sequence.add(cur_track);

                    // calculate absolute distance
                    distance = Math.abs(cur_track - head);

                    // increase the total count
                    seek_count += distance;

                    // accessed track is now the new head
                    head = cur_track;
                }
                direction = "right";
            } else if (direction == "right") {
                for (int i = 0; i < right.size(); i++) {
                    cur_track = right.get(i);

                    // appending current track to seek sequence
                    seek_sequence.add(cur_track);

                    // calculate absolute distance
                    distance = Math.abs(cur_track - head);

                    // increase the total count
                    seek_count += distance;

                    // accessed track is now new head
                    head = cur_track;
                }
                direction = "left";
            }
        }

        System.out.print("Total number of seek operations = " + seek_count + "\n");

        System.out.print("Seek Sequence is" + "\n");

        for (int i = 0; i < seek_sequence.size(); i++) {
            System.out.print(seek_sequence.get(i) + "\n");
        }
    }

}
