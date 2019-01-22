# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
a = (2*n)//3+1
b = (n+2)//3-1
c = (2*n+2)//3
print(a)
for i in range(0,a,2):
    print(i,c-i//2,n-c-i//2)
for i in range(1,a,2):
    print(i,b-i//2,n-1-b-i//2)
