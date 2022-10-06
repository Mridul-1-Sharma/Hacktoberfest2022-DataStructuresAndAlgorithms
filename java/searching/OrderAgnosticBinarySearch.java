//  Let's suppose if we don't know that the array is sorted in ascending or descending order. 
// First We need to identify whether the array is sorted in ascending order or descending order 
// to make the decision about whether to continue the search in the lower half of the array or 
// the upper half of the array

public class OrderAgnosticBinarySearch {
    public static void main(String[] args) {
        // int[] arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89}; // Ascending
        // Order
        int[] arr = { 99, 80, 75, 22, 11, 10, 5, 2, -3 }; // Descending order(
        int target = 22;
        int ans = orderAgnosticBS(arr, target);
        System.out.println(ans);
    }

    static int orderAgnosticBS(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        // find whether the array is sorted in ascending or descending
        boolean isAsc = arr[start] < arr[end]; /*(first arr example boolean value should be true,Second arr example boolean value should be false))*/

        while (start <= end) {
            // find the middle element
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (isAsc) {
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}