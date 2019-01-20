#!/bin/python3

import os
import sys
import collections

def ford_fulkerson(graph, source, sink):
    residuals = {}
    flow = {}
    new_graph = {u: dict() for u in graph}
    for u in graph:
        for v in graph[u]:
            new_graph.setdefault(v, dict())
            new_graph[v].setdefault(u, 0)
            new_graph[u][v] = graph[u][v]

    graph = new_graph

    # Build the residual graph.
    for u, children in graph.items():
        u_residuals = {}
        u_flow = {}
        for v, cap in children.items():
            u_residuals[v] = cap
            u_flow[v] = 0
        residuals[u] = u_residuals
        flow[u] = u_flow

    while True:
        queue = collections.deque([source])
        prev = {source: None}
        found = False

        # Run BFS on the residual graph.
        while queue:
            top = queue.popleft()
            if top == sink:
                found = True
                break
            for child in graph[top]:
                if not residuals[top][child]:
                    continue
                if child in prev:
                    continue
                prev[child] = top
                queue.append(child)

        if not found:
            break

        # Reconstruct path.
        path = []
        node = sink
        while node is not None:
            path.append(node)
            node = prev[node]
        path = list(reversed(path))

        # Augment flows and residuals.
        min_residual = min(residuals[u][v] for u, v in zip(path, path[1:]))
        for u, v in zip(path, path[1:]):
            flow[u][v] += min_residual
            flow[v][u] = -flow[u][v]
            residuals[u][v] = graph[u][v] - flow[u][v]
            residuals[v][u] = graph[v][u] - flow[v][u]

    return sum(flow[source].values())


#
# Complete the crabGraphs function below.
#
def crabGraphs(n, t, graph):
    #
    # Write your code here.
    #
    graphs = {(i, 0): dict() for i in range(1, 1 + n)}
    for i in range(1, 1 + n):
        graphs[i, 1] = dict()

    for u, v in graph:
        graphs[u, 0][v, 1] = 1
        graphs[v, 0][u, 1] = 1

    graphs["source"] = {(i, 0): 1 for i in range(1, 1 + n)}
    graphs["sink"] = {}

    for i in range(1, 1 + n):
        graphs[i, 1]["sink"] = t

    return ford_fulkerson(graphs, "source", "sink")

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    c = int(input())

    for c_itr in range(c):
        ntm = input().split()

        n = int(ntm[0])

        t = int(ntm[1])

        m = int(ntm[2])

        graph = []

        for _ in range(m):
            graph.append(list(map(int, input().rstrip().split())))

        result = crabGraphs(n, t, graph)

        fptr.write(str(result) + '\n')

    fptr.close()
