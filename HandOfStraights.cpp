class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize)
            return false;
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        map<int,int> mp;
        int n = hand.size();
        for(int i = 0; i < n; i++)
            mp[hand[i]]++;
        for(auto x : mp)
        {
            // cout << x.first << " " << x.second << "\n";
            pq.push({x.first, x.second});
        }   
        while(!pq.empty())
        {
            vector<pair<int,int>> vec;
            auto ele = pq.top();
            pq.pop();
            int consec = ele.first;
            int occur = ele.second - 1;
            if(occur != 0)
                vec.push_back({consec, occur});
            for(int j = 0; j < groupSize - 1; j++)
            {
                auto next = pq.top();
                pq.pop();
                int c = next.first;
                int o = next.second - 1;
                if(o != 0)
                    vec.push_back({c, o});
                if((c - consec) != 1)
                    return false;
                consec = c;
            }
            for(auto x: vec)
            {
                // cout << x.first << " " << x.second << "\n";
                pq.push(x);
            }
        }
        return true;
    }
};
