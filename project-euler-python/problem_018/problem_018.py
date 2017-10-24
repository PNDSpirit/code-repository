triangle = []
line_number = 0
file = open("p018_triangle.txt", "r")
for line in file:
	triangle.append([])
	for i in range(0, len(line), 3):
		# print(str(int(line[i: i + 3])), end=',')
		triangle[line_number].append(int(line[i: i + 3]))
	line_number += 1

for i in range(14, 0, -1):
	for j in range(0, len(triangle[i - 1])):
		triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1])

print(triangle[0][0])





# for i in range(0, 15):
# 	for j in range(0, len(triangle[i])):
# 		print(triangle[i][j], end=', ')
# 	print()

