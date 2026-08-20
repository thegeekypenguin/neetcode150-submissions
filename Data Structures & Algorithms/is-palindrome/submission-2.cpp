class Solution {
public:
    bool isPalindrome(string s) {
       string temp = "";
       for(auto ch: s){
        if(isalnum(ch))
            temp.push_back(tolower(ch));
       } 

       int i=0, j=temp.size()-1;

       while (i<j){
        if(temp[i] == temp[j]){
            i++; j--;
            continue;
        }
        return false;
       }
       return true;
    }
};
