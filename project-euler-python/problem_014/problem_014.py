def collatz_terms(starting_number):
	count = 1
	while starting_number != 1:
		if starting_number % 2 == 0:
			starting_number /= 2
		else:
			starting_number *= 3
			starting_number += 1
		count += 1
	return count

max_terms = 0
terms = 0
number = 0
for i in range(1, 1000000):
	terms = collatz_terms(i)
	if terms > max_terms:
		max_terms = terms
		number = i

print(number)
