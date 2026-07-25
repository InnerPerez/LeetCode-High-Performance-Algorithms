# -*- coding: utf-8 -*-
"""
Created on Wed Jun 24 23:28:38 2026

@author: blzsm
"""

from collections import deque

def cerca_0(board):
    for i in range(6):
        if board[i] == "0":
            return i
        
        
def movimiento(x):
    match x:
        case 0:
            return [1, 3]     # Derecha (1), Abajo (3)
        case 1:
            return [0, 2, 4]  # Izquierda (0), Derecha (2), Abajo (4)
        case 2:
            return [1, 5]     # Izquierda (1), Abajo (5)
        case 3:
            return [0, 4]     # Arriba (0), Derecha (4)
        case 4:
            return [1, 3, 5]  # Arriba (1), Izquierda (3), Derecha (5)
        case 5:
            return [2, 4]     # Arriba (2), Izquierda (4)

def main(board):
    x = cerca_0(board)
    if board == "123450":
        return 0
    
    else:    
        fila=deque()
        history=set()
        fila.append((board, 0, x))
        
        while fila:   
            table, ciclos, x = fila.popleft()
            
            for x2 in movimiento(x):
                
                new_table = list(table)
                new_table[x] = new_table[x2]
                new_table[x2] = "0"
                new_table = "".join(new_table)
                
                if new_table not in history:
                    if new_table == "123450":
                        return ciclos+1
                        
                    history.add(new_table)
                    fila.append((new_table, ciclos+1, x2))
        
        return -1

board = [[4,1,2],
         [5,0,3]]

table ="".join(map(str, board[0]))
table = table + "".join(map(str, board[1]))

print(main(table))


