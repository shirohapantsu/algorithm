"""素数筛：欧式筛法 时间复杂度为O(n)"""

NUM=100
primes=[]
count=0

num=[False]*(NUM+1)
for i in range(2,NUM+1):
    if num[i]==False:
        primes.append(i)
        count+=1
    for j in primes:
        if j*i<=NUM:
            num[j*i]=True
            if i%j==0:
                break

for i in range(0,count):
    print(f"{primes[i]:5d}",end="")
    if (i+1)%5==0:
        print()


