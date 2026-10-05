// tree_int_vector.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <string>
#include <print>
using namespace std;

struct nodes{
	
    struct nodes* letter[28] = {nullptr}; //nullptr start all pointers off
	int end = 0;
    string palabra = "";
};




int find_words(nodes* nodo, int* conter_array,char* line_vector, int x, int limite_x, vector<string> & result)
{

    if (nodo->end == 1)
    {
        *conter_array = *conter_array - 1;
        nodo->end = 0;
        result.push_back(nodo->palabra);
        if (*conter_array == 0)
        {

            return 1;
        }

    }
           
    char save = line_vector[x];
    if (nodo->letter[save - 97] != nullptr)
    {
        int r;
        line_vector[x] = 124;

        r = find_words(nodo->letter[save - 97], conter_array, line_vector, (x - limite_x), limite_x, result); //up
        if (r == 1) { line_vector[x] = save;return 1; }
        r = find_words(nodo->letter[save - 97], conter_array, line_vector, (x + limite_x), limite_x, result); //down
        if (r == 1) { line_vector[x] = save;return 1; }
        r = find_words(nodo->letter[save - 97], conter_array, line_vector, (x + 1), limite_x, result); //right
        if (r == 1) { line_vector[x] = save;return 1; }
        r = find_words(nodo->letter[save - 97], conter_array, line_vector, (x - 1), limite_x, result); //left
        if (r == 1) { line_vector[x] = save;return 1; }
        line_vector[x] = save;
    }
          
    return 0;
}

int main()
{
    vector<vector<char>> board;
    vector<string> words;

    board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    words = {
        "oath", "pea", "eat", "rain", "oathi", "oathk",
        "oathf", "oate", "oathii", "oathfi", "oathfii"
    };

   

    nodes* nodes_ = new nodes();
    nodes* raiz = nodes_;

    int counter[26] = {0};

    for(const string & word : words)
    {
        nodes_ = raiz;
        counter[word[0] - 97] = counter[word[0] - 97] + 1;
        for(const char & char_ : word)
        {
            if(!nodes_->letter[char_ - 97])
            {
                nodes_->letter[char_ - 97] = new nodes();
            }
            nodes_ = nodes_->letter[char_ - 97];
        }
        nodes_->end = 1;
        nodes_->palabra = word;
    }
    
   
    int y = board.size();
    int x = board[0].size();

    char* mapa_plano = new char[(x + 2) * (y + 2)];

    int c = 0;

    ////PADDING////
    for(c; c < x+2; c++)
    {
        mapa_plano[c] = 124;
    }
    
    for (int y2 = 0; y2 < y; y2++) 
    {
        mapa_plano[c++] = 124;
        for(int x2=0; x2 < x; x2++)
        {

            mapa_plano[c] = board[y2][x2];
            c++;

        }
        mapa_plano[c++] = 124;
        
    }

    for (c; c < ((x + 2) * (y + 2)); c++)
    {
        mapa_plano[c] = 124;
    }
    ////END PADDING////
    

    vector<string> r;
    for (int i=0; i < ((x + 2) * (y + 2)); i++)
    {
        if (mapa_plano[i] != 124)
        {
            if (counter[mapa_plano[i] - 97] > 0) 
            {
                find_words(raiz, &counter[mapa_plano[i] - 97], mapa_plano, i, x+2, r);
            }
        }
        
    }
    print("{}", r);
    delete[] mapa_plano;

}
