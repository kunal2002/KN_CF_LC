int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> vec;
        for(int i = 0; i < n; i++)
            vec.push_back({aliceValues[i] + bobValues[i], i});
        sort(vec.rbegin(), vec.rend());
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            int ind = vec[i].second;
            if(i%2)
                b += bobValues[ind];
            else
                a += aliceValues[ind]; 
        }
        if(a > b)   return 1;
        else if(b > a) return -1;
        return 0;
    }
