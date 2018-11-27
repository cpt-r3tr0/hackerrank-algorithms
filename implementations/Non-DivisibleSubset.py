def main():
    n, k = [int(fld) for fld in input().split()]
    a = [int(fld) for fld in input().split()]
    assert n == len(a)
    modclass = [0] * k
    for elt in a:
        modclass[elt % k] += 1
    ans = sum(max(modclass[i], modclass[k-i]) for i in range(1, (k+1)//2))
    if modclass[0] != 0:
        ans += 1
    if k % 2 == 0 and modclass[k//2] != 0:
        ans += 1
    print(ans)

main()
