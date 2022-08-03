class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty()){
            st.insert({start,end-1});
            return true;
        }else{
            for(auto p:st){
                if((start >=p.first && start<=p.second) || (end-1>=p.first && end-1<=p.second)){
                    return false;
                }
                // for checking if existing interval is overlapped by new interval
                // e.g old -> 12-20 
                // book 10-30 this should return false
                if(p.first>start && p.second<end-1){
                    return false;
                }
            }
            st.insert({start,end-1});
            cout<<"pushed "<<start<<" "<<end-1;
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */