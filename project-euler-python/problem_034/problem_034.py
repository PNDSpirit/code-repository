import math

# 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
def is_curious_number(number):
	total = 0
	for i in str(number):
		total += math.factorial(int(i))
	if total == number:
		return 1
	return 0

total = 0
for i in range(3, 362881):
	if is_curious_number(i):
		total += i
print(total)