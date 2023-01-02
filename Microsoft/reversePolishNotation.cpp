class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int op1= st.top();
                st.pop();
                int op2= st.top();
                st.pop();
                if(tokens[i]=="+"){
                    op1= op2 + op1;
                }
                else if(tokens[i]=="-"){
                    op1= op2 - op1;
                }
                else if(tokens[i]=="*"){
                    op1= op2 * op1;
                }
                else if(tokens[i]=="/"){
                    op1= op2 / op1;
                }
                st.push(op1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};