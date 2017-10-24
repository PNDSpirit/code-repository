def factorial(number):
	for i in range(1, number):
		number *= i
	return number

def lattice_paths(matrix_size):
	return factorial(2 * matrix_size) // factorial(matrix_size) ** 2

print(lattice_paths(20))