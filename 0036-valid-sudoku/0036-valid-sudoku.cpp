class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for columns
        multiset<char>s;
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(s.find(board[i][j])==s.end()){
                    if(board[i][j]!='.')s.insert(board[i][j]);
                }else{
                    
                    return false;
                }
            }
        }
        
        // for rows
        for(int i=0;i<9;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(s.find(board[j][i])==s.end()){
                    if(board[j][i]!='.') s.insert(board[j][i]);
                }else{
                                        
                    return false;
                }
            }
        }
        // for a grid
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                cout<<"start at"<<i<<" "<<j<<endl;
                //starting point of each grid
                s.clear();
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        cout<<i+k<<j+l<<" ";
                        if(s.find(board[i+k][l+j])==s.end()){
                            if(board[i+k][l+j]!='.'){
                                
                                s.insert(board[i+k][l+j]);}        
                        }else{
                            return false;
                        }
                    }
                    
                }
                cout<<endl;
            }
        }
        return true;
    }
};