#!/usr/bin/env python


## Project Euler question 68. 
## See https://projecteuler.net/problem=68 for more information

"""

WARNING: This code was not written to be readalble, but I comment it just so I can retrace my steps in the future when I forget what I've done

This implementation is probably more complex than it needs to be. I always try to make my project euler answers as optimal as possible. 
I use the properties of a magic 5-gon to deduce whether or not it's useful to try to assemble it, and then assemble the highest 5-gon.
It's possible however to brute force this question. It's also possible to figure this out by hand by making some useful observations:

 - 10 has to be an edge node
 - There are 5 edge nodes and 5 shared nodes
 - The largest possible leading digit is 6, since the other edge nodes would be 7,8,9,10

You can guess that if you have a form of 6XX,10XX,9XX,8XX,7XX that the next leading digit would be a 5, and
you would be right, but I don't think there's any reason that this must necessarily be the case, at least 
in any obvious way. After you assume that the form is like 65X,10XX,9XX,8XX,7XX - it's reasonable
to guess that the next digit would be a 3 so that the other trios would add up to the same number.
From there, you can follow the rules I outline in assembleFiveGon to finish the string.
Most people who claim that they solved this by hand, I think, got lucky that there actually was a 
magic 5-gon that followed that format. My implementation would efficiently solve any magic N-gon 
with some slight modifications. 


IN RETROSPECT: 

I'd probably brute force this just for readability's sake. 

"""

import collections
from datetime import *
# returns all combinations of n choose k
# eg: combinations (3,2) = [(1,2), (1,3), (2,3)]
def combinations(N,k):
	sets = []
	S = list(range(1,k+1))
	sets.append(S[:])
	getCombinations(S,N,k-1,0,sets)
	return sets


# This method finds combinations in the same way that one counts in binary
# The method is best explained with an example. The following are the combinations to 5 choose 3 (N=5, k=3)
# [1, 2, 3], [1, 2, 4], [1, 2, 5], [1, 3, 4], [1, 3, 5], [1, 4, 5], [2, 3, 4], [2, 3, 5], [2, 4, 5], [3, 4, 5]
# This can be expressed in a more general form:
# [1, 2, k], [1,2,k+1], [1,2,k+2]... until the number at the index i, S[i] > N-(k-1) + i
# When there is a carry over, the digits to the right of the number are changed like so:  [1, 4, 5] -> [2, 3, 4]
# Concretely, numbers that follow S[index] (the numbers that follow the number being incremented) are set to S[index] + 1, S[index] + 2 ... etc

def getCombinations(S, limit, i, carry, sets):
	#base case is when the lowest index cannot be incremented anymore
	if (i < 0):
		return
	elif (S[i] < limit):
		S[i] = S[i] + 1
		if(carry):
			n = 0
			for j in range(i+1,len(S)):
				n=n+1
				S[j] = S[i] + n
		sets.append(S[:])
		#if there was a carry, go back to the highest index with the correct limit for that index
		getCombinations(S,limit+carry,i+carry,0,sets)
	else:
		#if the current index is at the limit, go to the next lowest index and see if it can be incremented
		return getCombinations(S,limit-1,i-1,carry+1,sets)


# return an array that represents if each number is shared or not with another line
# eg: if number 1 is a node shared with another line, return true on index 1, if number 2 is an edge node, return false on index 2
# If a number is shared, it appears more than once in the set of combinations.
def classifyNodes(combinations):
	isShared = [False]*(len(combinations) + 1) # +1 so that number and index matches
	count = collections.Counter()
	# get count of occurences of each number n in the combinations
	for combination in combinations:
		count.update(combination)
	for n in count:
		if(count[n] > 1):
			isShared[int(n)] = True
	return isShared

#returns the largest 16 bit string 5 gon based on shared nodes and the edge nodes
#preFiveGon is a length 3 tuple (combinations, shared nodes, edge nodes)
def assembleFiveGon(preFiveGon,firstTrio):
	# the plan is to follow the rules of magic five gons to infer the rest of the string based on the first trio
	# A magic 5gon is made of 5 trios
	# Each trio can start with any edge, so we order the edges to create the largest FiveGon possible
	# The second character in a trio must be the first character of the previous trio
	# The third character in a trio must be the remaining character

	# 15 because each will be the actual number
	fiveGon = [0]*15
	for num in range(3):
		fiveGon[num] = int(firstTrio[num])
	count = collections.Counter()
	for subset in preFiveGon:
		count.update(subset)
	edges = []
	shared = []
	for key in count:
		if (count[key] == 1 and key != fiveGon[0]):
			edges.append(key)
		elif (key != fiveGon[1] and key != fiveGon[2]):
			shared.append(key)

	edges.sort(reverse=True)
	for i in range(1,5):
		fiveGon[3*i] = edges[i-1]
		fiveGon[3*i + 1] = fiveGon[3*i -1]
		for group in preFiveGon:
			if (fiveGon[3*i] in group):
				for e in group:
					if (e != fiveGon[3*i] and e != fiveGon[3*i + 1]):
						fiveGon[3*i + 2] = e
	assembledFiveGon = ''
	for n in fiveGon:
		assembledFiveGon = assembledFiveGon + str(n)
	return assembledFiveGon


