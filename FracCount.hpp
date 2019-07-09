using namespace std;

class FracCount{
public:
    int position(int numer, int denom){
        double target = numer / (double)denom;
        int n = 1, d = 2;
        int pos = 1;

        while (target != n/(double)d){
            n++;
            if (n == d){
                n = 1;
                d++;
            }

            // check for previously seen fractions
            bool found = false;
            for (int i = 2; i <= d / 2; i++){
                if (n % i == 0 && d % i == 0){
                    found = true;
                }
            }

            // if not seen, increment counter (pos)
            if (!found){
                pos++;
            }
        }
        return pos;
    }
};