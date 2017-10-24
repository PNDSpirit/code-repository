import math

def is_palindrome(string): 
	for i in range(0, math.ceil(len(string) / 2)):
		if not string[i] == string[len(string) - i - 1]:
			return 0
	return 1

total = 0
for i in range(1, 1000000):
	if is_palindrome(str(i)) and is_palindrome(str(bin(i)[2:])):
		total += i
print(total)