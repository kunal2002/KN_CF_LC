class Solution {
public:
    auto z_algo(string& str)
    {
        int sz = str.size();
        int l = 0, r = 0;
        vector<int> vec(sz, 0);
        for(int i = 1; i < sz; i++)
        {
            if(i > r)
            {
                l = r = i;
                while(r < sz && str[r] == str[r - l])
                    r++;
                vec[i] = r - l;
                r--;
            }
            else
            {
                int idx = i - l;
                if(i + vec[idx] <= r)
                    vec[i] = vec[idx];
                else
                {
                    l = i; 
                    while(r < sz && str[r] == str[r - l])
                        r++;
                    vec[i] = r - l;
                    r--;
                }
            }
        }
        return vec;
    }
    int minimumTimeToInitialState(string word, int k) {
        auto z = z_algo(word);
        int n = word.size();
        int pos = 1;
        while(pos * k < n && (z[pos * k] < n - pos * k))
            pos++;
        return pos;
    }
};
