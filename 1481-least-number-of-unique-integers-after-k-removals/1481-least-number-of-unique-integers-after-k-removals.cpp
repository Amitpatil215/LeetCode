class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // element, <count,element>
        unordered_map<int,pair<int,int>>freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]={freq[arr[i]].first+1,arr[i]};
        }
        
        vector<pair<int,int>> v;
        for(auto m:freq){
            v.push_back(m.second);
        }
        sort(v.begin(),v.end());
        int copyk=k;
        int countx=0;
        int sizeReduced=0;
        for(auto e:v){
            int count=e.first;
            k=k-count;
            if(k>=0){
                sizeReduced++;
            }else{
                break;
            }
        }
        countx=v.size()-sizeReduced;
        cout<<"size"<<v.size()<<endl;
        cout<<"reduced size"<<sizeReduced<<endl;
        return countx;
    }
};