#include <string>
using namespace std;

class StreetParking{
public:
	int freeParks(string street){
		int count = street.length();
		cout << "String: " << street << "\n";

		for (int i = 0; i < street.length(); i++){
			if (street[i] == 'B'){
				count--;
				if (street[i-1] == '-'){
					count--;
				}
				if (street[i-2] == '-'){	
					count--;
				}
				if (street[i-1] == 'S' && street[i-2] == '-'){
					count++;
				}
				if (street[i-2] == 'S' && street[i-1] == '-'){
					count++;
				}
				if (street[i-3] == 'S' && street[i-2] == '-' && street[i-1] == '-'){
					count++;
				}
				if (street[i-3] == 'S' && street[i-2] == '-' && street[i-1] == 'D'){
					count++;
				}
				if (street[i-1] == 'B' && street[i-2] == '-'){
					count++;
				}
			}

			if (street[i] == 'S'){
				count--;
				if (street[i-1] == '-'){
					count--;
				}
				if (street[i+1] == '-'){
					count--;
				}
				if (street[i-2] == 'S' && street[i-1] == '-'){
					count++;
				}
			}

			if (street[i] == 'D'){
				count--;
			}
		}
		return count;
	}
};