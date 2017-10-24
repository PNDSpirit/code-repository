def right_triangles(perimeter):
	count = 0
	for a in range(1, perimeter // 2):
		for b in range(a, perimeter // 2):
			c = perimeter - a - b
			if c > a + b:
				continue
			if a ** 2 + b ** 2 == c ** 2:
				count += 1
	return count

max_solutions = 0
for p in range(12, 1000, 2):
	solutions = right_triangles(p)
	if solutions > max_solutions:
		max_solutions = solutions
		perimeter_with_max_solutions = p
print(perimeter_with_max_solutions)
