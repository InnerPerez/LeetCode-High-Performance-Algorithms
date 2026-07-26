def ataque(board, filas, columnas, cajas):
    
    minimo = [float('inf'),[], 0]
    for x in range(81):
        
        if board[x] == 0:
            y=x//9
            x2=x%9
            box_index = (y // 3) * 3 + (x2 // 3)
            
            ocupados = filas[y] | columnas[x2] | cajas[box_index]
            candidatos = ~ocupados & 0x3FE
            conta = candidatos.bit_count()
            
            appo_nums = []
            while candidatos > 0:
                bit_aislado = candidatos & -candidatos
                
                numero = bit_aislado.bit_length() - 1
                appo_nums.append(numero)
                candidatos -= bit_aislado
            
            if conta < minimo[0]:
                minimo[0]=conta
                minimo[1]=appo_nums
                minimo[2] = x

                
    return minimo


def recorre(board, filas, columnas, cajas):
    
    r = ataque(board, filas, columnas, cajas)
    if r[1]:
    
        for numeros in r[1]:
            
            board[r[2]] = numeros
            
            y=r[2]//9
            x=r[2]%9
            
            filas[y] |= (1 << numeros)
            columnas[x] |= (1 << numeros)
            box_index = (y // 3) * 3 + (x // 3)
            cajas[box_index] |= (1 << numeros)
            
            risultato = recorre(board, filas, columnas, cajas)
            
            if risultato is not None:
                return risultato
            
            board[r[2]] = 0
            filas[y] &=~ (1 << numeros) #and not
            columnas[x] &=~ (1 << numeros)
            cajas[box_index] &=~ (1 << numeros)
            
        return None
    else:
        if 0 in board:
            return None
        return board
            
 

def main():
    matrice = [
    ["1", ".", ".", ".", ".", "7", ".", "9", "."],
    [".", "3", ".", ".", "2", ".", ".", ".", "8"],
    [".", ".", "9", "6", ".", ".", "5", ".", "."],
    [".", ".", "5", "3", ".", ".", "9", ".", "."],
    [".", "1", ".", ".", "8", ".", ".", ".", "2"],
    ["6", ".", ".", ".", ".", "4", ".", ".", "."],
    ["3", ".", ".", ".", ".", ".", ".", "1", "."],
    [".", "4", "1", ".", ".", ".", ".", ".", "7"],
    [".", ".", "7", ".", ".", ".", "3", ".", "."]
]



    filas = [0] * 9
    columnas = [0] * 9
    cajas = [0] * 9


    for x in range(9):
        for y in range(9):
            value = matrice[x][y]        
            if value != ".":
                num = int(value)
                box_index = (x // 3) * 3 + (y // 3)
                filas[x] |= (1 << num)
                columnas[y] |= (1 << num)
                cajas[box_index] |= (1 << num)

    board=[]

    for line in matrice:
        for value in line:
            if value == ".":
                board.append(0)
            else:
                board.append(int(value))
                
        
    return recorre(board, filas, columnas, cajas)



r2 = main()
r=[]
for value in r2:
    r.append(str(value))

r = [r[0:9]]+[r[9:18]]+[r[18:27]]+[r[27:36]]+[r[36:45]]+ [r[45:54]]+ [r[54:63]]+[r[63:72]]+[r[72:81]]

print(r)

      
    







