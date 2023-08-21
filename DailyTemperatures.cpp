stack<int> st; // monotonic stack
        int n = temperatures.size();
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push(i);
                ans.push_back(0);
            }
            else
            {
                while(!st.empty())
                {
                    int ind = st.top();
                    if(temperatures[ind] > temperatures[i])
                    {
                        ans.push_back(ind - i);
                        st.push(i);
                        break;
                    }
                    else
                        st.pop();
                    if(st.empty())
                    {
                        st.push(i);
                        ans.push_back(0);
                        break;
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
