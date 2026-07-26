# -*- coding: utf-8 -*-
"""
Created on Mon Jun 15 11:43:06 2026

@author: blzsm
"""
class words_1:
    def __init__(self):
        self.letra = {}
        self.final = False
        
def x_y(board, letra):
    
    y=0
    r=[]
    for line in board:
        x=0
        for letra_x in line:
            
            if letra_x == letra:
                r.append((y, x))
            
            x=x+1
        y=y+1
    return r
            
def verifica_avanti(board, y, x, letra_next, limite_y, limite_x):  

    r=[]
    
    if y-1 >= 0: #arriba
         if board[y-1][x] in letra_next.letra:
             r.extend([(y-1, x)])
    if y+1 < limite_y: #abajo
        if board[y+1][x] in letra_next.letra:
            r.extend([(y+1, x)])
    
    if x-1 >= 0:#sinistra
        if board[y][x-1] in letra_next.letra:
            r.extend([(y, x-1)])
    if x+1 < limite_x:#destra
        if board[y][x+1] in letra_next.letra:
            r.extend([(y, x+1)])
    return r


def all_x_y_iniciales(board, letra, limite_y, limite_x):
    
    r = []
    
    for y in range(limite_y):
        for x in range(limite_x):
            if board[y][x] == letra:
               r.extend([(y,x)])
                
    return r


    
def encuentra_palabras(board, raiz, limite_y, limite_x, y, x, palabra, resultado):
    
    letra_actual = board[y][x]
    palabra = palabra + letra_actual
    
    if raiz.final:
        raiz.final=False
        resultado.add(palabra)
    
    if raiz.letra:
        
        escudo = board[y][x]
        board[y][x]="#"
        all_interno = verifica_avanti(board, y, x, raiz, limite_y, limite_x)
        
        for y2, x2 in all_interno:
        
            if board[y2][x2] in raiz.letra:
                
                encuentra_palabras(board, raiz.letra[board[y2][x2]], limite_y, limite_x, y2, x2, palabra, resultado)
                if not raiz.letra[board[y2][x2]].letra and not raiz.letra[board[y2][x2]].final:
                    raiz.letra.pop(board[y2][x2]) #agregar la poda de manera correcta
            
            
        board[y][x] = escudo    
            
    else:
        return 
        

if __name__ == "__main__":
    
    raiz = words_1()
    
    """board = [
        ["a","a","a"],
      ["a","a","a"],
      ["a","a","a"]
      ]

    words = ["aaaaa", "aaaax"]"""
    
    """board = [["o","a","a","n"],
             ["e","t","a","e"],
             ["i","h","k","r"],
             ["i","f","l","v"]]
    words = ["oath","pea","eat","rain"]"""
    
    words = ["ab", "abc"]
    board = [["a", "b", "c"]]
    board = [
    ["a", "b", "b"]
]
    words = ["ab"]
    board = [
    ["a", "b"],
    ["b", "a"]
]
    words = ["ab"]
    
    
    save_raiz = raiz
    
    for palabra in words:
        
        for letra in palabra:
            if letra not in save_raiz.letra:
                save_raiz.letra[letra]=words_1()
                
            save_raiz = save_raiz.letra[letra]
        
        save_raiz.final = True 
        
        save_raiz = raiz

    limite_y= len(board)
    limite_x = len(board[0])
    
    
    all_y_x=[]
    
    
    for key in raiz.letra:
        all_y_x.extend(all_x_y_iniciales(board, key, limite_y, limite_x))
    
    
    resultado = set()
    for y, x in all_y_x:
        letra_inicial = board[y][x]
        encuentra_palabras(board, raiz.letra[letra_inicial], limite_y, limite_x, y,x, "", resultado)
        
    print(list((resultado)))
        

    
