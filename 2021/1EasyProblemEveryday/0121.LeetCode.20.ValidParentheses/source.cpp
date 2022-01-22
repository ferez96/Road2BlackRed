#include <string>
#include <iostream>
#include <stack>

using namespace std;

const char* OPEN_BRACKETS = "({[";
const char* CLOSE_BRACKETS = ")}]";

class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i] == OPEN_BRACKETS[j]) {
                    brackets.push(j);                    
                } else if (s[i] == CLOSE_BRACKETS[j]) {
                    if (brackets.size() == 0) {
                        return false; // close bracket without open
                    } else {
                        if (brackets.top() != j) {
                            return false; // open bracket not match with close bracket
                        }
                        brackets.pop();
                    }                    
                }
            }
        }
        if (brackets.size() != 0) {
            return false; // open bracket remain
        }
        return true;
    }
};


int main(){
    cout << Solution().isValid("()") << endl;
    cout << Solution().isValid("{}") << endl;
    cout << Solution().isValid("[]") << endl;
    cout << Solution().isValid(")") << endl;
    cout << Solution().isValid("}") << endl;
    cout << Solution().isValid("]") << endl;
    cout << Solution().isValid("(())") << endl;
    cout << Solution().isValid("({[]})") << endl;
    cout << Solution().isValid("({[]}") << endl;
    cout << Solution().isValid("({[})") << endl;
    cout << Solution().isValid("([]})") << endl;
    return 0;
}