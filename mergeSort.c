/* 归并排序
 *主要原理是：把数据对半分，分别对两边的数据做排序，最后合并起来
 */

#include <stdlib.h>
#include <stdio.h>

void merge_sort_recursive(int *arr, int *reg, int start, int end) {
    if (start >= end)
        return;

    int len = end - start, mid = (len >> 1) + start;

    int start1 = start, end1 = mid;

    int start2 = mid + 1, end2 = end;

    //通过递归方式，把数据对半分
    merge_sort_recursive(arr, reg, start1, end1);

    merge_sort_recursive(arr, reg, start2, end2);

    //比较大小排序
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

    while (start1 <= end1)
        reg[k++] = arr[start1++];

    while (start2 <= end2)
        reg[k++] = arr[start2++];

    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void merge_sort(int *arr, const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}


int main(void)
{
    int array[6] = {3, 2, 5, 1, 8, 4};

    merge_sort(array, 6);

    for(int i = 0; i < 6; i++)
        printf("%d\t", array[i]);

    printf("\n");

    return 1;
}
