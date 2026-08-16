#include <iostream>
#include <vector>
#include <print>
#include <deque>

using namespace std;
int main()
{

    int n = 11;
    vector<vector<int>> flights = { {0,3,3}, {3,4,3}, {4,1,3}, {0,5,1}, {5,1,100}, {0,6,2}, {6,1,100}, {0,7,1}, {7,8,1}, {8,9,1}, {9,1,1}, {1,10,1}, {10,2,1}, {1,2,100} };
    int src = 0;
    int dst = 2;
    int k = 4;
    // Saída esperada no LeetCode: 11

    
    vector<vector<pair<int, int>>> grafo(n);

    for (vector<int> & values: flights)
    {
    
        grafo[values[0]].push_back({ values[1], values[2]});

    }

    deque<vector<int>> fila;

    //inicializar la fila
    for (auto & values : grafo[src]) {
        //agregamos tres valores a la fila next, precio, ciclos hechos
        fila.push_back({ values.first, values.second, 1});
      
    }

    vector<int> datos_fila;
    int siguiente;
    int precio;
    int pasos;
    int min = INT_MAX;
    int len_fila;

    vector<int> rutas(flights.size(), INT_MAX);
   
    while(!fila.empty())
    {

        datos_fila = fila.front();
        fila.pop_front();

        siguiente = datos_fila[0];
        precio = datos_fila[1];
        pasos = datos_fila[2];

        if (siguiente == dst)
        {
            if (precio < min)
            {
                min = precio;
            }
        }
        else
        {
            if (pasos <= k)
            {
                for (auto& new_entry : grafo[siguiente])
                {
                    if (new_entry.second + precio < rutas[new_entry.first])
                    {
                        rutas[new_entry.first] = new_entry.second + precio;
                        //cout << "City > " << new_entry.first << " - Price: " << new_entry.second << " - Steps: " << pasos + 1<<endl;
                        fila.push_back({ new_entry.first, new_entry.second + precio, pasos + 1 });
                    }

                }
            }
        }

    }

    cout << "soy min: " << min<<endl;
    if (min == INT_MAX)
    { 
        cout << "-1" << endl; 
    }
    else
    { 
        cout << min << endl;
    }
    

}
