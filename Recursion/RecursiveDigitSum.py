def digSum(n):
    result = 0
    for x in n:
        result += int(x)
    return result % 9

n, k = tuple(input().strip().split(" "))
if n == "0":
    print(0)
else:
    if digSum(n) * int(k) % 9 == 0:
        print(9)
    else:
        print(digSum(n) * int(k) % 9)
