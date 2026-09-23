#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void heapify(long int arr[],int n,int i){
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
        arr[largest]= = temp;

        heapify(arr,n,largest);  // solve affected sub-tree
    }
}

void heap_sort(long int arr[],int n){
    // first max heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int j=n-1;j>0;j--){
            int temp=arr[0];
            arr[0]=arr[j];
            arr[j]=temp;
            heapify(arr,j,0); // heapify from root node i.e 0 
            // (to check subtree is max heap or not)
    }
   
}
void main(){
    int min_index=0,temp=0,n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    long int arr[n];
    FILE *fb;
    clock_t start,end;
    double cpu_time;
    char file_name[100];
    printf("Enter file name with %d size",n);
    scanf("%s", file_name);
    fb=fopen(file_name,"r");
    if (fb == NULL) {
        printf("Error opening file.\n");
        return ;
    }
    
    for(i=0;i<n;i++){
        fscanf(fb,"%d",&arr[i]);
    }
    fclose(fb);
    start=clock();
    heap_sort(arr,n);
    end=clock();
    cpu_time=(double)(end-start)/CLOCKS_PER_SEC*1000;
    
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n Time taken is: %f micro sec",cpu_time);
    
}