inp = input()


def parse_command(inp):
  args = inp.replace("","",1).split(" ")
  return args

args = parse_command(inp)

a = int(args[0])
b = int(args[1])
c = int(args[2])
d = int(args[3])
e = int(args[4])
f = int(args[5])
g = int(args[6])

randlist = [a,b,c,d,e,f,g]


empty = []

for item1 in randlist:
        for item2 in randlist:
                for item3 in randlist:
                        item1=int(item1)
                        item2 = int(item2)
                        item3 = int(item3)
                        empty.append([item1, item2, item3])

for item in empty:
        value1 = item[0]
        value2 = item[1]
        value3 = item[2]
        if value1+value2 in randlist and value2+value3 in randlist and value1+value3 in randlist and value1+value2+value3 in randlist:
                a1 = min(value1,value2, value3)
                a3 = max(value1,value2, value3)
                a2 = value1+value2+ value3 - a1 - a3
                print(a1, a2, a3)
                break