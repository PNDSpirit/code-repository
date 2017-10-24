def is_pythagorean_triplet(a, b, c):
	if a * a + b * b == c * c:
		return 1
	return 0

def find_the_triplet():
	for a in range(1, 1000):
		for b in range(1, 1000 - a):
			c = 1000 - a - b
			if is_pythagorean_triplet(a, b, c):
				print(a * b * c)
				return 0

find_the_triplet()

