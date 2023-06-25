bool checkD(vector<int>& vec, int d, int mid)
{
    int i = 0, n = vec.size();
    while(d--)
    {
        int sum = 0;
        while(i < n && sum + vec[i] < mid)
            sum += vec[i++];
    }
    if(i == n)
        return true;
    else
        return false;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int s = *min_element(weights.begin(), weights.end());
    int e = accumulate(weights.begin(), weights.end(),0);
    while(s <= e)
    {
        int mid = (s + e) / 2;
        if(checkD(weights, d, mid))
            e = mid - 1;
        else
            s = mid + 1;
    }
    return e;
}
