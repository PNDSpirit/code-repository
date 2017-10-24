def divisors_sum(number):
	total = 1
	i = 2
	while (i * i <= number):
		if number % i == 0:
			total += i
			if not (number // i) == i:
				total += number // i
		i += 1
	return total

# if number can be expressed by the sum of two numbers in the sorted list
def search_for_sum(number, numbers_list):
	number1_index = 0
	number2_index = len(numbers_list) - 1
	while number1_index <= number2_index:
		if numbers_list[number1_index] + numbers_list[number2_index] < number:
			number1_index += 1
		elif numbers_list[number1_index] + numbers_list[number2_index] > number:
			number2_index -= 1
		elif numbers_list[number1_index] + numbers_list[number2_index] == number:
			return 1
	return 0

abundant_numbers = []
for i in range(1, 28124):
	if divisors_sum(i) > i:
		abundant_numbers.append(i)

total = 0

for i in range(1, 28124):
	if not search_for_sum(i, abundant_numbers):
		total += i

print(total)