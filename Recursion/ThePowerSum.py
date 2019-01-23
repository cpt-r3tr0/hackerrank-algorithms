#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the powerSum function below.
def powerSum(X, N, current = 1):
    pw=pow(current,N)

    if(pw==X):
        return 1
    elif(pw>=X):
        return 0
    else:
        return powerSum(X,N,current+1)+powerSum(X-pw,N,current+1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    X = int(input())

    N = int(input())

    result = powerSum(X, N)

    fptr.write(str(result) + '\n')

    fptr.close()
