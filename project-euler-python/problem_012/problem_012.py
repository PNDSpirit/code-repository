import math

def number_of_divisors(number):
	divisors = 0
	for x in range(1, int(math.sqrt(number)) + 1):
		if number % x == 0:
			divisors += 1
	if math.sqrt(number).is_integer():
		return divisors * 2 - 1
	return divisors * 2

number = 0
n = 1
while True:
	number += n
	n += 1
	# print(number)
	if number_of_divisors(number) > 500:
		print(number)
		break;

