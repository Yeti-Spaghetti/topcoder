#include <string>
#include <vector>
using namespace std;

class AzimuthMonitoring{
public:
	int getAzimuth(vector<string> instructions){
		int direction = 0;
		int i = 0;
		
		for (int i = 0; i < instructions.size(); i++){
			if (instructions[i] == "LEFT"){
				direction -= 90;
			}
			if (instructions[i] == "RIGHT"){
				direction += 90;
			}
			if (instructions[i].find(" ") != string::npos){
				if (instructions[i] == "TURN AROUND"){
					direction += 180;
				} else {
					string tempString = instructions[i].substr(instructions[i].find(" ", 0)+1);
					int tempInt = stoi(tempString);
					if (instructions[i].find("RIGHT") != string::npos){
						direction += tempInt;
					} else if (instructions[i].find("LEFT") != string::npos){
						direction -= tempInt;
					}
				}	
			}
			if (direction >= 360){
				direction %= 360;
			}
			if (direction < 0){
				direction = 360 + direction;
			}
			if (instructions[i] == "HALT"){
				return direction;
			}
		}
		return direction;
	}
};