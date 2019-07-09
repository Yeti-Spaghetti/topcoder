#include <bits/stdc++.h>
using namespace std;

class LotteryTicket{
public:
    string buy(int price, int b1, int b2, int b3, int b4){
        vector<int> notes = {b1, b2, b3, b4};
        sort(notes.rbegin(), notes.rend());
        bool noChange = false;
        
        for (int i = 0; i < 4; i++){
            if (price == notes[i]){
                noChange = true;
            }
        }

        for (int i = 0; i < 4; i++){
            int tempPrice1 = price;
            if (notes[i] <= tempPrice1){
                tempPrice1 -= notes[i];
            }

            if (tempPrice1 == 0){
                return "POSSIBLE";
            }

            for (int j = i+1; j < 4; j++){
                int tempPrice2 = tempPrice1;
                if (notes[j] <= tempPrice2){
                    tempPrice2 -= notes[j];
                }

                if (tempPrice2 == 0){
                    return "POSSIBLE";
                }

                for (int k = j+1; k < 4; k++){
                    if (notes[k] <= tempPrice2){
                        tempPrice2 -= notes[k];
                    }
                    
                    if (tempPrice2 == 0){
                        return "POSSIBLE";
                    }
                }
            }
        }

        return "IMPOSSIBLE";
    }
};