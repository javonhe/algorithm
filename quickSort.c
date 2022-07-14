/*
快速排序的原理：在待排序的一组数中，任意找一个基准数，一般是第一个或者最后一个
然后将比基准小的数放到左边，比基准大的数放到右边
经过多次轮询操作，最终完成
*/


#include <stdio.h>
#include <stdlib.h>

#define N 7

//以key的值作为基准，比它小的数放在左边，比它大的数放在右边
int partition(int *arr, int low, int high)
{
    int key;

    key = arr[low];

    while(low < high)
    {
        while(low < high && arr[high] >= key) //从右开始，寻找比key小的数
            high--;

        if (low < high)
            arr[low++] = arr[high];

        while(low < high && arr[low] <= key) //从左开始，寻找比key大的数
            low++;

        if (low < high)
            arr[high--] = arr[low];
    }

    arr[low] = key;

    return low;
}


void quickSort(int *arr, int start, int end)
{
    int pos;

    if (start < end)
    {
        pos = partition(arr, start, end);

        //对左右两边的数，分别递归做
        quickSort(arr, start, pos-1);

        quickSort(arr, pos+1, end);
    }

    return;
}


int main(void)
{
    int i;
    int arr[N] = {32, 12, 7, 40, 78, 23, 45};

    quickSort(arr, 0, N-1);

    for (i = 0; i < N; i++)
        printf("%d\t", arr[i]);

    printf("\n");

}
