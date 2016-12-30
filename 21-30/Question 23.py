import math


#returns factors of integer n
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

#find a numbers factors and if sum of factors > the number, it's abundant
def isAbundant(num):
    numFactors = factor(num)
    total = 1
    for fac in numFactors:
        total += fac
    if total > num:
        return True
    return False

#returns true if target is in the list
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
abundants = []
# By mathematical analysis, it can be shown that all integers
# greater than 28123 can be written as the sum of two abundant numbers.
maxNum = 28123

"""
This algorithm tries to find the sum of all numbers who cannot
be expressed as the sum of two abundant numbers

If a number n can be expressed as the sum of two abundant numbers,
A1 and A2, then n-A2 = A1.
Therefore, if n-A2 is in the list of abundant numbers, it can be
expressed as the sum of two abundant numbers

This algorithm iterates from n=0 to maxNum,
creating a list of abundant numbers

If n - num is not in the list of abundant numbers,
it is added to the total sum.

"""
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
