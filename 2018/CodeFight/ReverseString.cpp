#include <bits/stdc++.h>
using namespace std;

// Reverse
// str_cat

string reverse(string str){
    string res = "";
    for(char x:str) res = x + res;
    return res; 
}

int findNextOpenPar(string str, int startIndex){
    for(int i=startIndex; i<str.length(); ++i){
        if (str[i] =='(') return i;
    }
    return -1;
}

int findGoodClosePar(string str, int startIndex){
    int cnt = 0;
    for(int i=startIndex; i<str.length(); ++i){
        if (str[i] == '(') cnt++;
        if (str[i] == ')') cnt--;
        if (cnt == 0) return i;
    }
    return -1;
}

void copy2str(string src, string &des, int l, int r){
    for(int i =l;i<=r;++i) des = des+src[i];
}

std::string reverseInParentheses(std::string str) {
    // cout<<str<<endl;
    string result = "";
    int i = 0;
    while(i < str.length()){
        int l = findNextOpenPar(str,i);
        if (l!=-1){
            int r = findGoodClosePar(str,l); // assumpt r != -1
            copy2str(str,result,i,l-1);
            string temp = "";
            copy2str(str,temp,l+1,r-1);
            result = result + reverse(reverseInParentheses(temp));
            i = r+1;
        }else{
            copy2str(str,result,i,str.length()-1);
            break;
        }
    }

    return result;
}


int main(){
    string x = "foo(bar(baz))blim";
    cout<<reverseInParentheses(x);
    return 0;
}