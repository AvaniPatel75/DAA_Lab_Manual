#include<stdio.h>
#include<stdlib.h>


int binarySearch(int arr[],int size,int key,int left,int right){
    // int left=0;
    // int right=size-1;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            return binarySearch(arr,size,key,mid+1,right);
        }
        else{
            return binarySearch(arr,size,key,left,mid-1);
        }

    }
    return -1;
}
void main(){

    int size,key,ans;
    printf("Enter size of array");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element you want to find:");
    scanf("%d",&key);
    ans=binarySearch(arr,size,key,0,size-1);
    printf("given elemtn found at index %d",ans);
}