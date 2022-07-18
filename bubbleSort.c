/* 冒泡算法
 * 原理：每一轮，通过两两比较，将最大的数排到最后面，经过多次操作后，形成从左到右，从小到大的排列
 * 特性：冒泡排序空间复杂度为O(1)，是原地排序算法
 *       相同大小的数据在排序前后，不会改变顺序，是稳定的排序算法
 *       最好时间复杂度是O(n)，最坏时间复杂度是O(n^2)，平均时间复杂度是O(n)
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubbleSort(int *a, int n)
{
    if (n <= 1) return;

    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1]) //循环将最大的数，放到末尾
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;

                flag = true;
            }

        }

        if (!flag)
            break;
    }
}


int main(void)
{
    int arr[6] = {2, 10, 6, 0, 5, 4};

    bubbleSort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}
