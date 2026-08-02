// word_Ladder_A-Z.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <print>
#include <unordered_set>
#include <vector>

using namespace std;
int search_one_queue(unordered_set<string>& wordList, const string & beginWord, const string & endWord)
{
    int altura = 1;
    deque<string> fila;
    unordered_set<string> view;
    fila.push_back(beginWord);
    int l_beginWord= beginWord.size();
    string word;
    char save_char;

    while(!fila.empty())
    {
        altura += 1;
        const int l_fila = fila.size();
        for(int _=0; _ < l_fila; _++)
        {
            word = fila.front();
            fila.pop_front();
            
          
            for (int i = 0; i < l_beginWord; i++)
            {
                save_char = word[i];
                for (char char_ = 97; char_ <= 122; char_++)
                {
                    word[i] = char_;

                    if(wordList.contains(word))
                    {
                        if(word == endWord)
                        {
                            return altura;
                        }
                        fila.push_back(word);
                        wordList.erase(word);
                    }

                }
                word[i] = save_char;
            }
            

        }
        
    }
    return 0;
}


int search(unordered_set<string>& wordList, const string & beginWord, const string & endWord)
{
    int altura = 1;
    unordered_set<string> fila;
    unordered_set<string> fila_2;
    int l_fila;
    int l_fila_2;

    unordered_set<string> view;


    fila.insert(beginWord);
    fila_2.insert(endWord);

    int l_beginWord= beginWord.size();
    string word;
    char save_char;

    while(!fila.empty() && !fila_2.empty())
    {
        altura += 1;
        unordered_set<string> save;

        if (fila_2.size() <= fila.size())
        {
          
            while (! fila.empty() )
            {
                auto it = fila.begin();
                word = *it;
                fila.erase(it);


                for (int i = 0; i < l_beginWord; i++)
                {
                    save_char = word[i];
                    for (char char_ = 97; char_ <= 122; char_++)
                    {
                        word[i] = char_;

                        if (wordList.contains(word))
                        {
                            if (fila_2.contains(word))
                            {
                                return altura;
                            }
                            save.insert(word);
                            wordList.erase(word);
                        }

                    }
                    word[i] = save_char;
                }


            }
            fila = move(save);

        }else
        {
            while (!fila_2.empty())
            {
                auto it = fila_2.begin();
                word = *it;
                fila_2.erase(it);


                for (int i = 0; i < l_beginWord; i++)
                {
                    save_char = word[i];
                    for (char char_ = 97; char_ <= 122; char_++)
                    {
                        word[i] = char_;

                        if (wordList.contains(word))
                        {
                            if (fila.contains(word))
                            {
                                return altura;
                            }
                            save.insert(word);
                            wordList.erase(word);
                        }

                    }
                    word[i] = save_char;
                }


            }
            fila_2 = move(save);
        }
        
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    unordered_set<string>  wordList_2(wordList.begin(), wordList.end());

    if (wordList_2.contains(endWord))
    {
        int result = search(wordList_2, beginWord, endWord);
        cout << result;
    }
    else
    {
        cout << 0;
    }

    

}
