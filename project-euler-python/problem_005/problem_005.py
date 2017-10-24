import math

def is_prime(number):
	if number < 2:
		return 0
	x = 2
	while number >= x * x:
		if number % x == 0:
			return 0
		x += 1
	return 1

limit = 20
primes = []
for i in range(0, limit + 1):
	if is_prime(i):
		primes.append(i)

result = 1
for prime in primes:
	result *= prime**math.floor(math.log(limit, prime))

print(int(result))