class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        int len =str.size();
        
        for(int i=0; i<len; i++){
            if(s.empty()){
                s.push(str[i]);
                
            }else{
                if(s.top()=='(' && str[i]==')'){
                    s.pop();
                }else if(s.top()=='[' && str[i]==']'){
                    s.pop();
                }else if(s.top()=='{' && str[i]=='}'){
                    s.pop();
                }else{
                    s.push(str[i]);   
                }          
            }
            
        }
        
        if(s.empty()){
            return true;
        }else{
            return false;
        }
    }
};