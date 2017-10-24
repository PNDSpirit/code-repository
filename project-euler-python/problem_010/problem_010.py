def sieve_of_eratosthenes(limit):
	boolean_list = [True] * limit;
	for i in range(2, limit):
		if i * i > limit:
			break
		for j in range(i * i, limit + 1, i):
			boolean_list[j - 1] = False
	primes = []
	for i in range(1, limit):
		if boolean_list[i] == True:
			primes.append(i + 1)
	return primes


primes = sieve_of_eratosthenes(2000000)
primes_sum = 0
for i in range(0, len(primes)):
	primes_sum += primes[i]
print(primes_sum)