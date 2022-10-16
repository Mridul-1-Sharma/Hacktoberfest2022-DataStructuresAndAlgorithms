#include <iostream>
using namespace std;

void selectionsort(int *array, int size){
    // main logic for selection sort
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size ; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j]= temp;
            }
        }
    }
    
    // now printing the array after sorting
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<" selection sort successfully executed  "<<endl;
}

int main() {
    cout<<" Enter the size of array"<<endl;
    
    int n;  //size of array
    cin>>n;
    
    cout<< " Enter the element in array "<<endl;
    
    int array[n];  // unsorted array
    
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    
    selectionsort(array, n); //function calling
    return 0;
}
