"""素数筛：朴素算法，时间复杂度为O(sqrt(n)*n)"""

num=100
primes=[2]

import math
count=1
for i in range(3,num):
    if all(i%j!=0 for j in range (2,int(math.sqrt(i)+1))):
        primes.append(i)
        count+=1

for i in range(0,count):
    print(f"{primes[i]:5d}",end="")
    if (i+1)%5==0:
        print()

