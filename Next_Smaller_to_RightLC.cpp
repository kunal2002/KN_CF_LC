vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices; 
        int n = prices.size();
        stack<int> st;
        for(int i = n - 1; ~i; i--){
            while(!st.empty() && st.top() > prices[i]) 
                st.pop();
            ans[i] -= (st.empty()? 0 : st.top());
            st.push(prices[i]);
        }
        return ans;
    }
//1475. Final Prices With a Special Discount in a Shop
