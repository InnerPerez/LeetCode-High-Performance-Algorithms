# -*- coding: utf-8 -*-
"""
Created on Wed Jul 22 00:29:17 2026

@author: blzsm
"""

def re(s, p, i, j, altura, cache):
    
    if (i, j) in cache:
        return cache[(i, j)]
    
    if j == len(p):
        cache[(i, j)] = (i == altura)
        return cache[(i, j)]    


    if p[j] != "." and p[j] != "*":
        
        #siamo su una lettera
        if j+1 < len(p) and p[j+1] == "*":
            r = re(s, p, i, j+2, altura, cache)
            if r: cache[(i, j)]=True; return True
            
            if i < altura and p[j] == s[i]:          
                r = re(s, p, i+1, j, altura,cache)
                if r: cache[(i, j)]=True; return True
        
        else:
            if i < altura and p[j] == s[i]:
                r = re(s, p, i+1, j+1, altura, cache)
                if r: cache[(i, j)]=True; return True
            else:
                cache[(i, j)]=False; return False
              
    else:
        if i < altura and j+1 == len(p) and p[j]==".":
            r = re(s, p, i+1, j+1, altura, cache)
            if r: cache[(i, j)]=True ; return True
            
        if  i < altura and j+1 < len(p) and p[j] == "." and  p[j+1] != "*":
            r = re(s, p, i+1, j+1, altura, cache)
            if r: cache[(i, j)]=True ; return True
        
        if j+1 < len(p) and p[j+1] == "*" and p[j] == ".": #.* una linea de tiempo recuerda que tiene que encontrar la ultima j+2 por lo que por cada j+2 == s[i] debe generar una rama
            
         
            r = re(s, p, i, j+2, altura, cache)
            if r: cache[(i, j)]=True; return True
            
            if i < altura:
                r = re(s, p, i+1, j, altura, cache)
        
                if r: cache[(i, j)]=True; return True
    
                  
    cache[(i, j)]=False
    return False
            
                








s = "a"
p = "a." #verificar el while infinito que se genra 




altura = len(s)
s=list(s)
p=list(p)

le_p=len(p)
r = re(s, p, 0, 0, altura, {})
print(r)