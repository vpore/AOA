#include <stdio.h>

void selectionSort(int arr[], int n){
    int i, j, k, min, temp;

    for(i=0; i<=n-2; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;

        for(k=0; k<n; k++){
            printf("%d\t", arr[k]);
        }
        printf("\n");
    }

    printf("Sorted Array:\n");
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

    selectionSort(arr, n);
}