class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0, obtainable = 0;
        for(auto x : coins)
        {
            while(x > obtainable + 1)
            {
                obtainable += obtainable + 1;
                ans++;
                if(obtainable >= target)
                    return ans;
            }
            obtainable += x;
            if(obtainable >= target)
                return ans;
        }
        while(obtainable < target)
        {
            obtainable += obtainable + 1;
            ans++;
        }
        return ans;
    }
};
