#include <string>
using namespace std;

class BlackAndRed{
public:
    bool subDeck(string newDeck){
        int red = 0;
        int blk = 0;
        for (int i = 0; i < newDeck.length(); i++){
            if (newDeck[i] == 'B'){
                blk++;
            } else {
                red++;
                if (red > blk){
                    return false;
                }
            }
        }
        return true;
    }

    int cut(string deck){
        int red = 0;
        int blk = 0;
        string split1, split2, newString;
        for (int i = 0; i < deck.length(); i++){
            if (deck[i] == 'B'){
                blk++;
            } else {
                red++;
                if (red > blk){
                    split1 = deck.substr(0, i+1);
                    split2 = deck.substr(i+1, deck.length());
                    newString = split2 + split1;
                    if (subDeck(newString)){
                        return i+1;
                    }
                }
            }
        }
        return 0;
    }
};