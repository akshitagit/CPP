n=int(input())
count1=[0]*n
arr1=input()
arr=list(map(int,arr1.split(' ')))


mean=sum(arr)/n
arr.sort()
if n%2==0:
    median=(arr[int(n/2)-1]+arr[int(n/2)])/2
else:
    median=arr[n/2]

for i in range(0,n-1):
    for j in range(0,n-1):
        if arr[i]==arr[j]:
            count1[i]=int(count1[i])+1

val=max(count1)
for i in range(0,n-1):
    if val==count1[i]:
        mode=arr[i]
        break

print("{:.2f}\n{:.2f}\n{}".format(mean,median,mode))

