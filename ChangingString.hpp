#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class ChangingString{
public:
	int distance(string A, string B, int K){
		int iA, iB;
		vector<int> difference;
		for (int i = 0; i < A.length(); i++){
			iA = A[i];
			iB = B[i];
			int absoluteDifference = abs(iA - iB);
			difference.push_back(absoluteDifference);
		}

		int index = 0;
		int remainingSwaps = K;

		for (int i = 0; i < K; i++){
			int max = 0;
			for (int j = 0; j < A.length(); j++){
				if (difference[j] > max){
					max = difference[j];
					index = j;
				}
			}

			if (difference[index] != 0){
				difference[index] = 0;
				remainingSwaps--;
			}
		}

		int distance = 0;
		for (int i = 0; i < A.length(); i++){
			distance += difference[i];
		}
		return distance + remainingSwaps;
	}
};