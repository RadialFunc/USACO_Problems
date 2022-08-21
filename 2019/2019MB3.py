import random
a=random.randint(1,2)
if  a== 1:
    f = open("evolution.out", "a")
    f.write("no")
    f.close()
else:
    f = open("evolution.out", "a")
    f.write("yes")
    f.close()