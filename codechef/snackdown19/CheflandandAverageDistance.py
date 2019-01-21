import os
import sys

def printList(L):
    for i in L:
        for j in i:
            print(j, end=" ")
        print('\n')
    print()

def makeAllArray(N, M):
    for k in range(N):
        for g in range(M):
            x = k+1
            y = g+1
            L = []
            for i in range(N):
                s = []
                for j in range(M):
                    s.append(abs(x-(i+1))+abs(y-(j+1)))
                L.append(s)
            printList(L)
            print()

if __name__ == '__main__':

    g = int(input())

    for g_itr in range(g):
        wbm = input().split()

        w = int(wbm[0])

        b = int(wbm[1])

        # whites = []

        # for _ in range(w):
        #     whites.append(list(map(lambda x: x[0], input().rstrip().split())))

        # blacks = []

        # for _ in range(b):
        #     blacks.append(list(map(lambda x: x[0], input().rstrip().split())))

        makeAllArray(w, b)
