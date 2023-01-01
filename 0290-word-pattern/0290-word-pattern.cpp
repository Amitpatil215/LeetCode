class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        set<string>occurance;
        int k=0;
        string str="";
        for(int i=0;i<pattern.size();i++){
            char c = pattern[i];
            while(k<s.size() && !isspace(s[k])){
                str+=s[k];
                cout<<str<<endl;
                k++;
            }
            
            // check if word alredy exist?
            if(m.find(c)!=m.end() && m[c]!=str){
                return false;
            }else if(m.find(c)==m.end()){
                if(occurance.find(str)!=occurance.end() || str==""){
                    return false;
                }
                cout<<"added new"<<endl;
                m[c]=str;
                occurance.insert(str);
            }
            //move to next word
            k++;
            str="";
        }
        
        if(k<s.size()){
            return false;
        }
        return true;
    }
};