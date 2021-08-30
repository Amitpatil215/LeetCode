class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        int s=0;
        int e=numbers.size()-1;
        
        while(s<=e){
          int sum=numbers[s]+numbers[e];
            
            if(sum==target){
                ans.push_back(s+1); // +1 cause array is 1 indexed based
                ans.push_back(e+1);                
                break;
            }else if(sum>target){
                e--;
            }else if(sum<target){
                s++;
            }
        }
        
        return ans;
    }
};