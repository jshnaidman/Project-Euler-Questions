import math

factors = {1: [1]}


def factor(n):
    n_factors = []
    if(n in factors):
        return factors.get(n)
    i = 1
    while i < math.sqrt(n):
        if n % i == 0:
            if i in factors:
                for num in factors.get(i):
                    if num not in n_factors:
                        n_factors.append(num)
            else:
                n_factors.append(i)
                n_factors.append(n / i)
        i += 1
    factors[n] = n_factors
    return n_factors


def isAbundant(num):
    numFactors = factor(num)
    total = 0
    for fac in numFactors:
        total += fac
    if total > num:
        return True
    return False

total = 0
for n in range(28123):
    if not isAbundant(n):
        total += n

print(total)
