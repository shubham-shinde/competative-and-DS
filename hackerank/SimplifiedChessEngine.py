#!/bin/python3

import os
import sys

SS = 4;

def whoseTurn(turn, x, y):
    switcher = {
        'N':[[x+2,y+1], [x+2,y-1], [x+1,y+2], [x-1,y+2], 
            [x-2,y-1], [x-2,y+1], [x+1,y-2], [x-1,y-2]],
        'Q':[[x+1,y+1], [x-1,y+1], [x+1,y-1], [x-1,y-1], 
            [x,y-1], [x,y+1], [x+1,y], [x-1,y]],
        'B':[[x+1,y+1], [x+2,y+2], [x+3,y+3], 
            [x-1,y+1], [x-2,y+2], [x-2,y+2], 
            [x+1,y-1], [x+2,y-2], [x+2,y-2], 
            [x-1,y-1], [x-2,y-2], [x-2,y-2]],
        'R':[[x+1,y], [x+2,y], [x+3,y], 
            [x,y+1], [x,y+2], [x,y+3], 
            [x,y-1], [x,y-2], [x,y-3], 
            [x-1,y], [x-2,y], [x-3,y]]
    }
    return switcher[turn]

def printBoard(board):
    for i in board:
        for j in i:
            if j[0]=='@':
                print(' ', end='')
            else:
                print(j[0], end='')
            print(j[1], end=' ')
        print()
    print()

def blackTurn(board, white, black, w):
    if w==0:
        return False    
    for b_in,j in enumerate(black):
        turnOf = j[0]
        x = j[1]
        y = j[2]
        turn = whoseTurn(turnOf, x, y)
        for i in turn:
            if(0<=i[0]<SS and 0<=i[1]<SS):
                temp = board[i[0]][i[1]]
                if (temp[0] == '@' or temp[1]==1) and temp[0] != 'Q':
                    board[x][y] = ['@', 0]
                    board[i[0]][i[1]] = [turnOf, 0]
                    # print(white)
                    if temp[0]!='@':
                        index = white.index([temp[0],i[0], i[1]])
                        white.remove([temp[0], i[0], i[1]])
                    black[b_in] = [turnOf, i[0], i[1]]
                    printBoard(board)
                    re = whiteTurn(board, white, black, w-1)
                    if re == True:
                        print(turnOf,i[0],i[1])
                        return True
                    black[b_in] = [turnOf, x, y]
                    if temp[0]!='@':
                        white.insert(index, [temp[0], i[0], i[1]])
                    board[i[0]][i[1]] = temp
                    board[x][y] = [turnOf, 0]
    return False

def whiteTurn(board, white, black, w):
    if w==0:
        return False
    for w_in,j in enumerate(white):
        turnOf = j[0]
        x = j[1]
        y = j[2]
        turn = whoseTurn(turnOf, x, y)
        for i in turn:
            if (0<=i[0]<SS and 0<=i[1]<SS):
                temp = board[i[0]][i[1]]
                if temp[0] == 'Q' and temp[1] == 0:
                    return True
                if temp[1] != 1:
                    board[x][y] = ['@', 0]
                    board[i[0]][i[1]] = [turnOf, 1]
                    if temp[0]!='@':
                        index = black.index([temp[0], i[0], i[1]])
                        black.remove([temp[0], i[0], i[1]])
                    white[w_in] = [turnOf, i[0], i[1]]
                    printBoard(board)
                    re = blackTurn(board, white, black, w-1)
                    if re == True:
                        print(turnOf, i[0],i[1])
                        return True
                    white[w_in] = [turnOf, x, y]                
                    if temp[0]!='@':
                        black.insert(index, [temp[0], i[0], i[1]])
                    board[i[0]][i[1]] = temp
                    board[x][y] = [turnOf, 1]
    return False


def simplifiedChessEngine(whites, blacks, moves):
    for i in whites+blacks:
        i[2] = int(i[2]) - 1
        i[1] = ord(i[1]) - 65
    board =[[['@', 0], ['@', 0], ['@', 0], ['@', 0]],
            [['@', 0], ['@', 0], ['@', 0], ['@', 0]],
            [['@', 0], ['@', 0], ['@', 0], ['@', 0]],
            [['@', 0], ['@', 0], ['@', 0], ['@', 0]]]

    for i in whites:
        board[i[1]][i[2]] = [i[0], 1] 
    for i in blacks:
        board[i[1]][i[2]] = [i[0], 0]
    printBoard(board)
    if whiteTurn(board, whites, blacks, moves):
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':

    g = int(input())

    for g_itr in range(g):
        wbm = input().split()

        w = int(wbm[0])

        b = int(wbm[1])

        m = int(wbm[2])

        whites = []

        for _ in range(w):
            whites.append(list(map(lambda x: x[0], input().rstrip().split())))

        blacks = []

        for _ in range(b):
            blacks.append(list(map(lambda x: x[0], input().rstrip().split())))

        simplifiedChessEngine(whites, blacks, m)
