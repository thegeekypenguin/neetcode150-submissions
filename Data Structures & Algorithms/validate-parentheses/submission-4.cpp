class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(char it: s){
            if(it == '(' or it == '{' or it == '[')
                st.push(it);
            
            else{
                if(st.empty()) return false;
                else if(it == ')' and st.top() == '(') st.pop();
                else if(it == '}' and st.top() == '{') st.pop();
                else if(it == ']' and st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
