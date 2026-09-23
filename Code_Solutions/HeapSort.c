#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;

    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
        
    }
    if(largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr,n,largest);
    }
    //return 1;
}

void heap_sort(int arr[],int n){
    int i;
     for(i=n/2-1;i>=0;i--){
        heapify(arr,n,n/2-1);
       
    // }12, -3, 7, 12, 5, 0, 15, -1, 8
    for(int j=n-1;j>0;j--){
            int temp=arr[0];
            arr[0]=arr[j];
            arr[j]=temp;
            heapify(arr,j,0);
    }
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void main(){

    int n,i;
    clock_t start,end;
    double cpu_time;
    printf("Enter size:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array Elements:");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    start=clock();
    //heap_sort(arr,n);
    heap_sort(arr,n);
    end=clock();
    cpu_time=(double)(end-start)/CLOCKS_PER_SEC*100000;
    
    printf("\n");
    printf("\n Time taken is: %f micro sec",cpu_time);
}