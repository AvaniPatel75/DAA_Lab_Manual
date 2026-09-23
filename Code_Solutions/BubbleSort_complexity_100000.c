#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

void bubbleSort(int arr[], int n)
{
    int temp, swap=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0)
            break;
    }
}

void main()
{
    FILE *fp;
    clock_t start, end;
    int arr[SIZE];
    int n = SIZE;
    // Best Case
    // fp = fopen("best_100000.txt", "r");
    // if (fp == NULL){
    //     printf("Error opening best_100000.txt\n");
    //     return;}
    // for (int i = 0; i < n; i++){
    //     fscanf(fp, "%d", &arr[i]);
    // }
    // fclose(fp);
    // printf("Best Case Scenario\n");
    // start = clock();
    // bubbleSort(arr, n);
    // end = clock();
    // printf("Time Taken: %f seconds\n\n",
    //     (double)(end - start) / CLOCKS_PER_SEC);


    //average
    //  fp = fopen("avg_100000.txt", "r");

    // if (fp == NULL)
    // {
    //     printf("Error opening avg_100000.txt\n");
       
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     fscanf(fp, "%d", &arr[i]);
    // }

    // fclose(fp);

    // printf("Average Case Scenario\n");

    // start = clock();
    // bubbleSort(arr, n);
    // end = clock();

    // printf("Time Taken: %f seconds\n",
    //        (double)(end - start) / CLOCKS_PER_SEC);

    // Worst Case
    fp = fopen("worst_100000.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening worst_100000.txt\n");
        
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    printf("Worst Case Scenario\n");

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    printf("Time Taken: %f seconds\n\n",
           (double)(end - start) / CLOCKS_PER_SEC);

   

}