# -*- coding: utf-8 -*-
"""
Created on Fri Jul  3 22:10:37 2026

@author: blzsm
"""
def obtener_vecinos_validos(palabra, word_set):
    vecinos = set()  # Ahora es un Set
    lista_palabra = list(palabra)
    
    for i in range(len(lista_palabra)):
        letra_original = lista_palabra[i]
        for c in 'abcdefghijklmnopqrstuvwxyz':
            if c != letra_original:
                lista_palabra[i] = c
                nueva_palabra = "".join(lista_palabra)
                
                if nueva_palabra in word_set:
                    vecinos.add(nueva_palabra)
                    
        lista_palabra[i] = letra_original
        
    vecinos.discard(palabra) 
    return vecinos


def main(beginWord,endWord, wordList):
    
    if endWord in wordList:
        #operaciones
        fila={beginWord}
        visitados = {beginWord}
        
        fila2={endWord}
        visitados_2={endWord}
        
        contador=1
        len_fila=1
        len_fila_2=1
        while fila and fila2:
            
            contador+=1
            
            if len_fila <= len_fila_2:
                len_fila = 0
                save_fila = set(fila)
                for value in save_fila:
                    permuta = obtener_vecinos_validos(value, wordList)
                    for insert in permuta:
                        if insert in visitados_2:
                            return contador
                        if insert in wordList:
                            if insert not in visitados:
                                len_fila+=1
                                visitados.add(insert)
                                fila.add(insert)
                    
                    fila.discard(value)
            else:
                #fila2
                save_fila_2 = set(fila2)
                len_fila_2=0
                for value in save_fila_2:
                    permuta = obtener_vecinos_validos(value, wordList)
                    for insert in permuta:
                        if insert in visitados:
                            return contador
                        if insert in wordList:
                            if insert not in visitados_2:
                                len_fila_2+=1
                                visitados_2.add(insert)
                                fila2.add(insert)
                    
                    fila2.discard(value)
            
        return 0
    else:
        return 0
    


beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

wordList = set(wordList)
print(main(beginWord,endWord, wordList))
