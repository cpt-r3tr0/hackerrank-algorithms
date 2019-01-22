#!/bin/python3

import math
import os
import random
import re
import sys

def insertionSort(alist, ans):
   for index in range(1,len(alist)):

     currentvalue = alist[index]
     position = index

     while position>0 and alist[position-1]>currentvalue:
         ans[0] += 1
         alist[position]=alist[position-1]
         position = position-1

     alist[position]=currentvalue

# Complete the minimumBribes function below.
def minimumBribes(q):
    ans = [0]

    # check if the queue is too chaotic
    for i, v in enumerate(q):
        if (v - 1) - i > 2:
            print('Too chaotic')
            return

    insertionSort(q, ans)
    print(ans[0])

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
