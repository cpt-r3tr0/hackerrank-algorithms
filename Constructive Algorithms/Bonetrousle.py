#!/bin/python3

import os
import sys

#
# Complete the bonetrousle function below.
#
def bonetrousle(n, k, b):
    #
    # Write your code here.
    #
    if n > (k*(k+1)/2) or n < (b*(b+1)/2):
        return [-1]
    elif b == 1:
        if k >= n:
            return [n]
        else:
            return [-1]
    factor = int(n/b)
    half_b = int(b/2)
    result = [0] * b
    if b % 2 != 0:
        result[half_b] = factor
        for i in range(1, half_b+1):
            result[half_b - i] = factor - i
            result[half_b + i] = factor + i
    else:
        result[half_b] = factor + 1
        result[half_b - 1] = factor
        for i in range(1, half_b):
            result[half_b - 1 - i] = factor - i
            result[half_b + i] = factor + 1 + i
    sum = 0
    for i in result:
        sum += i
        if i > k or i < 1:
            return [-1]
    if sum < n:
        diff = n - sum
        replace = result[b - 1] + 1
        if replace > k:
            return [-1]
        for i in range(b):
            if result[i] == replace - diff:
                result[i] = replace
                break
    if sum > n:
        diff = sum - n
        replace = result[0] - 1
        if replace < 1:
            return [-1]
        for i in range(b):
            if result[i] == replace + diff:
                result[i] = replace
                break
    return result
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nkb = input().split()

        n = int(nkb[0])

        k = int(nkb[1])

        b = int(nkb[2])

        result = bonetrousle(n, k, b)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
