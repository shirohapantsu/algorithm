/*素数筛：欧式筛法 时间复杂度为O(n)*/
#include <stdio.h>
#include <string.h>

#define NUM 100

int num_arr[NUM + 1];
int prime_arr[NUM];

int prime(int n)
{
    int i, j, k = 0;
    memset(num_arr, 0, (NUM + 1) * sizeof(int));

    for (i = 2; i <= n; i++)
    {
        if (num_arr[i] == 0)
        {
            prime_arr[k++] = i;
        }
        for (j = 0; j < k && prime_arr[j] * i <= n; j++)
        {
            num_arr[prime_arr[j] * i] = 1;
            if (i % prime_arr[j] == 0)
                break;
        }
    }
    return k;
}

int main()
{
    int i;
    int k = prime(NUM);
    for (i = 0; i < k; i++)
    {
        printf("%5d", prime_arr[i]);
        if ((1 + i) % 5 == 0)
            printf("\n");
    }
    return 0;
}