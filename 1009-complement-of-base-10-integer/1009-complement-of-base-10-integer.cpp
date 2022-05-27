class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        long long mask=1;
        long long sum=0;
        long long i=0;
        while(n!=0){
            bool isSet=n&mask;
            if(!isSet){
                sum+=1 * (1<<i);
            }
            i++;
            n=n>>1;
        }
        return sum;
    }
};