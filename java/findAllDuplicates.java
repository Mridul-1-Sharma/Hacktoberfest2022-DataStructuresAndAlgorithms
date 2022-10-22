import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class findAllDuplicates {
    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 8, 4, 7, 6, 5, 4, 2, 8};
        System.out.println(cycle(arr));
    }

    public static List<Integer> cycle(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[i] != arr[correct]) {
                swap(arr, i, correct);
            } else i++;
        }
        for (int j = 0; j < arr.length; j++) {
            if (arr[j] != j + 1) {
                list.add(arr[j]);
            }
        }
        return list;
    }

    public static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
