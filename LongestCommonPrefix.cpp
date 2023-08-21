string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        int n = strs.size();
        string str = strs[0];
        string ans = "";
        int j = 0;
        while(true)
        {
            int flag = 0;
            for(int i = 1; i < n; i++)
            {
                int mini_sz = min(str.size(), strs[i].size());
                if(j < mini_sz && strs[i][j] == str[j])
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
            ans += str[j];
            j++;
        }
        
        return ans;
    }
