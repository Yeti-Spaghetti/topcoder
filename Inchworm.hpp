using namespace std;

class Inchworm{
public:
	int lunchtime(int branch, int rest, int leaf){
		int count = 1;
		int location = leaf;
		while (location <= branch){
			if (location % rest == 0){
				count++;
			}
			location += leaf;
		}
		return count;
	}
};