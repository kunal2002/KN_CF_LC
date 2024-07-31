class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        deque<int> pos;
        sort(deck.begin(), deck.end());
        for(int i = 0; i < n; i++){
            pos.push_back(i);
        }
        for(int x : deck){
            int idx = pos.front(); 
            pos.pop_front();
            ans[idx] = x;
            if(!pos.empty()){
                pos.push_back(pos.front());
                pos.pop_front();
            }
        }
        return ans;
    }
};
