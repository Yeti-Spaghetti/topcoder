#include <bits/stdc++.h>
using namespace std;

class RGBStreet{  
public:
    int estimateCost(vector<string> houses){
        //vector<int> red, green, blue;
        vector<int> h1, h2, h3;
        int size = houses.size();
        int array[size][3];
        
        // split colours into their respective vectors
        for (int i = 0; i < houses.size(); i++){
            int counter = 0;
            string str_colour = "";
            houses[i] += " ";
            for (int j = 0; j < houses[i].length(); j++){
                if (houses[i][j] == ' '){
                    int int_colour = stoi(str_colour);
                    array[i][counter] = int_colour;
                    str_colour = "";
                    counter++;
                    j++;
                }
                str_colour += houses[i][j];
            }
        }

        int min1_val = INT_MAX, min2_val = INT_MAX;
        int min1_ind = -1, min2_ind;

        // find 2 minimum values and respective index in first house
        for (int i = 0; i < 3; i++){
            if (array[0][i] < min1_val){
                min1_val = array[0][i];
                min1_ind = i;
            }
        }
        for (int i = 0; i < 3; i++){
            if (min1_ind != i && array[0][i] < min2_val){
                min2_val = array[0][i];
            }
        }
        
        // add mins to next row
        for (int i = 1; i < size; i++){
            for (int j = 0; j < 3; j++){
                if (min1_ind == j){
                    array[i][j] += min2_val;
                } else {
                    array[i][j] += min1_val;
                }
            }

            // search for new smallest mins
            min1_val = INT_MAX, min2_val = INT_MAX;
            for (int j = 0; j < 3; j++){
                if (array[i][j] < min1_val){
                    min1_val = array[i][j];
                    min1_ind = j;
                }
            }
            //search for new second smallest min
            for (int j = 0; j < 3; j++){
                if (min1_ind != j && array[i][j] < min2_val){
                    min2_val = array[i][j];
                }
            }
        }
        return min1_val;
    }
};