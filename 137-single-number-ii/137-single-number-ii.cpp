class Solution {
public:
    void updateSum(vector<int> &sumArray, int x)
{
    for (int i = 0; i < 32; i++)
    {
        // extracting all the bits of x
        int i_thBit = x & (1 << i);
        if (i_thBit)
        {
            sumArray[i]++;
            if (sumArray[i])
            {
                // debug(sumArray[i], i);
            }
        }
    }
}

int noFromBits(vector<int> sumArray)
{
    int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num += (sumArray[i] * (1 << i));
        // debug(sumArray[i], num);
    }
    return num;
}
int solve(vector<int> v)
{
    // int n;
    // cin >> n;
    // vector<int> v(n + 1);
    vector<int> sumArray(32, 0);
    for (int i = 0; i < v.size(); i++)
    {
        // cin >> v[i];
        updateSum(sumArray, v[i]);
    }
    // get array of bits of uniqe number
    for (int i = 0; i < 32; i++)
    {
        sumArray[i] = sumArray[i] % 3;
    }
    // get decimal value
    int no = noFromBits(sumArray);
    return no;
}
    int singleNumber(vector<int>& nums) {
        return solve(nums);
    }
};