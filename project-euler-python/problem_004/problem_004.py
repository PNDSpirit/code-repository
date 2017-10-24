largest_palindrome = 0
current_number = 0
for i in range(100, 1000):
	for j in range(100, 1000):
		current_number = i * j
		if (str(current_number) == str(current_number)[::-1]):
			if (largest_palindrome < current_number):
				largest_palindrome = current_number
print(largest_palindrome)
