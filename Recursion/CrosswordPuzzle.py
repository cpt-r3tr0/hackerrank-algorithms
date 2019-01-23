def printy(cross, forma):

    for a in range(10):
        for b in range(10):
            if(cross[a][b]=="+"):
                print(forma,end="")
            else:
                print(cross[a][b], end="")
        print()


def horizontal(cross, l, i, j):
    ans=[]
    alr=""
    for x in range(j-1, -1, -1):
        if(cross[i][x]=="+" or cross[i][x]=="-"):
            break
        else:
            alr=cross[i][x]+alr
   # print("####################", alr,l)
    for st in l:
        c=0
        f=0
        for y in alr:

            if(y==st[c]):

                c=c+1

            else:
                break
        else:


            for x in range(j, 10):
                #print(st,c, st[c], cross[i][x])

                if(c==len(st)):
                    if(x<9 and cross[i][x]!="+"):
                        f=1
                    break
                if(cross[i][x]=="+"):
                    if(c!=len(st)):
                        f=1
                        break
                if(cross[i][x]=="-" or cross[i][x]==st[c]):
                    c=c+1

                else:
                    f=1
                    break
            if(f==0 and c==len(st)):
                ans.append(st)
    ans.append(len(alr))

    return ans


def vertical(cross, l, i, j):
    alr=""
    for x in range(i-1, -1, -1):
        if(cross[x][j]=="+" or cross[x][j]=="-"):
            break
        alr=cross[x][j]+alr
    ans=[]
    for st in l:
        c=0
        f=0
        for y in alr:
            if(y==st[c]):
                c=c+1
            else:
                break
        else:

            for x in range(i, 10):
                if(c==len(st)):
                    if(x<9 and cross[x][j]!="+"):
                        f=1
                    break
                if(cross[x][j]=="+"):
                    if(c!=len(st)):
                        f=1
                        break
                if(cross[x][j]=="-" or cross[x][j]==st[c]):
                    c=c+1
                else:
                    f=1
                    break
            if(f==0 and c==len(st)):
                ans.append(st)
    ans.append(len(alr))
  #  print(ans)
    return ans


def soln(cross, l, i, j ):
  #  printy(cross,l,i,j)
    if(len(l)==0):
        printy(cross, forma)
        return True
    if(j==10):
        return soln(cross, l, i+1, 0)

    if(i==10):
        return False

    if(cross[i][j]!="+" and cross[i][j]!="-"):

        return soln(cross,l, i, j+1)
    if(cross[i][j]=="+"):
        return soln(cross, l, i, j+1)
    if(cross[i][j]!="+"):

        aa=horizontal(cross, l, i, j)
        bb=vertical(cross, l, i, j)
        lh=aa.pop()
        lv=bb.pop()
        if(cross[i][j]=="-" and len(aa)==0 and len(bb)==0):
            return False
        if(len(aa)!=0):

            for a in aa:
                cx=0
                lol=a
                a=a[lh:]
                bt=cross[i][j:j+len(a)]
                for ff in range(j, j+len(a)):
                    cross[i][ff]=a[cx]
                    cx=cx+1
                del l[l.index(lol)]
                if(soln(cross, l, i, j+1)):
                    return True
                cx=0
                for ff in range(j, j+len(a)):
                    cross[i][ff]=bt[cx]
                    cx=cx+1
                l.append(lol)

        if(len(bb)!=0):
            for b in bb:
                lol=b
                b=b[lv:]
                cx=0
                bt=""
                for ff in range(i, i+len(b)):
                    bt=bt+cross[ff][j]
                    cross[ff][j]=b[cx]
                    cx=cx+1
                del l[l.index(lol)]
                if(soln(cross, l, i, j+1)):
                    return True
                cx=0
                for ff in range(i, i+len(b)):
                    cross[ff][j]=bt[cx]
                    cx=cx+1
                l.append(lol)


        return False

#

cross=["" for j in range(10)]
for a in range(10):
    cross[a]=list(input())
forma="+"
for a in range(10):
    for b in range(10):
        if(cross[a][b]=="X"):
            cross[a][b]="+"
            forma="X"
l=input().split(";")
soln(cross, l, 0, 0)
