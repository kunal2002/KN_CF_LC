class Solution {
public:
    class element{
    public:
    int value;
    int row;
    int index;
    int n;
    element(int val,int r,int idx, int sz)
    {
        value = val;
        row = r;
        index = idx;
        n = sz;
    }
};
    struct comp
    {
        bool operator()(element a,element b)
        {
            return (a.value > b.value);
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<element,vector<element>,comp> pq;
        int minn = INT_MAX, maxx = INT_MIN, range = INT_MAX;
        int k = nums.size();
        int low,high;
        for(int i = 0; i < k; i++)
        {
            //sort(nums[i].begin(),nums[i].end());
            pq.push(element(nums[i][0],i,0,nums[i].size()));
            minn = min(minn,nums[i][0]);
            maxx = max(maxx,nums[i][0]);
        }
        //range = maxx - minn;
        while(!pq.empty())
        {
            element t = pq.top();
            pq.pop();
            int temp = t.value;
            if(range > maxx - temp)
            {
                minn = t.value;
                range = maxx - temp;
                low = temp;
                high = maxx;
            }
            //reached end of an array list, break out of the priority_queue
            if(t.index == t.n - 1)
                break;
            t.index += 1;
            pq.push(element(nums[t.row][t.index],t.row,t.index,t.n));
            maxx = max(maxx,nums[t.row][t.index]);
        }
        vector<int> result;
        result.push_back(low);
        result.push_back(high);
        return result;
        }
};
