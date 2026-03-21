/*素数筛：朴素算法，时间复杂度为O(n)*/
#include <stdio.h>
#include <math.h>
#define num 100

int prime_arr[num];

int prime(int n)
{

    prime_arr[0] = 2;

    int i, j, k = 1;
    _Bool flag;

    for (i = 3; i < n; i++)
    {
        for (j = 2; j <= sqrt(i); j++)
        {
            flag = 1;
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            prime_arr[k] = i;
            k++;
        }
    }
    return k;
}

int main()
{
    int i;
    int k = prime(num);

    for (i = 0; i < k; i++)
    {
        printf("%5d", prime_arr[i]);
        if ((1 + i) % 5 == 0)
            printf("\n");
    }
    return 0;
}