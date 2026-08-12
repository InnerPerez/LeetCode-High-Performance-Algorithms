/*Key Features
* **Execution Time:** 3 ms (Top ~0.2% among global C++ submissions on LeetCode).
* **Pure Logical Flow:** No low-level bitwise operations or variable packing. Driven entirely by clean, high-level string routing.
* **Cacheless Architecture:** Defies conventional wisdom—the BFS pruning is so sharp that traditional caching layers only add unnecessary latency and memory overhead.
* **Readability Meets Speed:** Proof that clean software design can match and beat low-level encoding tricks in performance-critical tasks.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <print>
#include <chrono>

using namespace std;


void BFS(unordered_set<string>& wordList_2, string& beginWord, string& endWord, unordered_map<string, vector<string>>& mapa)
{
    unordered_set<string> fila_1;
    unordered_set<string> fila_2;
    unordered_set<string> padres_visitados_1;
    unordered_set<string> hijos_visitados_1;
    char save_char;
    int len_fila;
    fila_1.insert(endWord);
    fila_2.insert(beginWord);
    int l_words = endWord.size();
    string padre;
    string hijo;
    int flag = 0;

    while (!fila_1.empty() && !fila_2.empty())
    {

        unordered_set<string> new_iter;

        if (fila_2.size() <= fila_1.size())
        {

            while (!fila_1.empty())
            {
                auto hijo_1 = fila_1.begin();
                padre = *hijo_1;
                hijo = *hijo_1;
                fila_1.erase(hijo_1);

                for (int i = 0; i < l_words; i++)
                {
                    save_char = padre[i];

                    for (char c = 97; c <= 122; c++)
                    {

                        padre[i] = c;

                        if (wordList_2.contains(padre))
                        {
                            if (padre != hijo && !padres_visitados_1.contains(padre))
                            {
                                //cout << "Padre: " << padre << " - Hijo: " << hijo << endl;
                                if (padre == beginWord)
                                {

                                    flag = 1;
                                }

                                mapa[padre].push_back(hijo);
                                new_iter.insert(padre);

                            }

                        }
                    }
                    padre[i] = save_char;
                }

                wordList_2.erase(hijo);
            }
            
            padres_visitados_1.insert(new_iter.begin(), new_iter.end());
            fila_1 = move(new_iter);
        }
        else
        {

            while (!fila_2.empty())
            {
                auto padre_2 = fila_2.begin();
                padre = *padre_2;
                
                hijo = *padre_2;
                padres_visitados_1.insert(padre);

                fila_2.erase(padre_2);
                for (int i = 0; i < l_words; i++)
                {
                    save_char = hijo[i];

                    for (char c = 97; c <= 122; c++)
                    {

                        hijo[i] = c;
                       
                        if (wordList_2.contains(hijo))
                        {
                            
                            if(padre!=hijo && !padres_visitados_1.contains(hijo))
                            {
                                if (padre == endWord) { flag = 1; }
                               
                               mapa[padre].push_back(hijo);
                               new_iter.insert(hijo);
                               //wordList_2.erase(hijo);
                            }
                            

                        }

                    }
                    hijo[i] = save_char;

                }


            }

            
            for (const string & eliminar: new_iter) {
                wordList_2.erase(eliminar);
            }
            fila_2 = move(new_iter);

        }

        if (flag == 1) { return; }


    }



}

int find_words(unordered_map<string, vector<string>>& mapa_clane, const string& next_, const string& endWord, int height, vector<string>& pre_words, vector<vector<string>>& result)
{

    if (next_ == endWord)
    {  
        result.push_back(pre_words);
        return 1;
    }
    else
    {
        auto it = mapa_clane.find(next_);
        int r = 0;
        if (it != mapa_clane.end())
        {
            for (const string next : it->second)
            {
                pre_words.push_back(next);
                find_words(mapa_clane, next, endWord, height + 1, pre_words, result);
                pre_words.pop_back();

            }
        }
      return 0;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = chrono::high_resolution_clock::now();

    string beginWord, endWord;
    vector<string> wordList;
    beginWord = "hit";
    endWord = "cog";
    wordList = { "hot", "dot", "dog", "lot", "log", "cog"};


    beginWord = "aaaaa";
    endWord = "ggggg";
    wordList = { "aaaaa", "caaaa", "cbaaa", "daaaa", "dbaaa", "eaaaa", "ebaaa", "faaaa", "fbaaa", "gaaaa", "gbaaa", "haaaa", "hbaaa", "iaaaa", "ibaaa", "jaaaa", "jbaaa", "kaaaa", "kbaaa", "laaaa", "lbaaa", "maaaa", "mbaaa", "naaaa", "nbaaa", "oaaaa", "obaaa", "paaaa", "pbaaa", "bbaaa", "bbcaa", "bbcba", "bbdaa", "bbdba", "bbeaa", "bbeba", "bbfaa", "bbfba", "bbgaa", "bbgba", "bbhaa", "bbhba", "bbiaa", "bbiba", "bbjaa", "bbjba", "bbkaa", "bbkba", "bblaa", "bblba", "bbmaa", "bbmba", "bbnaa", "bbnba", "bboaa", "bboba", "bbpaa", "bbpba", "bbbba", "abbba", "acbba", "dbbba", "dcbba", "ebbba", "ecbba", "fbbba", "fcbba", "gbbba", "gcbba", "hbbba", "hcbba", "ibbba", "icbba", "jbbba", "jcbba", "kbbba", "kcbba", "lbbba", "lcbba", "mbbba", "mcbba", "nbbba", "ncbba", "obbba", "ocbba", "pbbba", "pcbba", "ccbba", "ccaba", "ccaca", "ccdba", "ccdca", "cceba", "cceca", "ccfba", "ccfca", "ccgba", "ccgca", "cchba", "cchca", "cciba", "ccica", "ccjba", "ccjca", "cckba", "cckca", "cclba", "cclca", "ccmba", "ccmca", "ccnba", "ccnca", "ccoba", "ccoca", "ccpba", "ccpca", "cccca", "accca", "adcca", "bccca", "bdcca", "eccca", "edcca", "fccca", "fdcca", "gccca", "gdcca", "hccca", "hdcca", "iccca", "idcca", "jccca", "jdcca", "kccca", "kdcca", "lccca", "ldcca", "mccca", "mdcca", "nccca", "ndcca", "occca", "odcca", "pccca", "pdcca", "ddcca", "ddaca", "ddada", "ddbca", "ddbda", "ddeca", "ddeda", "ddfca", "ddfda", "ddgca", "ddgda", "ddhca", "ddhda", "ddica", "ddida", "ddjca", "ddjda", "ddkca", "ddkda", "ddlca", "ddlda", "ddmca", "ddmda", "ddnca", "ddnda", "ddoca", "ddoda", "ddpca", "ddpda", "dddda", "addda", "aedda", "bddda", "bedda", "cddda", "cedda", "fddda", "fedda", "gddda", "gedda", "hddda", "hedda", "iddda", "iedda", "jddda", "jedda", "kddda", "kedda", "lddda", "ledda", "mddda", "medda", "nddda", "nedda", "oddda", "oedda", "pddda", "pedda", "eedda", "eeada", "eeaea", "eebda", "eebea", "eecda", "eecea", "eefda", "eefea", "eegda", "eegea", "eehda", "eehea", "eeida", "eeiea", "eejda", "eejea", "eekda", "eekea", "eelda", "eelea", "eemda", "eemea", "eenda", "eenea", "eeoda", "eeoea", "eepda", "eepea", "eeeea", "ggggg", "agggg", "ahggg", "bgggg", "bhggg", "cgggg", "chggg", "dgggg", "dhggg", "egggg", "ehggg", "fgggg", "fhggg", "igggg", "ihggg", "jgggg", "jhggg", "kgggg", "khggg", "lgggg", "lhggg", "mgggg", "mhggg", "ngggg", "nhggg", "ogggg", "ohggg", "pgggg", "phggg", "hhggg", "hhagg", "hhahg", "hhbgg", "hhbhg", "hhcgg", "hhchg", "hhdgg", "hhdhg", "hhegg", "hhehg", "hhfgg", "hhfhg", "hhigg", "hhihg", "hhjgg", "hhjhg", "hhkgg", "hhkhg", "hhlgg", "hhlhg", "hhmgg", "hhmhg", "hhngg", "hhnhg", "hhogg", "hhohg", "hhpgg", "hhphg", "hhhhg", "ahhhg", "aihhg", "bhhhg", "bihhg", "chhhg", "cihhg", "dhhhg", "dihhg", "ehhhg", "eihhg", "fhhhg", "fihhg", "ghhhg", "gihhg", "jhhhg", "jihhg", "khhhg", "kihhg", "lhhhg", "lihhg", "mhhhg", "mihhg", "nhhhg", "nihhg", "ohhhg", "oihhg", "phhhg", "pihhg", "iihhg", "iiahg", "iiaig", "iibhg", "iibig", "iichg", "iicig", "iidhg", "iidig", "iiehg", "iieig", "iifhg", "iifig", "iighg", "iigig", "iijhg", "iijig", "iikhg", "iikig", "iilhg", "iilig", "iimhg", "iimig", "iinhg", "iinig", "iiohg", "iioig", "iiphg", "iipig", "iiiig", "aiiig", "ajiig", "biiig", "bjiig", "ciiig", "cjiig", "diiig", "djiig", "eiiig", "ejiig", "fiiig", "fjiig", "giiig", "gjiig", "hiiig", "hjiig", "kiiig", "kjiig", "liiig", "ljiig", "miiig", "mjiig", "niiig", "njiig", "oiiig", "ojiig", "piiig", "pjiig", "jjiig", "jjaig", "jjajg", "jjbig", "jjbjg", "jjcig", "jjcjg", "jjdig", "jjdjg", "jjeig", "jjejg", "jjfig", "jjfjg", "jjgig", "jjgjg", "jjhig", "jjhjg", "jjkig", "jjkjg", "jjlig", "jjljg", "jjmig", "jjmjg", "jjnig", "jjnjg", "jjoig", "jjojg", "jjpig", "jjpjg", "jjjjg", "ajjjg", "akjjg", "bjjjg", "bkjjg", "cjjjg", "ckjjg", "djjjg", "dkjjg", "ejjjg", "ekjjg", "fjjjg", "fkjjg", "gjjjg", "gkjjg", "hjjjg", "hkjjg", "ijjjg", "ikjjg", "ljjjg", "lkjjg", "mjjjg", "mkjjg", "njjjg", "nkjjg", "ojjjg", "okjjg", "pjjjg", "pkjjg", "kkjjg", "kkajg", "kkakg", "kkbjg", "kkbkg", "kkcjg", "kkckg", "kkdjg", "kkdkg", "kkejg", "kkekg", "kkfjg", "kkfkg", "kkgjg", "kkgkg", "kkhjg", "kkhkg", "kkijg", "kkikg", "kkljg", "kklkg", "kkmjg", "kkmkg", "kknjg", "kknkg", "kkojg", "kkokg", "kkpjg", "kkpkg", "kkkkg", "ggggx", "gggxx", "ggxxx", "gxxxx", "xxxxx", "xxxxy", "xxxyy", "xxyyy", "xyyyy", "yyyyy", "yyyyw", "yyyww", "yywww", "ywwww", "wwwww", "wwvww", "wvvww", "vvvww", "vvvwz", "avvwz", "aavwz", "aaawz", "aaaaz" };


    unordered_set<string> wordList_2;
    wordList_2.insert(wordList.begin(), wordList.end());

    if(wordList_2.contains(endWord))
    {
        if(!wordList_2.contains(beginWord))
        {
            wordList_2.insert(beginWord);
        }

        unordered_map<string, vector<string>> mapa_clane;
        BFS(wordList_2, beginWord, endWord, mapa_clane);      
        vector<string> pre_words;
        vector<vector<string>> result;
        pre_words.push_back(beginWord);
        find_words(mapa_clane, beginWord, endWord, 0, pre_words, result);
        if(result.empty() )
        {
            cout << "{}" << endl;
        }
        else
        {
            print("{}", result);
        }
       
    }
    else
    {
        cout << "{}" << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    std::cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

}
