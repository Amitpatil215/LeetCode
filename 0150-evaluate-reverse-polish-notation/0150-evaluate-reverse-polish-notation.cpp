class Solution {
public:
    int ans=0;
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto x:tokens){
            if(x=="/" || x=="*" || x=="-" || x == "+"){
                long long a = st.top();
                st.pop();
                long long b= st.top();
                st.pop();
                long long int curr =0;
                if(x=="*"){
                    curr = a*b; 
                } else if(x=="+"){
                    curr = a+b;
                } else if(x=="-"){
                    curr = b-a;
                } else if(x=="/"){
                    curr = b/a;
                }

                st.push(curr);
                
            }else{
                st.push(stoi(x));
            }
        }
    return st.top();
    }
};