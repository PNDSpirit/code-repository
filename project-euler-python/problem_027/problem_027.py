def is_prime(number):
	i = 2
	if number <= 1:
		return 0
	while (i * i <= number):
		if number % i == 0:
			return 0
		i += 1
	return 1

def consec_primes_count(a, b):
	if not is_prime(b):
		return 0
	n = 1
	while (is_prime(n * n + a * n + b)):
		n += 1
	return n

primes_under_1001 = []
for i in range(2, 1001):
	if is_prime(i):
		primes_under_1001.append(i)

max_consec_primes_count = 0
for a in range(-1000, 1001):
	for b in primes_under_1001:
		z = consec_primes_count(a, b)
		if z > max_consec_primes_count:
			max_consec_primes_count = z
			product = a * b
			# print("product = " + str(a) + " + " + str(b) + " with " + str(z) + " consecutive primes")

print(product)

