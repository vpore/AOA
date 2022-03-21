#include<stdio.h>

void swap(int* a, int* b) { //Swapping array elements
    int t = *a; 
    *a = *b; 
    *b = t; 
}

void printArray(int arr[], int n){ // Print array
    for(int i = 0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}

int part(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    printf("SubArray:\n");
    printArray(arr, high-low+1);
    printf("\n\n");
    return i+1;
}

void quickSort(int arr[], int low, int high){ //Quick Sort function
    if(low < high){
        int x = part(arr, low, high);
        quickSort(arr, low, x-1);
        quickSort(arr, x+1, high);
    }
}

void main(){
    int n;
    printf("Enter size of array:\n"); //Input of size of array
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n"); //Input of elements of array
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    printf("Sorted Array:\n");
    printArray(arr, n);
}