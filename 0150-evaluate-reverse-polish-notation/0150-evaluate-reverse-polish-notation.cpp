class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int right = st.top(); st.pop();
                int left  = st.top(); st.pop();
                
                int result;
                if (tok == "+")      result = left + right;
                else if (tok == "-") result = left - right;
                else if (tok == "*") result = left * right;
                else  result = left / right; 
                
                st.push(result);
            } else {
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};
