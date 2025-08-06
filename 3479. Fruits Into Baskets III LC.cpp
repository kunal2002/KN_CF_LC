class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& segmentTree)
    {
        if(l == r)
        {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2*i + 1, l, mid, baskets, segmentTree);
        build(2*i + 2, mid + 1, r, baskets, segmentTree);
        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);
    }
    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int fruit)
    {
        if(segmentTree[i] < fruit)
            return false;
        if(l == r)
            return (segmentTree[i] >= fruit ? segmentTree[i] = -1 : false);
        bool placed = false;
        int mid = l + (r - l) / 2;
        if(segmentTree[2*i + 1] >= fruit)
            placed = querySegmentTree(2*i + 1, l, mid, segmentTree, fruit);
        else
            placed = querySegmentTree(2*i + 2, mid + 1, r, segmentTree, fruit);
        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4 * n, -1);
        // i = 0, l = 0, r = n - 1
        build(0, 0, n - 1, baskets, segmentTree);
        int unplaced = 0;
        for(int i = 0; i < n; i++)
        {
            if(querySegmentTree(0, 0, n - 1, segmentTree, fruits[i]) == false)
                unplaced++;
        }
        return unplaced;
    }
};
