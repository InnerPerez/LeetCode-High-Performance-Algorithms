# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 11:11:41 2026

@author: blzsm
"""

def derecha_izquierda_abajo_arriba(board, x, y, numero):
    limite_x = len(board[0])
    limite_y = len(board)
    r=[]
    
    if y-1 >= 0: #arriba
         if board[y-1][x] > numero:
             r.append((y-1, x))
    if y+1 < limite_y: #abajo
        if board[y+1][x] > numero:
            r.append((y+1, x))
    
    if x-1 >= 0:#sinistra
        if board[y][x-1] > numero:
            r.append((y, x-1))
    if x+1 < limite_x:#destra
        if board[y][x+1] > numero:
            r.append((y, x+1))
            
    return r




def recorre(board, x, y, espejo, resultado):
    
    if espejo[y][x] != -1:
       return espejo[y][x]
    
    r = derecha_izquierda_abajo_arriba(board, x, y, board[y][x])
    if r:
        pre_long = 1
        long = 0
        
        for y2,x2 in r:
            
            long = recorre(board, x2, y2, espejo, resultado)
            
            if long > pre_long:
                pre_long = long
                
                
        espejo[y][x] =pre_long+1
        
        if espejo[y][x]  > resultado[0]:
            resultado[0] = espejo[y][x]
            
        return espejo[y][x]
        
    
    
    else:   
        espejo[y][x]=1
        return espejo[y][x]
    

board = [[ 1,  2,  3 ],
         [ 8,  9,  4 ],
         [ 7,  6,  5 ]]





copia =[]

for y in range(len(board)):
    save=[]
    for x in range(len(board[0])):
        save.append(-1)
    copia.append(save)
    
#print(copia)
        
resultado = [1]
if len(board) > 0:
    for y in range(len(board)):
        for x in range(len(board[0])):
            recorre(board, x, y, copia, resultado)
        
else:
    resultado[0]=0
    
print(resultado)        
        
