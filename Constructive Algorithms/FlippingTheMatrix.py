#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the flippingMatrix function below.
def flippingMatrix(matrix, n):
    sumMaxes = 0
    for i in range(0,n):
      for j in range(0,n):
            sumMaxes += max([matrix[i][j], matrix[2*n-1-i][j], matrix[i][2*n-1-j], matrix[2*n-1-i][2*n-1-j]])
    return sumMaxes

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        n = int(input())

        matrix = []

        for _ in range(2*n):
            matrix.append(list(map(int, input().rstrip().split())))

        result = flippingMatrix(matrix, n)

        fptr.write(str(result) + '\n')

    fptr.close()
