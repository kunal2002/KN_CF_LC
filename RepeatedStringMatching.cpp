int repeatedStringMatch(string a, string b) {
        string str = a;
        int times = (int)b.size() / (int) a.size();
        times += 2;
        int cnt = 1;
        for(int i = 0; i < times; i++)
        {
            if(str.find(b) != string::npos)
                return cnt;
            else
            {
                str += a;
                cnt++;
            }
        }
        return -1;
    }
