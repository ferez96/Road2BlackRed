const int r[8] = {0,1,1,0,1,0,0,1};
const int m[8] = {0,0,0,1,0,1,1,1};

class Solution {
private:
    string revertString(std::string origin) {
        std::string reverted = "";
        for ( int i = 1; i <= origin.length(); i++ ) {
            reverted += origin[origin.length() - i];
        }
        return reverted;
    }
    
public:
    string addBinary(string a, string b) {
        // Make sure a.length >= b.length
        if (a.length() < b.length()) return addBinary(b, a);
        
        // memorize
        int mem = 0;
        std::string result = "";
        for ( int i = 1; i <= b.length(); i++ ) {
            int idx = (a[a.length() - i] - '0')*4 + (b[b.length() - i] - '0')*2 + mem;
            result += (r[idx]==0?'0':'1');
            mem = m[idx];
        }
        for ( int i = b.length() + 1; i <= a.length(); i++ ) {
            int idx = (a[a.length() - i] - '0')*4 + mem;
            result = result + (r[idx]==0?'0':'1');
            mem = m[idx];
        }
        if (mem == 1) result += "1";
        
        return revertString(result);
    }
};