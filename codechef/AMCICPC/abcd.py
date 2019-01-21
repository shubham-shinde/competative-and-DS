t = int(input())
for _ in range(t):
    inp = input()
    n = len(inp)
    arr = [0 for i in range(n)]
    for x in range(n):
        if inp[x]!='.':
            k = int(inp[x])
            st,en = max(0,x-k),min(n-1,x+k)
            for i in range(st,en+1):
                arr[i] += 1
    flag = 1
    for x in arr:
        if x>1:
            flag = 2
            break
    if flag==2:
        print('unsafe')
    else:
        print('safe')