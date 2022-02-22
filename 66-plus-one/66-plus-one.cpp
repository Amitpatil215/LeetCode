class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=(int)digits.size();
        
        int carry=0;
        vector<int> ans;
        cout<<"hello";
        for(int i=size-1;i>=0;i--){
            cout<<"loop"<<endl;
            int rightDigit=digits[i];
            int newSum=0;
            if(i==size-1){
                newSum+=1;
            }
             newSum+=rightDigit + carry;
            cout<<newSum<<endl;
            if(newSum>9){
                carry=1;
                ans.push_back(0);
            }else{
                ans.push_back(newSum);
                carry=0;
            }
            
        }
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};