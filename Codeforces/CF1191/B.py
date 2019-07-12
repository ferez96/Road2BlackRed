def trans(x): return int(x[0])*10+{"m":0,"p":1,"s":2}[x[1]]
def isKoutsu(a,b,c): return a == b and a == c
def isShuntsu(a,b,c): 
	x, z = max(a,b,c), min(a,b,c)
	y = (a + b + c) - (x + z)
	return x - y == 10 and y - z == 10

a,b,c = map(trans, input().split(' '))
if isKoutsu(a,b,c) or isShuntsu(a,b,c):
	print(0)
	exit(0)
for i in range(1,10):
	for j in range(0,3):
		k = i*10+j
		if isKoutsu(a,b,k) or isKoutsu(a,c,k) or isKoutsu(c,b,k) or isShuntsu(a,b,k) or isShuntsu(a,c,k) or isShuntsu(c,b,k):
			print(1)
			exit(0)

print(2)