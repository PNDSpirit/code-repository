import re

triangle_numbers = []
for i in range(1, 50):
	triangle_numbers.append((i * (i + 1)) / 2)

file = open("p042_words.txt", "r")
pattern = re.compile('\\w+')
match = pattern.findall(file.read())

triangle_words_count = 0
for i in range(0, len(match)):
	letters_sum = 0
	for j in range(0, len(match[i])):
		letters_sum += ord(match[i][j]) - 64
	if letters_sum in triangle_numbers:
		triangle_words_count += 1
print(triangle_words_count)
