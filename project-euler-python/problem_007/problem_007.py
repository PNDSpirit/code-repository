def is_prime(number, primes):
	for prime in primes:
		if number % prime == 0:
			return 0
	return 1

prime_count = 0
i = 1
primes = []
while prime_count < 10001:
	i += 1
	if is_prime(i, primes):
		prime_count += 1
		primes.append(i)

print(primes[10000])
