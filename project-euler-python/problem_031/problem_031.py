count = 0
for a in range(0, 201, 200):
	if a == 200:
		count += 1
		break;
	for b in range(0, 201, 100):
		if a + b > 200:
			break
		for c in range(0, 201, 50):
			if a + b + c > 200:
				break
			for d in range(0, 201, 20):
				if a + b + c  + d > 200:
					break
				for e in range(0, 201, 10):
					if a + b + c  + d + e > 200:
						break
					for f in range(0, 201, 5):
						if a + b + c  + d + e + f > 200:
							break
						for g in range(0, 201, 2):
							if a + b + c  + d + e + f  + g > 200:
								break
							for h in range(0, 201, 1):
								if a + b + c + d + e + f + g + h > 200:
									break;
								if a + b + c + d + e + f + g + h == 200:
									count += 1
print(count)
