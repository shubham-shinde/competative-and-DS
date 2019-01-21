def oper1(l,r):
    global u2,l2
    flag = r+1
    while l<flag:
        u2[l],l2[r] = l2[r],u2[l]
        l += 1
        r -= 1

def oper2(r):
    global u1,l1
    l,flag = 0,r+1
    while l<flag:
        u1[l],l1[r] = l1[r],u1[l]
        l += 1
        r -= 1


def oper3(a,b,c,d):
    ans = 0
    for i in range(b-a+1):
        ans += u1[c+i]*u2[a+i]
    print(ans)


n,m = map(int,input().split())
u2 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
u1 = [1 for iii in range(n)]
l1 = [-1 for ii in range(n)]
for __ in range(m):
    cas = list(map(int,input().split()))
    if cas[0]==1:
        oper1(cas[1]-1,cas[2]-1)
    elif cas[0]==2:
        oper2(cas[1]-1)
    else:
        oper3(cas[1]-1,cas[2]-1,cas[3]-1,cas[4]-1)