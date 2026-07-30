// regular+cache.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <vector>
#include <print>
#include <string>
#include <utility>
using namespace std;

int evaluarExpresion(const string & s, const string & p, int len_s, int len_p, int cache[40][40], int i, int j){

    int r = 0;

    if (cache[i][j] != -1) {
        return cache[i][j];
    }

    if (j == len_p) {
        if (i == len_s) {
            cache[i][j] = 1;
            
        }
        else {
            cache[i][j] = 0;
        }
        return cache[i][j];
    }

    if (p[j] != 46 && s[i] != 42) {
   
        if (j+1 < len_p && p[j+1] == 42) {

            r = evaluarExpresion(s, p, len_s, len_p, cache, i, j + 2);
            if (r == 1) {
                cache[i][j] = 1; return 1;
            }
           
            if (i < len_s && p[j] == s[i]) {
                r = evaluarExpresion(s, p, len_s, len_p, cache, i+1, j);
                if (r == 1) {
                    cache[i][j] = 1; return 1;
                }
            }


        }
        else {
            if (i < len_s && p[j] == s[i]) {
                r = evaluarExpresion(s, p, len_s, len_p, cache, i + 1, j+1);
                if (r == 1) {
                    cache[i][j] = 1; return 1;
                }

            }
            else {
                cache[i][j] = 0; return 0;
            }

        }

    }else {
    
      
        if (i < len_s && j+1 == len_p && p[j] == 46) {
            r = evaluarExpresion(s, p, len_s, len_p, cache, i + 1, j + 1);
            if (r == 1) {
                cache[i][j] = 1; return 1;
            }
        }

        if (i < len_s && j + 1 < len_p && p[j] == 46 && p[j + 1] != 42) {
            r = evaluarExpresion(s, p, len_s, len_p, cache, i + 1, j + 1);
            if (r == 1) {
                cache[i][j] = 1; return 1;
            }
        }
        if (j+1 < len_p && p[j+1] == 42 && p[j] == 46) {

            r = evaluarExpresion(s, p, len_s, len_p, cache, i, j + 2);
            if (r == 1) {
                cache[i][j] = 1; return 1;
            }

            if (i < len_s) {
                r = evaluarExpresion(s, p, len_s, len_p, cache, i+1, j);
                if (r == 1) {
                    cache[i][j] = 1; return 1;
                }
            }

        }

    }
    cache[i][j] = 0;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    


    string  s = "aa";
    string p = "a*";
    int len_s = s.size(), len_p= p.size();

    int cache[40][40]; /* It’s not a coincidence, it’s because the maximum string length they can give you on LeetCode is 20/30 characters.*/
    memset(cache, -1, sizeof(cache));

    int r = evaluarExpresion(s, p, len_s, len_p, cache,0,0);
    if (r == 1) {
        cout << "True" << endl;
    }
    else {

        cout << "False" << endl;
    }

}
