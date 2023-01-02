class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isFirstCap=false;
        bool allShouldBeCap =false;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(i==0 && isupper(c)){
                isFirstCap=true;
            }else if(i==1 && isupper(c)){
                if(isFirstCap){
                    allShouldBeCap =true;
                }else{
                    return false;
                }
            }else if(i!=0 && i!=1){
                if(isupper(c)){
                    if(!allShouldBeCap){
                        return false;
                    }
                }else{
                    if(allShouldBeCap){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};