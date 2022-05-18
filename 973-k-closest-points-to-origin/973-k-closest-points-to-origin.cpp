class Compare{
    long long dist(vector<int>v){
        int a=v[0];
        int b=v[1];
        return (a*a)+(b*b);
    }
    
    public:
    bool operator()(vector<int>v1,vector<int>v2){
        return dist(v1)<dist(v2);
    }
};



class Solution {
public:
    long long dist(vector<int>v){
        int a=v[0];
        int b=v[1];
        return (a*a)+(b*b);
    }
        
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        vector<vector<int>> ans;
        
        for(int i=0;i<k;i++){
            pq.push(points[i]);
        }

        for(int i=k;i<points.size();i++){
            cout<<points[i][0]<<" "<<points[i][1]<<"->"<<dist(points[i])<<" ** "<<pq.top()[0]<<" "<<pq.top()[1]<<"->"<<dist(pq.top())<<endl;
            if(dist(points[i]) < dist(pq.top())){
                pq.pop();
                pq.push(points[i]);
            }
        }
        while(pq.size()!=0){
            ans.push_back(pq.top());
            pq.pop();
        }
      
        return ans;
    }
};