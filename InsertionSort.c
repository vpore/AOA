#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n){ //Insertion Sort function
    int i, val, j, k;
    for(i=1; i<n; i++){ //looping array from index-1 till last index
        val = arr[i]; 
        j = i-1;     
        while(j>=0 && arr[j]>val){ //while loop to sort the array elements
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=val;

        printf("\n");
        for(k=0; k<n; k++){ //Printing each iteration of Sorted Array
            printf("%d\t", arr[k]);
        }
        printf("\n");
    }

    printf("\nSorted Array:\n"); //Printing sorted array
    for(k=0; k<n; k++){
        printf("%d\t", arr[k]);
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

    insertionSort(arr, n); //Function call passing array and size of array as arguments
}