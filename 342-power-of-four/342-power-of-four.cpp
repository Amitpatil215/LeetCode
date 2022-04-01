class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0){
            return false;
        }
        
        long long int odd_mask=1;
        for(int i=0;i<16;i++){
            odd_mask=(odd_mask<<2)|1;
        }
        long long int x=(n & n-1);
        if(x==0 && (n & odd_mask)!=0){
            return true;
        }else{
            return false;
        }
    }
};