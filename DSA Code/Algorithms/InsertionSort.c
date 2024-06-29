#include<stdio.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void InsertionSort(int* arr, int n){

    for (int i=1; i<n; i++) // For number of passes, i.e., n-1. (Also, 1st element is sorted in Insertion Sort, so start from index 1.)
    {
        int temp = arr[i];
        int j=i-1;
        printf("\nNumber of Pass: %d\n", i);
        for (j; j>=0; j--) // For comparison and swap inside each pass. (It compares the previous element so, i-1, and j--)
        {
           if (arr[j]>temp)
           {
            arr[j+1] = arr[j];
           }
           else break;
           
        }
        arr[j+1] = temp;
    }
}



int main(){
        int  n = 7;
        int arr[] = {1, 2, 89, 5, 67, 45, 3};
        // int arr[] = {1, 2, 3, 5, 8 , 9, 11}; //Already Sorted.
        printArr(arr, n);
        InsertionSort(arr, n);
        printf("\nAfter Sorting:\n");
        printArr(arr, n);
    return 0;
}