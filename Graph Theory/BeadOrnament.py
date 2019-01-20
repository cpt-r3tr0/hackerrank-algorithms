#!/bin/python3

import os
import sys

#
# Complete the beadOrnaments function below.
#

def beadOrnaments(b, b_count):
    #
    # Write your code here.
    #
    ans = 1
    for c in b:
        ans*=c**(c-1)
    ans *= sum(b)**(b_count-2)
    return int(ans)%1000000007

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        b_count = int(input())

        b = list(map(int, input().rstrip().split()))

        result = beadOrnaments(b,b_count)

        fptr.write(str(result) + '\n')

    fptr.close()
