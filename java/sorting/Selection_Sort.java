package Algorithms_Code.Java;

public class Selection_Sort {   
    
    void selection_sort(int arr[]){
        int n = arr.length;
        for (int i = 0; i < n - 1; i++){
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
        
    public static void main(String args[]){
        
    }

}
