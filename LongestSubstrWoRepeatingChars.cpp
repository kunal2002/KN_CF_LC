#include <bits/stdc++.h> 
//Classic Sliding window without while optimized
int uniqueSubstrings(string input)
{
    //Write your code here
    map<int,int> mp;
    int n = input.size();
    int best = 1, s = 0, e = 0;
    while(e < n)
    {
        if(mp[input[e]])
            s = max(s, mp[input[e]] + 1);
        mp[input[e]] = e;
        best = max(best, e - s + 1);
        e++;
    }
    return best;
}
