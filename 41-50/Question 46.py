import math

# Finding the smallest number that disproves Goldbach's other conjecture
# Goldbach's conjecture proposed that for any odd composite number c, c = 2s + p
# where s is a square number and p is a prime number

## Project Euler Question 46

primes = [1, 2, 3, 5, 7]

#Must have all primes up to n-1 in primes for this to work
def isPrime(n):
    for prime in primes[1:]:
        if (n%prime == 0):
            return False
    primes.append(n)
    return True

# To find if Goldbach's conjecture holds for a number n,
# Start with the largest prime < n and check, starting from the smallest squares,
# if n = 2s + p until 2s + p > n. Continue with all primes until p = 1
def isGoldBach(c):
    for p in reversed(primes):
        s = 1
        S = 1
        conjecture = 2 + p
        if ( conjecture == c ):
            return True
        while (conjecture < c):
            s = s+1
            S = math.pow(s,2)
            conjecture = 2*S + p
            if ( conjecture == c ):
                return True
    return False

n = 9

while isGoldBach(n):
	#go to the next odd number
    n = n+2 
    #skip prime numbers
    while (isPrime(n)):
    	n = n+2

print(n)
