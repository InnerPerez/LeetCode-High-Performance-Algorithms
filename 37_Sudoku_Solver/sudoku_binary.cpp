#include <iostream>
#include <vector>
#include <print>
#include <bitset>
#include <bit>
using namespace std;


pair <int, int> attack(vector<int>& board, int(&filas)[9], int(&columnas)[9], int(&bloques)[9]) {
    int x2;
    int y2;
    int id_bloque;
    int ocupados;
    int bits_ocupados;
    int posibilidades_libres;
    int min_opciones = INT_MAX;
    int mejor_x = -1;
    int mejor_posibilidades = 0;

    for (int x = 0; x < board.size(); x++) {
        
        if (board[x] == 0) {
            x2 = x % 9;
            y2 = x / 9;
            id_bloque = (y2 / 3) * 3 + (x2 / 3);
            ocupados = filas[y2] | columnas[x2] | bloques[id_bloque];
            bits_ocupados = __popcnt(ocupados & 1022); // El 1022 filtra solo tus 9 posiciones del Sudoku
            posibilidades_libres = 9 - bits_ocupados;

            if (posibilidades_libres < min_opciones){
                min_opciones = posibilidades_libres;
                mejor_x = x;
                mejor_posibilidades = (~ocupados) & 1022; // como ocupados dice los numeros que tiene el sudoku con la NOT inviertes y obtienes los valores que hacen falta
            }
  
        }

    }

    return { mejor_x , mejor_posibilidades};

}

int solved(vector<int>& board, int(&filas)[9], int(&columnas)[9], int(&bloques)[9]) {

    auto [x, mask] = attack(board, filas, columnas, bloques);

    int numero_aislado;
    int numero_insert;
    

    if (x != -1) {

        
        int flag=0;
        int x2 = x % 9;
        int y2 = x / 9;
        int id_bloque = (y2 / 3) * 3 + (x2 / 3);


        while (mask > 0) {
            numero_aislado = mask & -mask;
            numero_insert = std::countr_zero((unsigned int)numero_aislado);
            board[x] = numero_insert;

            bloques[id_bloque] |= (1 << numero_insert);
            filas[y2] |= (1 << numero_insert);
            columnas[x2] |= (1 << numero_insert);

            flag = solved(board, filas, columnas, bloques);

            if (flag == 1) {
                return 1;
            }
            

            bloques[id_bloque] &= ~(1 << numero_insert);
            filas[y2] &= ~(1 << numero_insert);
            columnas[x2] &= ~(1 << numero_insert);
            board[x] = 0;
           
            mask = mask - numero_aislado;
        }


    }else {
        


        return 1;

    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    vector<vector<char>> board = {
    {'1', '.', '.', '.', '.', '7', '.', '9', '.'},
    {'.', '3', '.', '.', '2', '.', '.', '.', '8'},
    {'.', '.', '9', '6', '.', '.', '5', '.', '.'},
    {'.', '.', '5', '3', '.', '.', '9', '.', '.'},
    {'.', '1', '.', '.', '8', '.', '.', '.', '2'},
    {'6', '.', '.', '.', '.', '4', '.', '.', '.'},
    {'3', '.', '.', '.', '.', '.', '.', '1', '.'},
    {'.', '4', '.', '.', '.', '.', '.', '.', '7'},
    {'.', '.', '.', '7', '.', '.', '.', '.', '5'}
    };


    vector<int> new_board;

    int filas[9] = { 0 };
    int columnas[9] = { 0 };
    int bloques[9] = { 0 };
    int id_bloque;

    for (int y = 0; y < 9; y++) {

        for (int x = 0; x < 9; x++) {

            int numero = board[y][x] - 48;

            if (numero > 0) {
                id_bloque = (y / 3) * 3 + (x / 3);
                bloques[id_bloque] |= (1 << numero);
                filas[y] |= (1 << numero);
                columnas[x] |= (1 << numero);
            }else {
                numero = 0;
            }


            new_board.push_back(numero);
        }

    }

    solved(new_board, filas, columnas, bloques);

    for (int i = 0; i < 81; i++) {
        board[i / 9][i % 9] = new_board[i] + 48;
    }

    cout << "\n--- TABLE SOLVED ---\n";
    for (const auto& fila : board) {
        for (char celda : fila) {
            cout << celda << " ";
        }
        cout << "\n";
    }
    
}
