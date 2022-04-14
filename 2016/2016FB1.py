import math
f = open("pails.in", "r")
ps = f.readlines()
pails= list(map(int,ps[0].split())) 

value=0
for i in range (0, math.floor(pails[2]/pails[0])+1):
    val = pails[2]-pails[0]*i
    thing = math.floor(val/pails[1])
    if pails[0]*i + thing*pails[1]> value:
        value=pails[0]*i+thing*pails[1]

o = value
file1 = open("pails.out", "w")
file1.writelines(str(o))
file1.close()