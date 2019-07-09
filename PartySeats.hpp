#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class PartySeats{
public:
	vector<string> seating(vector<string> attendees){
		vector<string> boys;
		vector<string> girls;
		vector<string> seating;

		int size = attendees.size();
		string tempString;

		// initial numbers check
		if (attendees.size() <= 3 || attendees.size() % 2 != 0){
			return seating;
		}

		// strip gender and fill male and female vectors
		for (int i = 0; i < attendees.size(); i++){
			if (attendees[i].find("boy") != string::npos){
				tempString = attendees[i].substr(0, attendees[i].find("boy", 0)-1);
				boys.push_back(tempString);
			} else if (attendees[i].find("girl") != string::npos){
				tempString = attendees[i].substr(0, attendees[i].find("girl", 0)-1);
				girls.push_back(tempString);
			}
		}

		// check number of boys and girls will work
		int numOfBoys = boys.size();
		int numOfGirls = girls.size();
		if (numOfBoys < 2 || numOfGirls < 2 || numOfBoys != numOfGirls || numOfBoys % 2 != 0 || numOfGirls % 2 != 0){
			return seating;
		}

		sort(boys.begin(), boys.end());
		sort(girls.begin(), girls.end());

		// assign seating
		seating.push_back("HOST");
		for (int i = 0; i < size/4; i++){
			seating.push_back(girls[i]);
			seating.push_back(boys[i]);
		}

		seating.push_back("HOSTESS");
		for (int i = size/4; i < size/2; i++){
			seating.push_back(boys[i]);
			seating.push_back(girls[i]);
		}
	}
};