class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq;
        queue<int> dq;
        int n = senate.size();
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);
        }
        while(!rq.empty() && !dq.empty())
        {
            int r_ele = rq.front(), d_ele = dq.front();
            rq.pop();
            dq.pop();
            if(r_ele < d_ele)
                rq.push(r_ele + n);
            else
                dq.push(d_ele + n);
        }
        if(rq.empty())
            return "Dire";
        return "Radiant";
    }
};
