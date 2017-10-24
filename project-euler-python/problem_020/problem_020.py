def factorial(number):
	for i in range(1, number):
		number *= i
	return number

total = 0
for char in str(factorial(100)):
	total += int(char)
print(total)