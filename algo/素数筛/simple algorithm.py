"""素数筛：朴素算法，时间复杂度为O(n^2)"""

num=100
primes=[]

count=0
for i in range(2,num):
    if all(i%j!=0 for j in range (2,i)):
        primes.append(i)
        count+=1

for i in range(0,count):
    print(f"{primes[i]:5d}",end="")
    if (i+1)%5==0:
        print()


