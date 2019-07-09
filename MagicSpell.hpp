#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MagicSpell{
public:
    string fixTheSpell(string spell){
        vector<char> chars;
        for (int i = 0; i < spell.length(); i++){
            if (spell[i] == 'A' || spell[i] == 'Z'){
                chars.push_back(spell[i]);
            }
        }
        
        /* for (int i = 0; i < chars.size(); i++){
            cout << chars[i];
        }
        cout << endl; */

        int j = chars.size();
        int k = 0;
        for (int i = 0; i < spell.length(); i++){
            if (spell[i] == 'A' || spell[i] == 'Z'){
                spell[i] = chars[j-1-k];
                k++;
            }
        }
        return spell;
    }
};