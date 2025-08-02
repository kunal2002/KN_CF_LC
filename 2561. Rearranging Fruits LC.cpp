class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp, mp1;
        int n = basket1.size();
        for(int i = 0; i < n; i++)
        {
            mp[basket1[i]]++;
            mp1[basket1[i]]++;
            mp[basket2[i]]++;
        }
        for(auto &x : mp)
        {
            if((x.second&1))
                return -1;
        }
        long long ans = 0;
        vector<pair<int,int>> take, give;
        for(auto &[fruit, tot_count] : mp)
        {
            int half = tot_count / 2, bkt1 = mp1[fruit];
            if(half == bkt1)
                continue;
            if(bkt1 > half)
                give.push_back({fruit, bkt1 - half});
            else
                take.push_back({fruit, half - bkt1});
        }
        sort(give.begin(), give.end());
        sort(take.begin(), take.end());
        int min_val = mp.begin()->first;
        
        int g_ptr = 0;
        int t_ptr = take.size() - 1;

        while (g_ptr < give.size() && t_ptr >= 0)
        {
            int g_fruit = give[g_ptr].first;
            int t_fruit = take[t_ptr].first;
            
            int swaps_to_do = min(give[g_ptr].second, take[t_ptr].second);
            
            long long direct_swap_cost = min((long long)g_fruit, (long long)t_fruit);
            // Use the cheapest fruit twice to deal, adding cheapest fruit's cost 2 times, 
            //like the transitive property in math kinda, using c to swap a and b, swap(a, c) then swap(c, b)
            long long cheapest_fruit_swap = 2LL * min_val;
            ans += (long long)swaps_to_do * min(direct_swap_cost, cheapest_fruit_swap);

            give[g_ptr].second -= swaps_to_do;
            take[t_ptr].second -= swaps_to_do;
            if(give[g_ptr].second == 0)
                g_ptr++;
            if(take[t_ptr].second == 0)
                t_ptr--;
        }
        return ans;
    }
};
