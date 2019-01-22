#!/bin/python3

import math
import os
import random
import re
import sys

def choose(n, r):
    return n * (n-1) * (n-2) // (r * (r-1) * (r-2))
def product(xs):
    y = 1
    for x in xs:
        y *= x
    return y
def generate_primes(n):
    p = [True] * (n + 1)
    p[0] = False
    p[1] = False
    for i in range(n+1):
        if p[i]:
            yield i
            for j in range(2*i,n+1,i):
                p[j] = False
primes = list(generate_primes(5000))
def factorize(n):
    qs = []
    for p in primes:
        if p*p > n:
            break
        while n % p == 0:
            qs.append(p)
            n //= p
    if n != 1:
        qs.append(n)
    return qs
def core_size(q):
    return ((q - 1) // 2) * 3
def select_factors(p, q, width, memo):
    if p in memo:
        return memo[p]
    qs = [p, 1, 1]
    qv = core_size(q) + sum(qs)
    for i in range(min(width, p)):
        ps = [1, 1, 1]
        for r in factorize(p - i):
            ps[ps.index(min(ps))] *= r
        pv = core_size(q) + sum(ps)
        if i:
            nps, npv = select_factors(p - product(ps), q, width=width, memo=memo)
            pv += npv
        if pv < qv:
            qs = ps
            qv = pv
    memo[p] = (tuple(qs), qv)
    return memo[p]
def make_core(v, e, q):
    if q % 2 == 1:
        xs, v = [v, v+1, v+2], v+3
        for i in range(3):
            e.append((xs[i], xs[(i+1)%3]))
    else:
        xs, v = [v, v, v], v+1
    for i in range(3):
        for j in range(q//2 - 1):
            e.append((xs[i], v))
            xs[i] = v
            v += 1
    return xs, v
def make_triplets(v, e, q, ps):
    xs, v = make_core(v, e, q)
    for i in range(3):
        for _ in range(ps[i]):
            e.append((xs[i], v))
            v += 1
    return v
def make_coalesced_core(v, e, l):
    for i in range(l):
        e.append((v, v + i+1))
    v += l+1
    return v


if __name__ == '__main__':
    PQ = input().split()

    p = int(PQ[0])

    q = int(PQ[1])
    v = 0
    e = []
    if q == 2:
        while p:
            l = 3
            while choose(l+1,3) <= p:
                l += 1
            p -= choose(l,3)
            v = make_coalesced_core(v, e, l)
    else:
        while p:
            ps, _ = select_factors(p, q, width=500, memo={})
            v = make_triplets(v, e, q, ps)
            p -= product(ps)
    print(v, len(e))
    assert v <= 100
    for a, b in e:
        print(a+1, b+1)
        
