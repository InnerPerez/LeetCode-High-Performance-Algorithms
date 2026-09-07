#include <iostream>
#include <vector>
using namespace std;


int dfs(int x, int y, int limite_y, int limite_x, vector<int> & cache, vector<vector<int>> & matrix)
{
    int index_ = (y * limite_x) + x; //calculate plane index, because will be use a 1D dimension cache. (y*limite_x) give my de height and '+x' the posicion

    if (cache[index_] != 0) return cache[index_]; //if i'm have one value in cache make return this value!

    int max = 0;
    int conta;

    //all conditions work as if they were a for

    if(x-1 >= 0 && matrix[y][x-1] > matrix[y][x])
    {        
        conta = dfs(x - 1, y, limite_y, limite_x, cache, matrix);
        if(conta > max)
        {
            max = conta;
        }   
    }

    if(x+1 < limite_x && matrix[y][x + 1] > matrix[y][x])
    {
        conta = dfs(x + 1, y, limite_y, limite_x, cache, matrix);
        if (conta > max)
        {
            max = conta;
        }
    }

    if(y-1 >= 0 && matrix[y-1][x] > matrix[y][x])
    {
        conta = dfs(x, y-1, limite_y, limite_x, cache, matrix);
        if (conta > max)
        {
            max = conta;
        }
    }

    if (y + 1 < limite_y && matrix[y + 1][x] > matrix[y][x])
    {
        conta = dfs(x, y + 1, limite_y, limite_x, cache, matrix);
        if (conta > max)
        {
            max = conta;
        }
    }
    //first time, i'm return 1 for this other times add max (in max you have 1+1+1...) +1
    //the first return happens when you are in the head and don't have problem became you add other values when you come down.
    cache[index_] = max + 1;
    return cache[index_];
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix;
    
    matrix = {
    {1,  20, 21, 40, 41, 60, 61, 80, 81, 100},
    {2,  19, 22, 39, 42, 59, 62, 79, 82, 99},
    {3,  18, 23, 38, 43, 58, 63, 78, 83, 98},
    {4,  17, 24, 37, 44, 57, 64, 77, 84, 97},
    {5,  16, 25, 36, 45, 56, 65, 76, 85, 96},
    {6,  15, 26, 35, 46, 55, 66, 75, 86, 95},
    {7,  14, 27, 34, 47, 54, 67, 74, 87, 94},
    {8,  13, 28, 33, 48, 53, 68, 73, 88, 93},
    {9,  12, 29, 32, 49, 52, 69, 72, 89, 92},
    {10, 11, 30, 31, 50, 51, 70, 71, 90, 91}
    };

    matrix = {
        {1,  10, 2,  20},
        {15, 99, 16, 21},
        {14, 18, 17, 102},
        {13, 20, 21, 22}
    };

    int limite_y = matrix.size();
    int limite_x = matrix[0].size();
    int max_2 = 0;
    int r;
    vector<int> cache((limite_y * limite_x), 0);
    //
    for (int y=0; y < limite_y; y++)
    {

        for(int x=0; x < limite_x; x++)
        {
            
            r = dfs(x, y, limite_y, limite_x, cache, matrix);
            if (r > max_2){
                max_2 = r;
            }

        }

    }
    cout << max_2 <<endl;
}
