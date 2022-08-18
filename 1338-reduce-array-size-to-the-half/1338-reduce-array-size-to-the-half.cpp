class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<pair<int,int>>freq(m.begin(),m.end());
        sort(freq.begin(),freq.end(),[](pair<int,int>p1,pair<int,int>p2){
            return p1.second > p2.second;
        });
        int index=-1;
        int expectedLength=0;
        while(expectedLength<arr.size()/2){
            index++;
            expectedLength+=freq[index].second;
        }
        return index+1;
    }
};