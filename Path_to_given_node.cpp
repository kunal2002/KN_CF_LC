bool Kunal(TreeNode* A, vector<int>& res, int B)
 {
     if(A == NULL)
        return false;
    res.push_back(A->val);
    if(Kunal(A->left, res, B) || Kunal(A->right, res, B))
        return true;
    if(A->val == B)
        return true;
    res.pop_back();
    return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if(A == NULL)
        return res;
    bool hey = Kunal(A, res, B);  
    return res;     
}
