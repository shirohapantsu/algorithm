"""素数筛：埃氏筛法 时间复杂度为N*log(log(N))"""

NUM=100
primes=[]
count=0


num=[False]*(NUM+1)
for i in range(2,NUM+1):
    if num[i]==False:
        primes.append(i)
        count+=1
        for j in range(i*i,NUM+1,i):
            num[j]=True

for i in range(0,count):
    print(f"{primes[i]:5d}",end="")
    if (i+1)%5==0:
        print()


