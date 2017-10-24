from itertools import permutations
permutations = [''.join(p) for p in permutations('0123456789')]
permutations.sort()
print(permutations[1000000 - 1])