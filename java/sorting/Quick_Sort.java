package Algorithms_Code.Java;

public class Quick_Sort {
 
    int partition (int a[], int start, int end)  {  
        int pivot = a[end];  
        int i = (start - 1);  
        for (int j = start; j <= end - 1; j++)  {  
            if (a[j] < pivot){  
                i++;  
                int t = a[i];  
                a[i] = a[j];  
                a[j] = t;  
            }  
        }  
        int t = a[i + 1];  
        a[i + 1] = a[end];  
        a[end] = t;  
        return (i + 1);  
    }  
        
    void quick_sort(int a[], int start, int end){  
        if (start < end)  {  
            int p = partition(a, start, end);  
            quick_sort(a, start, p - 1);  
            quick_sort(a, p + 1, end);  
        }
    }  

    public static void main(String args[]){
        
    }

}
