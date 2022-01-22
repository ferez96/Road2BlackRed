#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int low, high;
        low = 0;
        high = 1000000007;
        for (int i = 0; i < strs.size(); i++) {
            if (high > strs[i].length()) {
                high = strs[i].length();
            }
        }

        while (high > low) {
            int mid = (high + low +1)/2; // ceil
            if (check_common_prefix(strs, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        if (high == low) {
            return strs[0].substr(0, high);
        } else {
            return "";
        }
    }

    // make sure that length < min(strs[i].length())
    bool check_common_prefix(vector<string> const &strs, int length) {        
        string prefix = strs[0].substr(0, length);
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i].substr(0, length);
            if (tmp.compare(prefix) != 0) return false;
        }
        return true;
    }
};