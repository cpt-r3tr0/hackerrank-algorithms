import sys

q = int(input().strip())
for Q in range(q):
    n,s,k = [int(x) for x in input().strip().split(' ')]
    stack = [((),0,0,0,0)]
    ind = 0
    store = []
    g = s // n
    h = s % n
    f = n - h
    minK = f * h
    if minK % 2 != k % 2:
        print(-1)
        continue
    if minK == k:
        print((str(g)+" ")*f+(str(g+1)+" ")*h)
        continue
    while len(stack) > 0:
        tmp1 = stack.pop(0)
        tmp2 = [(tmp1[0] + (y,),tmp1[1] + 1, tmp1[2] + y, tmp1[3] + tmp1[1] * y, tmp1[4] + sum([y*x*(tmp1[1]-a) for a,x in enumerate(tmp1[0])])) for y in range(min(n-tmp1[2],n if s == 0 else int(s // max(1,tmp1[1]))),-1,-1)]
        tmp55 = [x for x in tmp2 if x[2] == n and x[3] == s and x[4] == k]
        if len(tmp55) > 0:
            store.extend(tmp55.copy())
            break
        tmp3 = [x for x in tmp2 if x[2] < n and x[3] <= s - (x[1] * (n - x[2])) and x[4] <= k - ((s-x[3]) * x[2] - x[3] * (n - x[2]))]

        stack = tmp3 + stack
    if len(store) > 0:
        for l,m in enumerate(store[0][0]):
            print((str(l) + " ")*m, end ="")
        print()
    else:
        print(-1)
