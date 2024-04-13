int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> area(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++)
        {
            int n = matrix[i].size();
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || (matrix[i][j] != '0'))
                    area[j] += (matrix[i][j] - '0');
                else
                    area[j] = 0;
            }
            stack<int> st;
            // next smaller right
            vector<int> h(area);
            for(int j = n - 1; ~j; j--){
                while(!st.empty() && area[st.top()] >= area[j]) 
                    st.pop();
                h[j] = (st.empty()? n : st.top());
                st.push(j);
            }
            while(!st.empty())  st.pop();
            for(int j = 0; j < n; j++){
                while(!st.empty() && area[st.top()] >= area[j])
                    st.pop();
                h[j] -= (st.empty()? 0 : st.top() + 1);
                if(h[j] > 0)
                    h[j] *= area[j];
                else 
                    h[j] = area[j];
                st.push(j);
            }
            maxArea = max(maxArea, *max_element(h.begin(), h.end()));
        }
        return maxArea;
    }
