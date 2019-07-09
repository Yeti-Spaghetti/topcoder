#include <cmath>	// pow
#include <string>	// string
#include <vector>	//vector
using namespace std;

class MooingCows{
public:
	int dissatisfaction(vector<string> farmland){
		int minDissatisfaction = numeric_limits<int>::max();
		for (int x = 0; x < farmland.size(); x++){
			for (int y = 0; y < farmland[x].length(); y++){
				if (farmland[x][y] == 'C'){
					// run through array again and look for other Cows
					int newDissatisfaction = 0;
					for (int i = 0; i < farmland.size(); i++){
						for (int j = 0; j < farmland[i].length(); j++){
							if (i == x && j == y){
								// do nothing
							} else if (farmland[i][j] == 'C'){
								newDissatisfaction += pow((x-i),2) + pow((y-j),2);
							}
						}
					}
					if (newDissatisfaction < minDissatisfaction){
						minDissatisfaction = newDissatisfaction;
					}
				}
			}
		}
		cout << minDissatisfaction << endl;
		return minDissatisfaction;
	}
};




