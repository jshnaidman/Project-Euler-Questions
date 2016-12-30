import math

abundants = []
maxNum = 28123

def factor(n):
    i = 2
    n_factors = []
    while i <= math.sqrt(n):
        if n % i == 0:
            n_factors.append(i)
            c = n/i
            if c != i:
                n_factors.append(c)
        i += 1
    return n_factors


def isAbundant(num):
    numFactors = factor(num)
    total = 1
    for fac in numFactors:
        total += fac
    if total > num:
        return True
    return False

def binarySearch(target,num_list):
    low = 0
    high = len(num_list) -1
    while (low <= high):
        mid = low + (high-low)/2
        if (num_list[mid] == target):
            return True
        elif target < num_list[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return False


n=0
total=0
while n <= maxNum:
    found = False
    for num in abundants:
        if binarySearch(n-num,abundants):
            found = True
            break
    if not found:
        total += n

    if isAbundant(n):
        abundants.append(n)
    n += 1

print total
