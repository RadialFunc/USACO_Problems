n = int(input())
di1 = input()
di2 = input()
di3 = input()
di4=input()

se = {"oauiwuowiowi"}
tot ={"dodpdidd"}
for letter in di1:
	tot.add(letter)
	se.add(letter)
for letter in di2:
	tot.add(letter)
	se.add(letter)
for letter in di3:
	tot.add(letter)
	se.add(letter)
for letter in di4:
	tot.add(letter)
	se.add(letter)

for a in di1:
	for b in di2:
		se.add(a+b)
		se.add(b+a)
	for b in di3:
		se.add(a+b)
		se.add(b+a)
	for b in di4:
		se.add(a+b)
		se.add(b+a)
for a in di2:
	for b in di3:
		se.add(a+b)
		se.add(b+a)
	for b in di4:
		se.add(a+b)
		se.add(b+a)
for a in di3:
	for b in di4:
		se.add(a+b)
		se.add(b+a)

for a in di1:
	for b in di2:
		for c in di3:
			se.add(a+b+c)
			se.add(a+c+b)
			se.add(c+a+b)
			se.add(c+b+a)
			se.add(b+c+a)
			se.add(b+a+c)
		for c in di4:
			se.add(a+b+c)
			se.add(a+c+b)
			se.add(c+a+b)
			se.add(c+b+a)
			se.add(b+c+a)
			se.add(b+a+c)
	for b in di3:
		for c in di4:
			se.add(a+b+c)
			se.add(a+c+b)
			se.add(c+a+b)
			se.add(c+b+a)
			se.add(b+c+a)
			se.add(b+a+c)

for a in di2:
	for b in di3:
		for c in di4:
			se.add(a+b+c)
			se.add(a+c+b)
			se.add(c+a+b)
			se.add(c+b+a)
			se.add(b+c+a)
			se.add(b+a+c)

for a in di1:
	for b in di2:
		for c in di3:
			for d in di4:
				se.add(d+a+b+c)
				se.add(d+a+c+b)
				se.add(d+c+a+b)
				se.add(d+c+b+a)
				se.add(d+b+c+a)
				se.add(d+b+a+c)
				se.add(a+d+b+c)
				se.add(a+d+c+b)
				se.add(c+d+a+b)
				se.add(c+d+b+a)
				se.add(b+d+c+a)
				se.add(b+d+a+c)
				se.add(a+b+d+c)
				se.add(a+c+d+b)
				se.add(c+a+d+b)
				se.add(c+b+d+a)
				se.add(b+c+d+a)
				se.add(b+a+d+c)
				se.add(a+b+c+d)
				se.add(a+c+b+d)
				se.add(c+a+b+d)
				se.add(c+b+a+d)
				se.add(b+c+a+d)
				se.add(b+a+c+d)
ye=[]
for k in range (1,n+1):
	wor = input()
	if wor in se:
		ye.append("YES")
	else:
		ye.append("NO")

for item in ye:
	print(item)