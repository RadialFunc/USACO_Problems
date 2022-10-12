import re

f = open("censor.in", "r")
data = f.readlines()

words = data[0]
censor=data[1]
values=[words]
while True:
    values.insert(0, re.sub(censor,"",values[0],count=1))
    if values[0]==values[1]:
        break

with open('censor.out', 'w') as g:
    g.write(values[0])

