# if the argument can be written with the sum of it's digits to the 5th power
def can_be_written(number):
	total = 0
	for n in str(number):
		total += int(n) ** 5
	if total == number:
		return 1
	return 0

total = 0
for i in range(2, 354295):
	if can_be_written(i):
		total += i

print(total)