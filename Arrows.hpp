#include <string>
using namespace std;

class Arrows{
public:
int longestArrow(string s){
	int tempLongest = -1;
	int longest = -1;
	char arrowType;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '<'){
			tempLongest = 1;
			if (s[i+1] == '-'){
				arrowType = s[i+1];
			} else if (s[i+1] == '='){
				arrowType = s[i+1];
			}
		}
		if (s[i] == '-' && arrowType == s[i]){
			tempLongest++;
		}
		if (s[i] == '=' && arrowType == s[i]){
			tempLongest++;
		}
		if (tempLongest > longest){
			longest = tempLongest;
		}
		if (s[i] == '>' || s[i+1] != arrowType){
			tempLongest = -1;
			arrowType = '\0';
		}
	}
	cout << longest << endl;

	arrowType = '\0';
	for (int i = s.length()-1; i >= 0; i--){
		if (s[i] == '>'){
			tempLongest = 1;
			if (s[i-1] == '-'){
				arrowType = s[i-1];
			} else if (s[i-1] == '='){
				arrowType = s[i-1];
			}
		}
		if (s[i] == '-' && arrowType == s[i]){
			tempLongest++;
		}
		if (s[i] == '=' && arrowType == s[i]){
			tempLongest++;
		}
		if (tempLongest > longest){
			longest = tempLongest;
		}
		if (s[i] == '<' || s[i-1] != arrowType){
			tempLongest = -1;
			arrowType = '\0';
		}
	}
	return longest;
}
};