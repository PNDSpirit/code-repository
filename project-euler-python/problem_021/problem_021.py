def divisors_sum(number):
	total = 1
	i = 2
	while (i * i <= number):
		if number % i == 0:
			total += i
			total += number // i
		i += 1
	return total

divisors = [0]
for i in range(1, 10001):
	divisors.append(divisors_sum(i))

total = 0
for i in range(1, 10001):
	if (divisors[i] <= 10000 and divisors[divisors[i]] == i and i != divisors[i]):
		total += i
		# print("added the number at index " + str(i))

print(total)
