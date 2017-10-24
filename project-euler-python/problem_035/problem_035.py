def sieve_of_eratosthenes(limit):
	boolean_list = [True] * limit;
	for i in range(2, limit):
		if i * i > limit:
			break
		while boolean_list[i - 1] == False:
			i += 1
		for j in range(i * i, limit + 1, i):
			boolean_list[j - 1] = False
	primes = []
	for i in range(1, limit):
		if boolean_list[i] == True:
			primes.append(i + 1)
	return primes

def binary_search(target, array):
    lower = 0
    upper = len(array)
    while lower < upper:
        x = lower + (upper - lower) // 2
        val = array[x]
        if target == val:
            return 1
        elif target > val:
            if lower == x:   # this two are the actual lines
                break        # you're looking for
            lower = x
        elif target < val:
            upper = x
    return 0

def all_permutations(string):
	permutations = []
	for i in range(0, len(string)):
		permutations.append(string)
		string = string[len(string) - 1] + string[0: len(string) - 1]
	return permutations

def is_a_circular_prime(number, prime_list):
	for x in all_permutations(str(number)):
		if not binary_search(int(x), prime_list):
			return 0
	return 1

primes = sieve_of_eratosthenes(1000000)
circular_primes_count = 0
for i in primes:
	if is_a_circular_prime(i, primes):
		circular_primes_count += 1
		# print(str(i) + " is a circular prime")

print(circular_primes_count)
