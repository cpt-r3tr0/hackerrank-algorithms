#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jimOrders function below.
l=[]
n=int(input())

for _ in range(n):
    a,b=map(int,input().split())
    l.append(a+b)

gen=((i+1,l[i]) for i in range(n))
md=dict(gen)
s=[k for k in sorted(md,key=md.get)]
for i in range(n):
    print(s[i],end=" ")
