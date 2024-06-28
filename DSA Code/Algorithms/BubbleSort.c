#include<stdio.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void BubbleSort(int* arr, int n){
    int temp = 0;
    for (int i=0; i<n-1; i++) // For number of passes, i.e., n-1.
    {
        for (int j=0; j<n-i-1; j++) // For comparison and swap inside each pass.
        {
           if (arr[j]>arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
           }
           
        }
        
    }
}


void AdaptBubbleSort(int* arr, int n){
    int temp = 0;
    int sorted = 1;
    for (int i=0; i<n-1; i++) // For number of passes, i.e., n-1.
    {
        printf("\nNumber of Pass: %d\n", i+1);
        for (int j=0; j<n-i-1; j++) // For comparison and swap inside each pass.
        {
           if (arr[j]>arr[j+1])
           {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            sorted = 0;
           }
           
        }
        if(sorted){
            printf("Already Sorted!!\n");
            return;
        }
        
    }
}



int main(){
        int  n = 7;
        int arr[] = {1, 2, 89, 5, 67, 45, 3};
        // int arr[] = {1, 2, 3, 5, 8 , 9, 11};
        printArr(arr, n);
        // BubbleSort(arr, n);
        AdaptBubbleSort(arr, n);
        printf("\nAfter Sorting:\n");
        printArr(arr, n);
    return 0;
}