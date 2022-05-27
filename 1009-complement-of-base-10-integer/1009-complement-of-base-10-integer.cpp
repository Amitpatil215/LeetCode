class Solution {
public:
    int bitwiseComplement(int n) {
       long long mask=1;
        while(n>mask){
            mask=(mask<<1) | 1;
        }
        return (n ^ mask);
    }
};