package sorting;

import java.util.*;

public class Radix_Sort {

	public static void main(String[] args) {
		int arr[] = {90,49,29,10,65,32,43,73};
		System.out.println("Array before Sorting: " + Arrays.toString(arr));
		int max = Integer.MIN_VALUE;
		for (int i : arr) {
			max = Math.max(i, max);
		}
		int exp = 1;
		while (exp <= max) {
			radixSort(arr, exp);
			exp *= 10;
		}
		System.out.println("Array after Sorting: " + Arrays.toString(arr));
	}

	public static void radixSort(int[] arr, int exp) {
		int[] count = new int[10];

		// store frequency of each element in count[] according to their indices
		for (int i = 0; i < arr.length; i++) {
			count[arr[i] / exp % 10]++;
		}
		for (int i = 0; i < count.length; i++) {
			if (i == 0)
				count[i] = count[i] - 1;
			else
				count[i] = count[i] + count[i - 1];
		}

		// create a temporary array to store the sorted array
		int[] ans = new int[arr.length];
		for (int i = arr.length - 1; i >= 0; i--) {
			int index = count[arr[i] / exp % 10];
			ans[index] = arr[i];
			count[arr[i] / exp % 10]--;
		}

		// copy the sorted array to original array
		for (int i = 0; i < arr.length; i++)
			arr[i] = ans[i];
	}
}
