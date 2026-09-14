class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            // If token is an operator
            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/") {

                int x = st.top();
                st.pop();

                int y = st.top();
                st.pop();

                if (tokens[i] == "+") {
                    st.push(y + x);
                }
                else if (tokens[i] == "-") {
                    st.push(y - x);
                }
                else if (tokens[i] == "*") {
                    st.push(y * x);
                }
                else if (tokens[i] == "/") {
                    st.push(y / x);
                }
            }
            else {
                // Token is a number
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};