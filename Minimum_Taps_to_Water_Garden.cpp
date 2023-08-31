class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini = 0, maxi = 0, ans = 0, ind = 0;
        while(maxi < n)
        {
            for(int i = ind; i < n + 1; i++)
            {
                if((i - ranges[i]) <= mini && (i + ranges[i]) > maxi)
                {
                    maxi = i + ranges[i];
                    ind = i;
                } // increasing the max range and ensuring the 
                // lower bound of the range is less than or equal to prev used range
            }
            ans++;
            if(mini == maxi)
                return -1;
            mini = maxi;
        }
        return ans;
    }
};
