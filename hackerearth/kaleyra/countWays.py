
def fun(N):
    ll = [i for i in range(1, N+1)]
    c = 0
    for j in ll:
        for z in ll :
            ijc = 0
            for i in ll:
                for k in ll:
                    for x in ll:
                        for y in ll :
                            # if i==j==k==x==y==z:
                            #     continue
                            if i==x and j==z and k==y:
                                continue
                            if (i+2*j+k)%(x+y+2*z) is 0:
                                print(i, k, j)
                                print(x, y, z)
                                print()
                                ijc = ijc+1
                                c = c + 1
            # print("ijc", j, z, ijc)
    return c

print(fun(3))