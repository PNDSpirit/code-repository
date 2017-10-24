number = 600851475143
factor = 2
while number > 1:
		if number % factor == 0:
			number /= factor
			factor -= 1
		factor += 1
print(factor)