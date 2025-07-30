class Solution {
public:
    long long numOfSubsequences(string s) {
        long long cntL = 0, cntLC = 0, cntLCT = 0;
        int n = s.size();
        // the total count of LCT without inserting any character is cntLCT
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'L') cntL++;
            else if(s[i] == 'C') cntLC += cntL;
            else if(s[i] == 'T') cntLCT += cntLC;
        }
        vector<long long> suffT(n + 1, 0), suffCT(n + 1, 0);
        for(int i = n - 1; ~i; i--)
        {
            suffT[i] += suffT[i + 1];
            suffCT[i] += suffCT[i + 1];
            if(s[i] == 'T') suffT[i]++;
            else if(s[i] == 'C') suffCT[i] += suffT[i];
        }
        long long preL = 0, preLC = 0, best = 0;
        // we are not counting all of LCT, just the gain, hence we multiply such that there is only one character addition, rest we will add the cntLCT that 
        // we calculated at the starting
        for(int i = 0; i <= n; i++)
        {
            // insert an L at the current position
            best = max(best, suffCT[i]);
            // insert a C at the current position
            best = max(best, preL * suffT[i]);
            // insert a T at the current position
            best = max(best, preLC);

            if(i < n)
            {
                if(s[i] == 'L') preL++;
                else if(s[i] == 'C') preLC += preL;
            }
        }
        return cntLCT + best;
    }
};
