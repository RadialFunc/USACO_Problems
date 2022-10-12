n = int(input())
greater = []
lesser=[]
for k in range (0,n):
    operator, num = input().split()
    if operator == "G":
        greater.append(int(num))
    else:
        lesser.append(int(num))

greater.sort(reverse=True)
lesser.sort(reverse=False)
possible = []
for k in range (0, len(greater)):
    ele = greater[k]
    for b in range (0, len(lesser)):
        if lesser[b]>=ele:
            possible.append(b+k)
            break
if possible == []:
    print(min(len(greater), len(lesser)))
else:
    print(min(possible))