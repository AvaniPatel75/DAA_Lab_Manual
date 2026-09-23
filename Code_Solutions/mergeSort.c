#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    k=0;
    for (i = left; i <= right; i++) {
        arr[i] = temp[k++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void main() {
     clock_t start,end;
    double cpu_time;
    int size,i,j;
    printf("Enter size of array:");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("enter %d element :",i);
        scanf("%d",&arr[i]);
    }
    printf("array:\n");
    for(int i=0;i<size;i++){
        printf(" %d\t",arr[i]);
        
    }
    start=clock();
    mergeSort(arr,0,size-1);
    end=clock();
    printf("Sorted array:\n");
    for(int i=0;i<size;i++){
        printf(" %d\t",arr[i]);
        
    }
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf seconds\n", cpu_time);
}