import time
import math
import sys
time_beginning = time.time()
def sieve_of_sundaram(limit):
	new_limit = (limit - 1) // 2
	boolean_list = [True] * new_limit;
	for i in range(1, int((math.sqrt(2 * limit + 1) - 1) / 2) + 1):
		start = 2 * i + 2 * i * i
		for j in range(start, new_limit + 1, 2 * i + 1):
			boolean_list[j - 1] = False
			j += 1
	primes = [2]
	for i in range(0, new_limit):
		if boolean_list[i]:
			primes.append(i * 2 + 3)
	return primes

primes = sieve_of_sundaram(int(sys.argv[1]))
print(len(primes))
time_taken = time.time() - time_beginning
print(str(time_taken))


# in the first for loop at line 10, the upper boundary for the range is derived
# by solving for 2 * x ** 2 + 2 * x < limit - > x is limited by
# (sqrt(2 * limit + 1) - 1) / 2
# the second loop is a direct transformation