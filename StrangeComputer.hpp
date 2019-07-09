using namespace std;

class StrangeComputer{
public:
    int setMemory(string mem){
        // initialize computer memory
        string compMem;
        compMem.append(mem.length(), '0');
        
        if (compMem == mem){
            return 0;
        }

        int count = 0, pos = 0;
        char bit = '1';
        while (compMem != mem){
            for (int i = pos; i < mem.length(); i++){
                if (mem[i] == bit){
                    pos = i;
                    for (int j = pos; j < mem.length(); j++){
                        compMem[j] = bit;
                    }
                    if (bit == '1'){
                        bit = '0';
                    } else {
                        bit = '1';
                    }
                    count++;
                }
            }
        }
        return count;
    }
};