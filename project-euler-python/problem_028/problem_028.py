total = 1
number = 1
growth = 2
for i in range(0, 500):
	for j in range(0, 4):
		number += growth
		total += number
	growth += 2
print(total)