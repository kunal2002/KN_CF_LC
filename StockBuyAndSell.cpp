#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int dip = INT_MAX, maxprof = 0;
    for(int i = 0; i < n; i++)
    {
        if(prices[i] < dip)
        {
            dip = prices[i];
            continue;
        }
        maxprof = max(maxprof, prices[i] - dip);
    }
    return maxprof;
}
