#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict
# Complete the arithmeticExpressions function below.
def arithmeticExpressions(arr):
    N = len(arr)

    # f = [defaultdict(str) for _ in range(N)]
    cache = defaultdict(str)

    cache[arr[0]] = str(arr[0])

    for i in range(1, N):
        next_step = defaultdict(str)
        cur = arr[i]
        for k, v in cache.items():
            # add
            add_ = (k + cur) % 101
            next_step[add_] = (v + "+" + str(cur))

            sub_ = (k - cur) % 101
            next_step[sub_] = (v + "-" + str(cur))

            mul_ = (k * cur) % 101
            next_step[mul_] = (v + "*" + str(cur))

            if 0 in next_step:
                output = next_step[0]
                for j in range(i+1, N):
                    output += "*"
                    output += str(arr[j])
                return output
        cache = next_step
    return cache[0]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = arithmeticExpressions(arr)

    fptr.write(result + '\n')

    fptr.close()
