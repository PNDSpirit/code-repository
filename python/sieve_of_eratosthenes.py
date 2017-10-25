import time
time_beginning = time.time()

def sieve_of_eratosthenes(limit):
	boolean_list = [True] * limit;
	i = 2
	while (i < limit):
		if i * i > limit:
			break
		while not boolean_list[i - 1]:
			i += 1
		for j in range(i * i, limit + 1, i):
			boolean_list[j - 1] = False
		i += 1
	primes = []
	for i in range(1, limit):
		if boolean_list[i]:
			primes.append(i + 1)
	return primes



primes = sieve_of_eratosthenes(20000000)
# print(primes)
print(len(primes))
print(str(time.time() - time_beginning))