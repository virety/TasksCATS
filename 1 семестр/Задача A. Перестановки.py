from itertools import permutations
n = int(input())
numbers = list(range(1, n+1))
permutations_list = list(permutations(numbers))
for permutation in permutations_list:
    print(*permutation)