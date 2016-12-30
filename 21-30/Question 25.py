import math
from decimal import *

"""
What is the index of the first term
in the Fibonacci sequence to contain 1000 digits?

I use Binet's formula to calculate the nth Fibonacci number
This is quicker than iteratively computing numbers until the # digits > 1000

I use an algorithm that is similar to how a p controller works.
It calculates the error produced from the difference between the desired
term from what the calculated term was and adjusts the next guess of n
a proportional amount.

I'm not familliar with machine learning, but this approach can probably
be optimized with it if it can be used to pick a better constants for
the p controller.

I chose P to be 1, but it just needs to be small enough to not throw
fib(n) a negtive number and large enough to converge and be able to exit
the while loop

The error threshold could have been larger, but it would have made it slower
If it was smaller, the while loop might not converge.

Because my fib(n) function does not handle negative numbers, my
controller must be overdamped. I compensate for this by iterating and
checking for the correct value of n once the p controller has found
a sufficiently close n.
"""

# Binet's formula to calculate n th Fibonacci number
def fib(n):
    n = Decimal(n)
    rootFive = Decimal(math.sqrt(5))
    phi = Decimal((1 + rootFive)/2)
    tau = Decimal((1 - rootFive)/2)
    return (phi**n - tau**n)/rootFive

n = 1000      #This is a guess at what n will be in the solution
error = 2 # error has to just be greater than 1

while math.fabs(error) > 1: #while abs(error) > 1
    error = 999 - getcontext().log10(fib(n))
    n += int(error) #control constant of 1
    print(error)
    print(fib(n))
    print(n, '\n')

#since it undershoots, add until we find the first number with 1000 digits
while getcontext().log10(fib(n)) < 999:
    n += 1

print(fib(n))
print(n)
