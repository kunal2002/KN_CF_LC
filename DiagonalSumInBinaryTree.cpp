void rec(Node* root, int vd, vector<int>& ans)
{
    if(!root) return;
    if(vd >= ans.size())
        ans.resize(vd + 1);
    ans[vd] += root->data;
    rec(root->right, vd, ans);
    rec(root->left, vd + 1, ans);
}
vector <int> diagonalSum(Node* root) {
    // Add your code here
    int vd = 0; //vertical distance
    vector<int> res;
    rec(root, 0, res);
    return res;
}