def main():
	#get all the combinations of numbers that sum to each total
	trios = combinations(10,3)
	sums = {}
	for trio in trios:
		total = sum(trio)
		if (total not in sums):
			sums[total] = []
		sums[total].append(tuple(trio))

	#Generate largest 5gon for each Total
	largestFiveGon = '0'
	for total in sums:
		#totalSet is a set of combinations that add up to total
		totalSet = sums[total]
		N = len(totalSet)
		if(N < 5):
			continue

		#Use the combinations returned as pointers to the different lines/trios 
		NcFive = combinations(N,5)
		preFiveGonTuples = []
		for combination in NcFive:
			preFiveGon = []
			for element in combination:
				preFiveGon.append(totalSet[element-1])
			#in a magic 5gon, 5 egdes will not repeat, and 5 will be shared twice.
			#must have 5 numbers with a count of 2, and 5 numbers with a count of 1
			count = collections.Counter()
			for subset in preFiveGon:
				count.update(subset)
			#if 10 occurs more than once, it will not form a 16 bit string
			if(count[10] > 1):
				break
			shared = []
			edges = []
			for num in count:
				if (count[num] == 1):
					edges.append(num)
				elif (count[num] == 2):
					shared.append(num)
				else:
					break
			if (len(shared) == 5 and len(edges) == 5):
				#sort so that we can easily find the highest shared nodes and the smallest edge node 
				#each solution is described by the smallest edge node followed by two shared nodes 5 times repeated
				#the first node must be the smallest but the shared nodes must be as large as possible to find the maximum 16 digit string
				preFiveGonTuples.append((preFiveGon,sorted(edges)))
		#sort the preFiveGons according to which has the largest minimum edge
		preFiveGonTuples = sorted(preFiveGonTuples, key=lambda x:x[1][0], reverse=True)
		largeMinEdgePreFiveGonTuples = []
		if (not preFiveGonTuples):
			continue
		i=0
		#create a list of the largest potential 5 gons by selecting those that contain the largest minimum edge
		while (preFiveGonTuples[i][1][0] == preFiveGonTuples[0][1][0]):
			largeMinEdgePreFiveGonTuples.append(preFiveGonTuples[i])
			i = i+1
			if (len(preFiveGonTuples)==i):
				break
		largestPreFiveGons = []
		largest = 0
		#get the preFiveGons with the largest first 3 chars
		for preFiveGonTuple in largeMinEdgePreFiveGonTuples:
			firstTrio = None
			#get the trio with the smallest edge in it
			for trio in preFiveGonTuple[0]:
				#They all have the same minimum edge
				if (preFiveGonTuple[1][0] in trio):
					edge = preFiveGonTuple[1][0]
					shared = []
					for num in trio:
						if (num != preFiveGonTuple[1][0]):
							shared.append(num)
					#the string returned as firstTrio is the highest combination of this trio
					shared = sorted(shared,reverse=True)
					firstTrio = str(edge) + str(shared[0]) + str(shared[1])
			if(int(firstTrio) > int(largest)):
				largestPreFiveGons = [(preFiveGonTuple[0],firstTrio)]
				largest = firstTrio
			elif (int(firstTrio) == int(largest)):
				largestPreFiveGons.append((preFiveGonTuple[0],firstTrio))
		for preFiveGonTuple in largestPreFiveGons:
			fiveGon = assembleFiveGon(preFiveGonTuple[0], preFiveGonTuple[1])
			if (fiveGon > largestFiveGon):
				largestFiveGon = fiveGon

	print(largestFiveGon)


if __name__ == "__main__":
    start = datetime.now()
    main()
    end=datetime.now()
    time = (end-start).total_seconds()
    print("\nelapsed_time:", time, "seconds")