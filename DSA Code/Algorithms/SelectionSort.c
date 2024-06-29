#include<stdio.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void SelectionSort(int* arr, int n){
    int temp;
    for (int i=0; i<n-1; i++) // For number of passes, i.e., n-1.
    {
        int MinIndex = i;
        printf("\nNumber of Pass: %d\n", i+1);
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[MinIndex]){ //If arr[j] is small then assign new MinIndex = j.
            MinIndex = j; 
            }
            
        }
        temp = arr[i];          //Swaping the arr[i] and arr[MinIndex] element.
        arr[i] = arr[MinIndex];
        arr[MinIndex] = temp;

    }
}



int main(){
        int  n = 7;
        int arr[] = {1, 2, 89, 5, 67, 45, 3};
        // int arr[] = {1, 2, 3, 5, 8 , 9, 11}; //Already Sorted.
        printArr(arr, n);
        SelectionSort(arr, n);
        printf("\nAfter Sorting:\n");
        printArr(arr, n);
    return 0;
}