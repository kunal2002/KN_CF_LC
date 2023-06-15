#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    //Checking for every number if the previous number in seq exists then we'll check it at that time only ek baar mein
    unordered_set<int> us;
    for(int i = 0; i < n; i++)
        us.insert(arr[i]);
    int cnt = 1, best = 1;
    for(int i = 0; i < n; i++)
    {
        if(us.find(arr[i] - 1) != us.end())
            continue;
        else
        {
            int tmp = arr[i];
            int cnt = 1;
            while(us.find(tmp + 1) != us.end())
            {
                tmp += 1;
                cnt++;
            }
            best = max(best, cnt);
        }
    }   
    return best;
}
