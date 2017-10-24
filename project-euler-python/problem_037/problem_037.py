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

def is_prime(number, prime_list):
	if number in prime_list:
		return 1
	return 0

def is_trancutable_prime(number, prime_list):
	number_string = str(number)
	for i in range(1, len(number_string)):
		if not is_prime(int(number_string[i:len(number_string)]), prime_list):
			# print(number_string[i:4] + "is not a prime")
			return 0
		if not is_prime(int(number_string[0:i]), prime_list):
			# print(number_string[0:i] + "is not a prime")
			return 0
	if not is_prime(number, prime_list):
		return 0
	return 1



prime_list = sieve_of_sundaram(1000000)
trancutable_primes_count = 0
trancutable_primes_sum = 0
i = 10
while trancutable_primes_count < 11:
	while not is_prime(int(str(i)[0:len(str(i)) - 1]), prime_list):
		while len(str(i)) > 2 and not is_prime(int(str(i)[0:len(str(i)) - 2]), prime_list):
			while len(str(i)) > 3 and not is_prime(int(str(i)[0:len(str(i)) - 3]), prime_list):
				while len(str(i)) > 4 and not is_prime(int(str(i)[0:len(str(i)) - 4]), prime_list):
					i += 10000
				i += 1000
			i += 100
		i += 10


	if is_trancutable_prime(i, prime_list):
		trancutable_primes_sum += i
		trancutable_primes_count += 1
		# print(i)
	i += 1
print(trancutable_primes_sum)