#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sort_reg(int array[MAX][MAX], int start_x, int end_x, int start_y, int end_y) {
    int arr[MAX * MAX];
    int index = 0;
    
    for(int i = start_x; i < end_x; i++) {
        for(int j = start_y; i < end_y; j++) {
            arr[index++] = array[i][j];
        }
    }

    for(int i = 0; i < index; i++) {
        for(int j = 0; i < index; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    index = 0;

    for (int i = start_x; i < end_x; i++) {
        for(int j = start_y; j < end_y; j++) {
            array[i][j] = arr[index++];
        }
    }
}

void devide_sort(int array[MAX][MAX], int n) {
    int jum = n/2;

    sort_reg(array, 0, jum, 0, n);

    sort_reg(array, jum + 1, n, 0, n);

    sort_reg(array, jum, jum + 1, 0, jum);

    sort_reg(array, jum, jum + 1, jum + 1, n);
}

int main(void) {
    int n = 4;
    int array[MAX][MAX] = { 
        {10, 3, 5, 7},
        {4, 12, 9, 6},
        {11, 8, 14, 1},
        {2, 13, 15, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    devide_sort(array, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // sort_reg(array, 0, 0, n/2);
    return 0;
}