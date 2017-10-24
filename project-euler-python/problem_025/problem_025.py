index = 2
a = 1
b = 1
while len(str(a)) < 1000:
	a, b = a + b, a
	index += 1
print(index)