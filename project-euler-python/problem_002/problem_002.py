a = 1
b = 1
sum = 0
while a + b < 4000000:
	b, a = a + b, b
	if b % 2 == 0:
		sum += b
print(sum)