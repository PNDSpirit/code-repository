import math

def is_pandigital(string):
	if len(string) != 9:
		return 0
	for i in range(1, 10):
		if str(i) not in string:
			return 0
	return 1

def generate_product(seed):
	result = str(seed)
	i = 2
	while len(result) < 9:
		result += str(seed * i)
		i += 1
	return result

max_result = 0
limit = 100001
for i in range(1, limit):
	result = generate_product(i)
	if (is_pandigital(result)):
		if int(result) > max_result:
			max_result = int(result)

print(max_result)