/*素数筛：埃氏筛法 时间复杂度为N*log(log(N))*/
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
            for (j = i * i; j <= n; j += i)
            {
                num_arr[j] = 1;
            }
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

/*
该算法的（中文）名字“埃氏筛”是“埃拉托斯特尼筛法”的简称。其基本思想是：

创建一个布尔（或整数）数组 isPrime[0...n]，初始时将所有从 2 到 n 的数都标记为“可能是素数”（例如 true 或 1）。

从第一个素数 p = 2 开始。

将 p 的所有倍数（p*p, p*p + p, p*p + 2p, ...）标记为“不是素数”（false 或 0）。

优化：我们从 p*p 开始标记，而不是 2*p。因为像 2*p, 3*p...(p-1)*p 这样的数，它们已经被比 p 更小的素数（如 2, 3 等）给筛掉了。

找到下一个未被标记的数，将其设为新的 p（这个数必定是素数）。

重复步骤 3 和 4，直到 p*p 大于 n。

最后，数组中所有仍被标记为“可能是素数”的索引（下标）就是素数。*/