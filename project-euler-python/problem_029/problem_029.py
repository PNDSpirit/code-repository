distinct_terms = []
for a in range(2, 101):
	for b in range(2, 101):
		number = a ** b
		if not number in distinct_terms:
			distinct_terms.append(number)

print(len(distinct_terms))