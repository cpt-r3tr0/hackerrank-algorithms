def sm(n):
    return n * (n + 1) // 2

def f(n, m, s):
    if m == n - 1:
        return s
    if s == n - 1:
        return m
    if m - 1 <= sm(n - 2):
        return m + s - n + 1
    x = s - n + 2
    z = sm(n - 2)
    y = m - z
    e = z + y * x
    a = (x - 1) // (n - 1)
    k = a * sm(n - 2) - a * (n - 2) * y
    if k > 0:
        return e
    e += k
    x -= a * (n - 2)
    b = x - a - 2
    if b > 0:
        b = sm(n - 2) - sm(n - b - 2) - b * y
        if b < 0:
            e += b
    return e

for _ in range(int(input())):
    print(f(*map(int, input().split())))
