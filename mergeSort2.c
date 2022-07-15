/*
 *使用演绎法，实现归并算法
 */


#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return x < y ? x : y;
}


void merge_sort(int *arr, int len) {
    int *a = arr;
    int *b = (int *) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

int main(void)
{
    int array[13] = {6, 5, 3, 2, 7, 9, 8, 4, 10, 1, 11, 15, 13};

    merge_sort(&array[0], 13);

    for(int i = 0; i < 13; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("\n");
}
