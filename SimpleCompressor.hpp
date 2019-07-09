#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class SimpleCompressor
{
  public:
    string uncompress(string data)
    {
        for (int i = data.length() - 1; i >= 0; i--)
        {
            if (isdigit(data[i]))
            {
                int repeat = data[i] - '0';
                data.erase(data.begin() + i);

                // extract string to repeat
                string temp_string = data.substr(i);
                int brak_pos = temp_string.find(']');
                data.erase(brak_pos + i, 1);

                temp_string = temp_string.substr(0, brak_pos);
                
                // insert substring
                for (int j = 1; j < repeat; j++){
                    data.insert(i, temp_string);
                }
                
                data.erase(i-1, 1);
            }
        }
        return data;
    }
};