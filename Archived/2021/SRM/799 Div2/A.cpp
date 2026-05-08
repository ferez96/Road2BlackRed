#include <bitset/stdc++.h>
using namespace std;

class CoolPairsEasy{
public:
    int count(vector<string> fn, vector<string> ln){
        int result = 0;
        for(int i=0; i<n; i++){
            result += name_count[ln[i]];
        }
        return result;
    }
}