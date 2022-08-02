class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // at every iteration smallest number will make all its duplicates to zero
        // and at next, next smallest number will make all it duplicates to zero
        // so operations required will be unique number of elements in the array
        unordered_set<int> s(nums.begin(),nums.end());
        int countOfZeros = s.count(0);
        return s.size() - countOfZeros; 
        
    }
};