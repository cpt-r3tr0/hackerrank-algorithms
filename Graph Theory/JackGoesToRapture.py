#!/bin/python3

import math
import os
import random
import re
from heapq import *
import sys

#
# Complete the 'getCost' function below.
#
# The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
#

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
#
#

def getCost(g_nodes, g_from, g_to, g_weight):
    # Print your answer within the function and return nothing
    adj = [[] for _ in range(g_nodes + 2)]
    inf =float('+inf')
    cost = [inf for _ in range(g_nodes + 2)]
    for i in range(len(g_from)):
        f, t, w = g_from[i], g_to[i], g_weight[i]
        adj[f].append((t, w))
        adj[t].append((f, w))
    q = [(0, 1)]
    V = set()
    while q:
        cum, s = heappop(q)
        if s in V:
            continue
        V.add(s)
        cost[s] = cum
        for t, w in adj[s]:
            sup = cum + max(0, w - cum)
            if cost[t] > sup:
                heappush(q, ((sup, t)))
    print(cost[g_nodes] if cost[g_nodes] != inf else 'NO PATH EXISTS')

if __name__ == '__main__':
    g_nodes, g_edges = map(int, input().rstrip().split())

    g_from = [0] * g_edges
    g_to = [0] * g_edges
    g_weight = [0] * g_edges

    for i in range(g_edges):
        g_from[i], g_to[i], g_weight[i] = map(int, input().rstrip().split())

    getCost(g_nodes, g_from, g_to, g_weight)
