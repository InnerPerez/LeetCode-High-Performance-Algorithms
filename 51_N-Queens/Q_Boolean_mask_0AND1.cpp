// 0MS

#include <iostream>
#include <vector>
#include <print>

using namespace std;

void n_q(vector<char>& board, vector<vector<char>>& r, vector<int> & diagonally_left, vector<int> & diagonally_right, vector<int> & bool_x2, int y, int n) {

    if (y < n){
        /*hace el codigo de la N_Q*/

        for (int x = 0; x < n; x++) {
            
            if ( diagonally_left[y - x + n - 1] != 1 &&  diagonally_right[y+x] != 1 && bool_x2[x] != 1) {

                diagonally_left[y - x + n - 1] = 1;
                diagonally_right[y + x] = 1;
                bool_x2[x] = 1;

                int insert;
                insert = (y * n) + x;
                board[insert] = 81;

                n_q(board, r, diagonally_left, diagonally_right, bool_x2, y+1, n);

                board[insert] = 46;
                diagonally_left[y - x + n - 1] = 0;
                diagonally_right[y + x] = 0;
                bool_x2[x] = 0;

            }
            
        }
    }
    else 
    {
        r.push_back(board);
        return;
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5;

    vector<char> board(n*n, '.');

    vector<int> diagonally_left(2 * n - 1, 0);
    vector<int> diagonally_right(2 * n - 1, 0);
    vector<int> bool_x2(2*n, 0);

    vector<vector<char>> r;
    n_q(board, r, diagonally_left, diagonally_right, bool_x2, 0, n);
   
    vector<vector<string>> result;

    for (int y = 0; y < r.size(); y++) {

        string re;
        vector<string> appo;

        for (int x = 0; x < n * n; x++){

            re = re + r[y][x];
            if ( (x+1) % n == 0) {
                
                appo.push_back({ re });
                re = "";

            }            

        }
        result.push_back(appo);
    
    }

    std::println("{}", result);

    return 0;

}
