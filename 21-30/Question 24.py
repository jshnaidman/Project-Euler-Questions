def factorial(n):
    if n == 0:
        return 1
    return n*factorial (n-1)


permutations = 1e6
permutation = []
numbers = [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
n = len(numbers)

"""
What is the millionth lexicographic permutation of the digits
0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Well n digits have n! permutations. Since lexicographic permutations
are ordered, we know that the 0 digit in the first position holds the first
9! permutations, the 1 digit in the first position holds the first 2*9!
permutations, the 2 digit in the first position holds the first 3*9!
permutations and so on and so on.

We therefore need the nth digit i to hold the condition i*(n-1)! < 1e6
while being the largest digit possible so that we can reduce the space
of possible permutations by as much as possible. This can actually
be solved

"""
while n>0:
    fact = factorial(n-1)
    i=0
    temp = 0
    while (temp < permutations):
        temp += fact
        i += 1
    temp -= fact
    i -= 1
    permutations -= temp
    permutation.append(numbers[i])
    del numbers[i]
    n -= 1;
assert (permutations==1) # should have 0! permutations at the end

print permutation
