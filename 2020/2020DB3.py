n = int(input())

eaten = []
cows = []
for i in range (0,n):
    info = input()
    info = info.split()
    info[1] = int(info[1])
    info[2] = int(info[2])
    info.append(0)
    info.append(True)
    cows.append(info)

for i in range (0,600):
    today = []
    for k in range (0,n):
        if cows[k][4] ==True:
            cell = [cows[k][1], cows[k][2]]
            
            if cell in eaten:
                cows[k][4]=False
            else:
                today.append(cell)
    for k in range (0,n):
        if cows[k][4] == True:
            cell = [cows[k][1], cows[k][2]]
            cows[k][3]+=1
            if cows[k][0] == "N":
                cows[k][2]+=1
            else:
                cows[k][1]+=1
    for val in today:
        eaten.append(val)
for i in range (0,n):
    if cows[i][4]==False:
        print(cows[i][3])
    else:
        print("Infinity")