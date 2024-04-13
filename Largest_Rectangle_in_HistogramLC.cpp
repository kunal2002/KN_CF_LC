int largestRectangleArea(vector<int>& heights) {
        vector<int> area = heights; 
        int n = heights.size();
        stack<int> st;
        // next smaller right
        for(int i = n - 1; ~i; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            area[i] = (st.empty()? n : st.top());
            st.push(i);
        }
        while(!st.empty())  st.pop();
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            area[i] -= (st.empty()? 0 : st.top() + 1);
            if(area[i] > 0)
                area[i] *= heights[i];
            else 
                area[i] = heights[i];
            st.push(i);
        }
        return *max_element(area.begin(), area.end());
    }
