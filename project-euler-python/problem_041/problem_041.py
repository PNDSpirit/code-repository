def is_pandigital(string):
	for i in range(1, len(string) + 1):
		if str(i) not in string:
			return 0
	return 1

def sieve_of_sundaram(limit):
	new_limit = limit // 2 - 1
	boolean_list = [True] * new_limit;
	i = 1
	j = i
	while (i + j + 2 * i * j < new_limit):
		while (i + j + 2 * i * j <= new_limit):
			boolean_list[2 * i * j + i + j - 1] = False
			j += 1
		i += 1
		j = i
	primes = [2]
	for i in range(0, new_limit):
		if boolean_list[i]:
			primes.append(i * 2 + 3)
	return primes


primes = sieve_of_sundaram(7654321)
for i in range(len(primes) - 1, -1, -1):
	if is_pandigital(str(primes[i])):
		print(primes[i])
		break;