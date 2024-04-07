bool check(vector<int>& vec, int mid, int k)
{
    k--;
    int en = vec[0];
    for(int i = 1; i < vec.size(); i++)
    {
        if(mid <= (vec[i] - en)){
            en = vec[i];
            k--;
        }
        if(!k)  return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int st = 1, en = stalls[stalls.size() - 1] - stalls[0];
    while(st <= en)
    {
        int mid = (st + en) >> 1;
        // cout << st << " " << en << " " << mid << "\n";
        if(check(stalls, mid, k))
            st = mid + 1;
        else    
            en = mid - 1;
    }
    return en;
}
