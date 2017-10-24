def is_pandigital(string):
	for i in range(1, len(string) + 1):
		if str(i) not in string:
			return 0
	return 1

total = 0
list_of_multiplies = []
for i in range(2, 100):
	if i < 9:
		j_lower_bound = 1234
	else:
		j_lower_bound = 123
	for j in range(j_lower_bound, 10000 // i + 1):
		string = str(i * j) + str(i) + str(j)
		if len(string) == 9 and is_pandigital(string):
			if i * j not in list_of_multiplies:
				total += i * j
				list_of_multiplies.append(i * j)
print(total)
