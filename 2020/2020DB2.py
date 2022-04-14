inp1 = input()
inp2=input()

def parse_command(inp):
  args = inp.replace("","",1).split(" ")
  return args

args = parse_command(inp2)

def average(lst):
        sums= 0
        x=0
        for item in lst:
                sums += item
                x+=1
        final = sums/x
        return final
        
inp1 = int(inp1)

x=0
p = []

while x<inp1:
        p.append(int(args[x]))
        x+=1

ans=0


for i in range (0, inp1):
        for j in range (0, inp1):
                if i>=j:
                        k=j
                        flow = []
                        while k<=i:
                                flow.append(p[k])
                                k+=1
                        avg = average(flow)

                        if avg in flow:
                                ans+=1

print(ans)