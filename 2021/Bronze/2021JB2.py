import math

amt = int(input())
ids = input()

idlist = list(map(int, ids.split()))

evens = 0
odds=0
maxs=0
for item in idlist:
        if item%2==0:
                evens+=1
        else:
                odds+=1

if evens < odds:
        maxs+=2*evens
        diff = odds-evens
        if diff%3==2:
                maxs+= 1+2*math.floor(diff/3)
        elif diff%3==0:
                maxs+= 2*math.floor(diff/3)
        else:
                maxs+=2*math.floor(diff/3)-1
elif evens == odds:
        maxs=2*evens
else:
        maxs=2*odds+1

print(maxs)