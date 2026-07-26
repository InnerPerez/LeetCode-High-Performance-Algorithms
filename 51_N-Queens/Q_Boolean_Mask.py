# -*- coding: utf-8 -*-
"""
Created on Sun Jul 26 22:53:29 2026

@author: blzsm
"""



import time
tiempo_inicio = time.perf_counter()
#siguiente_nivel = x1 + n - (x1 % n)

def N_Q(board, n, columna_vertical, diagonal_izquierda, diagonal_derecha, y2, r):
    
    
    if y2 < n:

        for x2 in range(n):
            

            if not diagonal_izquierda[y2 - x2 + n - 1] and not diagonal_derecha[y2 + x2] and not columna_vertical[x2]:
            
                diagonal_izquierda[y2 - x2 + n - 1] = True
                diagonal_derecha[y2 + x2] = True
                columna_vertical[x2] = True
                
                
                insert=(y2*n)+x2
                
                board[insert]="Q"
                
                N_Q(board, n, columna_vertical, diagonal_izquierda, diagonal_derecha, y2+1, r)
                
                board[insert]="."
                                
                diagonal_izquierda[y2 - x2 + n - 1] = False
                diagonal_derecha[y2 + x2] = False
                columna_vertical[x2] = False
           
    else:
        
        string_plana = "".join(board)
        tablero_formateado = [string_plana[i : i + n] for i in range(0, len(string_plana), n)]
        r.append(tablero_formateado)
        return
    
    
            
    
    
for n in range(1, 10):
    columna_vertical = [False] * n
    diagonal_izquierda = [False] * (2 * n)
    diagonal_derecha = [False] * (2 * n)
    
    board = ["." for _ in range(n) for _ in range(n)]
    
    l_board=len(board)
    r=[]
    
    N_Q(board, n, columna_vertical, diagonal_izquierda, diagonal_derecha, 0, r)



tiempo_fin = time.perf_counter()


tiempo_total = tiempo_fin - tiempo_inicio
print(f"Tiempo de ejecución: {tiempo_total:.6f} segundos")
