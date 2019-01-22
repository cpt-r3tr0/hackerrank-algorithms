#!/bin/python3

def search(start, end, is_good):
    while start < end:
        mid = (start + end) // 2
        if is_good(mid):
            end = mid
        else:
            start = mid + 1
    return start

def compute_min(n):
    r = [0] * (n + 1)
    for i in range(2, n + 1):
        r[i] = r[i >> 1] + r[i - (i >> 1) - 1] + i - 1
    return r

mins = compute_min(10**5)
maxs = [i*(i-1)//2 for i in range(10**5 + 1)]

def solvable(n, c):
    return mins[n] <= c <= maxs[n]

def solve(l, c):
    stack = [(l, c, 1)]
    result = []
    while stack:
        n, c, offset = stack.pop()
        c -= n - 1
        if n > 1:
            mid = n // 2
            pivot = search(1, mid + 1, lambda i: maxs[i] + maxs[n-i-1] < c) - 1
            yield offset + pivot
            right = mins[n - pivot - 1]
            left = min(maxs[pivot], c - right)
            right = c - left
            stack.append((n - pivot - 1, right, pivot + offset + 1))
            stack.append((pivot, left, offset))
        elif n == 1:
            yield offset


if __name__ == '__main__':
    q = int(input())
    for _ in range(q):
        l, c = [int(x) for x in input().split()]
        if solvable(l, c):
            print(' '.join(str(x) for x in solve(l, c)))
        else:
            print('-1')
    
