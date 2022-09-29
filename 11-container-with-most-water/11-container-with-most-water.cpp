class Solution {
public:
    int maxArea(vector<int>& height) {
            int end =height.size()-1;
    int start=0;
    int water=0;
   
    vector<int>v{};
    while(start<end){
         int difference= abs(start-end);
        
        if(height[start]<height[end]){
            water=height[start]*difference;
            v.push_back(water);
            start++;
            
        }
         else{
            water=height[end]*difference;
            v.push_back(water);
            end--;
            
    }
        
    }
    int ans=v[0];
    for(int i:v)
    
    ans=max(ans ,i);
    return ans;
    
    
    
    }
};