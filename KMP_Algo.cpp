void CalcLPS(string& pat, vector<int>& LPS)
        {
            int len = 0;
            LPS[0] = 0;
            int i = 1;
            while(i < pat.size())
            {
                if(pat[i] == pat[len])
                {
                    len++;
                    LPS[i] = len;
                    i++;
                }
                else
                {
                    if(len != 0)
                        len = LPS[len - 1];
                    else
                    {
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            int N = txt.size();
            int M = pat.size();
            vector<int> LPS(M);
            CalcLPS(pat, LPS);
            int i = 0, j = 0;
            vector<int> res;
            while(i < N)
            {
                if(txt[i] == pat[j])
                {
                    i++, j++;
                }
                if(j == M)
                {
                    res.push_back(i - M + 1);
                    j = LPS[j - 1];
                }
                else if(txt[i] != pat[j])
                {
                    if(j != 0)
                        j = LPS[j - 1];
                    else
                        i++;
                }
            }
            return res;
        }
