import java.util.Scanner;

public class MergeSortedArrays {
    public static void merge(int arr1[], int arr2[], int m, int n) {
        int i = 0, j = 0, k = 0;
        int temp[] = new int[m + n];

        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                temp[k++] = arr1[i++];
            } else {
                temp[k++] = arr2[j++];
            }
        }
        while (i < m) {
            temp[k++] = arr1[i++];

        }
        while (j < n) {
            temp[k++] = arr2[j++];
        }
        for (int a = 0; a < m + n; a++) {
            arr1[a] = temp[a];
        }

    }

    public static void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m, n;
        System.out.println("Enter the size of both arr1 and arr2: (hint: arr1>=5 and arr2>=5) ");
        m = sc.nextInt();
        n = sc.nextInt();
        int arr1[] = new int[m + n];
        int arr2[] = new int[n];

        arr1[0] = 2;
        arr1[1] = 4;
        arr1[2] = 6;
        arr1[3] = 8;
        arr1[4] = 10;
        arr2[0] = 1;
        arr2[1] = 3;
        arr2[2] = 5;
        arr2[3] = 7;
        arr2[4] = 9;
        // printArray(arr3, 9);
        merge(arr1, arr2, m, n);
        printArray(arr1, m + n);
        sc.close();

    }
}