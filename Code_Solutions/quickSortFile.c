#include<stdio.h>
#include<time.h>

int pivot(long int arr[],int i,int j){
    int k=i+1;
    int l=j;
    long int p=arr[i];
    long int temp=0;
    while(k<l){
        while(k <= j && arr[k] <= p)
            k++;
        
        while(l>i && arr[l] > p)
            l--;
        
        if(k<l){
            temp=arr[l];
            arr[l]=arr[k];
            arr[k]=temp;
        }
    }
    temp=arr[i];
    arr[i]=arr[l];
    arr[l]=temp;
    return l;
}
void quickSort(long int arr[],int i,int j){
    
    if(i<j){
        int p=pivot(arr,i,j);
        quickSort(arr,i,p-1);
        quickSort(arr,p+1,j);
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
        fscanf(fb,"%lld",&arr[i]);
    }
    fclose(fb);
    start=clock();
    quickSort(arr,0,n-1);
    printf("sorted....");
    end=clock();
    cpu_time=(double)(end-start)/CLOCKS_PER_SEC*1000;
    
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n Time taken is: %f micro sec",cpu_time);
}
