sum_of_squares = 0
for i in range(1, 101):
	sum_of_squares += i**2

square_of_sum = 0
for i in range(1, 101):
	square_of_sum += i
square_of_sum **= 2

print(square_of_sum - sum_of_squares)