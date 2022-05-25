class para{
  public:
    string str;
    int openCount=0;
    int closeCount=0;
    
    para(string s,int oc,int cc){
        this->str=s;
        this->openCount=oc;
        this->closeCount=cc;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        queue<para> q;
        q.push({"",0,0});
        
        while(!q.empty()){
            para paraStr=q.front();
            q.pop();
            
            if(paraStr.openCount ==n && paraStr.closeCount==n){
                ans.push_back(paraStr.str);
            }else{
                if(paraStr.openCount < n){
                
                    q.push({paraStr.str+"(", paraStr.openCount+1, paraStr.closeCount});
                }
                if(paraStr.openCount > paraStr.closeCount){
                     q.push({paraStr.str+")", paraStr.openCount, paraStr.closeCount+1});
                }
            }
        }
        return ans;
    }
};