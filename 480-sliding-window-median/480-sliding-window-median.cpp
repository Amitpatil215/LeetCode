class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>ms;
        vector<double> ans;
        
        for(int i=0;i<nums.size()-k+1;i++){
            
            if(ms.size()==0){
            //insert
            int x=k;
            while(x--){
                int e=nums[x+i];
                ms.insert(e);
                cout<<e<<" ";
            }
            }else{
                ms.insert(nums[i+k-1]);
                cout<<nums[i+k-1]<<" ";
            }
            cout<<endl;
            // calcualte median
            double med;
            if(k%2!=0){
                int index=(k)/2;
                med=*next(ms.begin(),index);
                cout<<"from odd"<<index<<endl;
            }else{
                int index=k/2;
                double med1=*next(ms.begin(),index);
                double med2=*next(ms.begin(),index-1);
                med=(med1+med2)*0.5;
            }
            cout<<"med is "<<med<<endl;
            ans.push_back(med);
            // to slide window remove first element
            ms.erase(ms.find(nums[i]));
        }
        return ans;
        
    }
};