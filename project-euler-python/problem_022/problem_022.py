import re
file = open("p022_names.txt", "r")
pattern = re.compile('\\w+')
match = pattern.findall(file.read())
match.sort()
char_sum = 0
total_sum = 0
for i in range(0, len(match)):
	for j in range(0, len(match[i])):
		char_sum += ord(match[i][j]) - 64
	total_sum += char_sum * (i + 1)
	char_sum = 0
print(total_sum)