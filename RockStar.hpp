#include <bits/stdc++.h>
using namespace std;

class RockStar{
public:
    int getNumSongs(int ff, int fs, int sf, int ss){
        if (ff == 0 && fs == 0 && sf == 0 && ss == 0){
            return 0;
        }

        if (ff != 0 && fs == 0){
            return ff;
        }

        if (ss != 0 && fs == 0 && sf == 0){
            return ss;
        }

        if (ff == 0 && ss == 0){
            if (fs != 0 && sf == 0 || fs == 0 && sf != 0){
                return 1;
            }
        }

        if (ff != 0 && ss == 0 || ff == 0 && ss != 0){
            if (fs != 0 && sf == 0 || fs == 0 && sf != 0){
                return ff + ss + 1;
            }
        }
        
        if (fs > sf){
            return ff+(sf*2)+1+ss;
        }
        if (fs <= sf){
            return ff+(fs*2)+ss;
        }
    }
};