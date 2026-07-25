# -*- coding: utf-8 -*-
"""
Created on Mon Jul 20 14:10:19 2026

@author: blzsm
"""

from collections import deque

def arbol_comodines_func(wordList):
    
    len_palabras = len(wordList[0])
    
    arbol_comodines={}
    for palabra in wordList:
        
        palabra_list = list(palabra)
  
        for c in range(len_palabras):
            
            prev=palabra_list[c]
            palabra_list[c]="*"
            palabra_comodin= "".join(palabra_list)
            arbol_comodines.setdefault(palabra_comodin, []).append(palabra)
            
            palabra_list[c]=prev
    return arbol_comodines



def word_ladder_map(beginWord, endWord, wordList, arbol_comodines):
    
    if endWord not in wordList:
        return (1, {})
        
    
    len_palabras = len(wordList[0])         
    cola_1=deque()
    cola_1.append(beginWord)
    cola_2=deque()
    cola_2.append(endWord)
    
    mapa={}

    padre_visitados=set()
    padre_visitados_cola_2=set()
    
    flag=False
    
    altura=0
    while cola_1 and cola_2:
        
        
        cola_2_set=set(cola_2)
        cola_1_set=set(cola_1)      
        l_cola_1 = len(cola_1)
        l_cola_2 = len(cola_2)
        altura+=1
        if l_cola_1 < l_cola_2:
            
            hijos_momentaneos=set()
            
            appo_padre=set()    
            for _ in range(l_cola_1):
                
                padre = cola_1.popleft()
                
                if padre not in padre_visitados:
                
                    padre_list=list(padre)
                    hijos_agregados=set()

                    for i in range(len_palabras):
                        precedente = padre_list[i]
                        padre_list[i]="*"
                        key= "".join(padre_list)
    
                        
                        for hijos in arbol_comodines[key]:
                            
                            if hijos not in padre_visitados and hijos not in padre_visitados_cola_2:
                                if hijos not in hijos_agregados:
                                    if hijos != padre:             
                                        if hijos not in hijos_momentaneos:                        
                                            cola_1.append(hijos)
                                            hijos_momentaneos.add(hijos)
                                        mapa.setdefault(padre, []).append(hijos)
                                    if hijos in cola_2_set:
                                        flag=True
                                
                                    hijos_agregados.add(hijos)
                                    
                            
                        padre_list[i]=precedente
                        
                appo_padre.add(padre)
            padre_visitados.update(appo_padre)
        else:
            
            hijos_momentaneos=set()
            
            appo_padre=set()    
            for _ in range(l_cola_2):
                
                padre = cola_2.popleft()
                
                if padre not in padre_visitados_cola_2:
                
                    padre_list=list(padre)
                    hijos_agregados=set()

                    for i in range(len_palabras):
                        precedente = padre_list[i]
                        padre_list[i]="*"
                        key= "".join(padre_list)
    
                        
                        for hijos in arbol_comodines[key]:
                            
                            if hijos not in padre_visitados_cola_2 and hijos not in padre_visitados:
                                if hijos not in hijos_agregados:
                                    if hijos != padre:             
                                        if hijos not in hijos_momentaneos:                        
                                            cola_2.append(hijos)
                                            hijos_momentaneos.add(hijos)
                                        mapa.setdefault(hijos, []).append(padre)
                                    if hijos in cola_1_set:
                                        flag=True
                                
                                    hijos_agregados.add(hijos)
                                    
                        padre_list[i]=precedente
                        
                appo_padre.add(padre)
            padre_visitados_cola_2.update(appo_padre)
            
            
        if flag:
            return (altura,mapa)
    
    return (altura, mapa)


r=[]
visitados=set()

def recorre(mapa, next_1, endWord, ruta_actual, altura, cache):
    
    
    if next_1 == endWord:
        return [[endWord]]
    
    
    if altura <= 0:
        return []
    
    if next_1 in ruta_actual:
        return []
    
    llave_cache = (next_1, altura)
    if llave_cache in cache:
        return cache[llave_cache]
    
    
    ruta_actual.add(next_1)  
    resultado_caminos = []
    if next_1 in mapa:
        for value in mapa[next_1]:
            
            secuencia_de_caminos = recorre(mapa, value, endWord, ruta_actual, altura-1, cache)
            
            
            if secuencia_de_caminos:
                for subcamino in secuencia_de_caminos:
                    camino_completo = [next_1] + subcamino
                    
                    resultado_caminos.append(camino_completo)
     
                
    ruta_actual.discard(next_1)  
    cache[llave_cache]=resultado_caminos

    return resultado_caminos
    
            

import time
tiempo_inicio = time.perf_counter()



beginWord = "aaaaa"
endWord = "ggggg"
wordList =  ["aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"]


if beginWord not in set(wordList):
    wordList.append(beginWord)

joyli = arbol_comodines_func(wordList)

print(joyli)

altura, mapa = word_ladder_map(beginWord, endWord, wordList, joyli)
print(mapa)
if mapa:
    
    caminos = recorre(mapa, beginWord, endWord, set(), altura, {})
    
    print(caminos)
else:
    print([])


tiempo_fin = time.perf_counter()


# 3. Restas el final menos el inicio para obtener los segundos exactos
tiempo_total = tiempo_fin - tiempo_inicio

# 4. Lo imprimes en la consola
print(f"Tiempo de ejecución: {tiempo_total:.6f} segundos")
