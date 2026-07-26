# -*- coding: utf-8 -*-
"""
Created on Sun Jun 21 00:22:13 2026

@author: blzsm
"""

"""for key in grafo:
    grafo[key] = dict(sorted(grafo[key].items(), key=lambda item: item[1], reverse=True))"""
    
n = 3
flights = [[0,1,10],[0,2,10],[0,3,10],[0,4,10],[0,5,10],[0,6,10],[0,7,10],[0,8,10],[1,0,10],[1,2,10],[1,3,10],[1,4,10],[1,5,10],[1,6,10],[1,7,10],[1,8,10],[2,0,10],[2,1,10],[2,3,10],[2,4,10],[2,5,10],[2,6,10],[2,7,10],[2,8,10],[3,0,10],[3,1,10],[3,2,10],[3,4,10],[3,5,10],[3,6,10],[3,7,10],[3,8,10],[4,0,10],[4,1,10],[4,2,10],[4,3,10],[4,5,10],[4,6,10],[4,7,10],[4,8,10],[5,0,10],[5,1,10],[5,2,10],[5,3,10],[5,4,10],[5,6,10],[5,7,10],[5,8,10],[6,0,10],[6,1,10],[6,2,10],[6,3,10],[6,4,10],[6,5,10],[7,0,10],[7,1,10],[7,2,10],[7,3,10],[7,4,10],[7,5,10],[8,0,10],[8,1,10],[8,2,10],[8,3,10],[8,4,10],[8,5,10]]
src= 0
dst= 9
k= 8


grafo={}
for origen, destino, precio in flights:
    if not origen in grafo:
        grafo[origen]={}      
    grafo[origen][destino]=precio


precio_minimo =  float('inf')
if src in grafo:
    if k == 0:
        for key in grafo[src]:
            if key == dst:
                precio_minimo = min(precio_minimo, grafo[src][key])

            
    else:   
        #la tupla esta compuesta por, src, k, precio
        from collections import deque
        
        fila = deque()
        
        fila.append((src, 0, 0))
        max_k=-1
        
        
        save_ruta={}
        
        while fila:
         
            next_1, max_k, precio = fila.popleft()
            
            if dst == next_1:
                precio_minimo = min(precio_minimo, precio)
            else:
                if next_1 in grafo:
                    if max_k <= k:
                       
                        if next_1 in grafo:
                            for key in grafo[next_1]:
                                precio_2 = grafo[next_1][key]
                                if key not in save_ruta or precio + precio_2 < save_ruta[key]:
                                    
                                    save_ruta[key]=precio+precio_2
                                    
                                    fila.append((key, max_k+1, precio+precio_2))
             
else:
    print(-1)

if precio_minimo == float('inf'):
    print(-1)
else:
    print(precio_minimo)
      
