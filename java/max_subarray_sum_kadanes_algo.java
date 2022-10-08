public class Main {

  public static int max_Sum(int a[]) {
    // maximum sum till now
    int sum = a[0];
    // most recent sum of subarray
    int sum_local = 0;

    // for-each loop is used to iterate over the array and find the maximum subarray sum
    for (int k : a) {
      sum_local = sum_local + k;
      //  update max sum
      sum = Math.max(sum, sum_local);

      // if running sum is negative then change it to 0

      if (sum_local < 0) sum_local = 0;
    }

    return sum;
  }

  // driver code

  public static void main(String[] args) {
    int[] arr = {2, -3, 5, 2, 0, -51, 44, -90, 32, -12};
    int ans = max_Sum(arr);
    System.out.println(ans);
  }
}


