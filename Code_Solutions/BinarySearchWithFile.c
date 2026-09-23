#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(const long int arr[], int size, long int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int size, i, ans;
    long int key;
    printf("Enter size of array: ");
    scanf("%d", &size);

    long int arr[size];
    FILE *fb;
    clock_t start, end;
    double cpu_time;
    char file_name[100];

    printf("Enter file name with %d size: ", size);
    scanf("%99s", file_name);

    printf("Enter element you want to find: ");
    scanf("%ld", &key);

    fb = fopen(file_name, "r");
    if (fb == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < size; i++) {
        if (fscanf(fb, "%ld", &arr[i]) != 1) {
            printf("Not enough numbers in the file.\n");
            fclose(fb);
            return 1;
        }
    }

    fclose(fb);

    start = clock();
    ans = binarySearch(arr, size, key);
    end = clock();
    cpu_time = (double)(end - start)*1000000 / CLOCKS_PER_SEC;

    if (ans != -1) {
        printf("Given element is on index %d\n", ans);
    } else {
        printf("Given element is not found in the array.\n");
    }

    printf("Time taken is: %.2f microseconds\n", cpu_time);
    return 0;
}