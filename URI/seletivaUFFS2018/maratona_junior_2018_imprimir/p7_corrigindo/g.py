n = input()
c = []
d = []
for a in range(0,int(n)):
	aux = input()
	c.append([aux,a])
	d.append([aux,a])

for a in c:
	a[0] = a[0].lower()

c.sort()

for a in c:
	a[0] = d[a[1]][0]

b = 0

for a in c:
	if(b != 0):
		if(c[b-1][0].lower() == c[b][0].lower()):
			for x in range(0,b-1):
				ixi = b-x
				if(c[ixi-1][0].lower() == c[ixi][0].lower()):
					aux1 = []
					aux1.append(c[ixi-1][0])
					aux1.append(c[ixi][0])
					aux1.sort()
					c[ixi-1][0] = aux1[0]
					c[ixi][0] = aux1[1]
				else:
					break

	b += 1

for a in c:
	print("{}".format(a[0]))
