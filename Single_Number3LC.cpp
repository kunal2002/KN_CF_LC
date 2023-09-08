class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        XOR &= -XOR; // Last set bit from left(MSB) and first set bit from right(MSB)
        vector<int> res = {0, 0};
        for(int x: nums)
        {
            if((x & XOR) == 0) //unset bit
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};
