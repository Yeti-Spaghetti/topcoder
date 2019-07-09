#include <string>
#include <vector>
using namespace std;

class SquareOfDigits{
public:
    int getMax(vector<string> data){
        int maxDistance = 0;
        int distance = 0;
        bool found = false;
        for (int i = 0; i < data.size(); i++){
            for (int j = 0; j < data[i].length(); j++){
                for (int k = j+1; k < data[i].length(); k++){
                    if (data[i][j] == data[i][k]){
                        distance = k-j;
                        if ((i+distance) < data.size() && data[i][j] == data[i+distance][j]){
                            if (data[i][j] == data[i+distance][j+distance]){
                                found = true;
                                if (distance > maxDistance){
                                    maxDistance = distance;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (found){
            return (maxDistance+1)*(maxDistance+1);
        }
        return 1;
    }
};