#include <vector>
using namespace std;

class ThrowTheBall{
public:
	int timesThrown(int N, int M, int L){
		vector<int> pCounter;
		// initialize vector
		for (int i = 0; i < N; i++){
			pCounter.push_back(0);
		}

		pCounter[0] = 1;
		int i = 0;
		int thrown = 0;

		// pass ball around the table
		while (pCounter[i] != M){
			if (pCounter[i] % 2 == 0){
				i += L;
				if (i >= N){
					i = i % N;
				}
			} else if (pCounter[i] % 2 == 1){
				i -= L;
				if (i < 0){
					i = N + i;
				}
			}
			pCounter[i]++;
			thrown++;
		}
		return thrown;
	}
};