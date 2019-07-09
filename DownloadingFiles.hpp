#include <algorithm>	// find
#include <limits>		// numeric_limits
#include <string>		// string, stoi, substr
#include <vector>
using namespace std;

class DownloadingFiles{
public:
	double actualTime(vector<string> tasks){
		int size = tasks.size();
		vector<int> speeds;
		vector<double> timeLeft;

		// push values into respective vector
		int tempSpeed, tempTime;
		for (int i = 0; i < size; i++){
			tempSpeed = stoi(tasks[i].substr(0, tasks[i].find(" ", 0)));
			tempTime = stoi(tasks[i].substr(tasks[i].find(" ", 0)+1));
			//cout << tempTime << endl;
			speeds.push_back(tempSpeed);
			timeLeft.push_back(tempTime);
		}

		int index, oldSpeed;
		int addSpeed = 0;
		double minimumTime;
		double totalTime = 0;
		
		for (int j = 0; j < size; j++){
			// find minimmum time left
			minimumTime = numeric_limits<int>::max();
			for (int i = 0; i < size; i++){
				if (timeLeft[i] < minimumTime && timeLeft[i] > 0){
					minimumTime = timeLeft[i];
				}
			}
			totalTime += minimumTime;

			// deduct minimum time left from every time
			for (int i = 0; i < size; i++){
				timeLeft[i] -= minimumTime;
					if (timeLeft[i] == 0){
						addSpeed += speeds[i];
					}
					
			}
			cout << addSpeed << endl;

			// find new minimum time left
			minimumTime = numeric_limits<int>::max();
			for (int i = 0; i < size; i++){
				if (timeLeft[i] < minimumTime && timeLeft[i] > 0){
					minimumTime = timeLeft[i];
					index = i;
				}
			}

			// update speeds
			oldSpeed = speeds[index];
			
			if (minimumTime == numeric_limits<int>::max()){
				return totalTime;
			}

			// calculate need timeLeft
			timeLeft[index] = timeLeft[index] * oldSpeed/(oldSpeed + addSpeed);
		}
		return totalTime;
	}
};