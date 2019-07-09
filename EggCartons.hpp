using namespace std;

class EggCartons{
public:
	int minCartons(int n){
		// base case
		if (n < 6 || n % 2 == 1){
			return -1;
		}

		int repeat = n / 6;
		int carton6, carton8;
		if (n % 8 == 0){
			return n / 8;
		} else {
			carton6 = 1;
			carton8 = (n / 8);
		}
		for (int i = 0; i < repeat; i++){
			if ((8*carton8 + 6*carton6) != n){
				carton6++;
				carton8--;
			} else {
				return carton6 + carton8;
			}
		}
		return -1;
	}
};