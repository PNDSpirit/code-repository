array = []
i = 1
while len(array) < 1000000:
	# print(array)
	for a in str(i):
		array.append(int(a))
	i += 1

product = 1
for i in range(0, 7):
	product *= int(array[10 ** i - 1])
print(product)