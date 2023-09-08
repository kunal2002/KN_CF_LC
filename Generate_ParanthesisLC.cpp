class Solution {
public:
    //Backtracking Solution
    vector<string> vec;
    void rec(int open, int close, string str, int n)
    {
        if(open > n || close > n)
            return;
        if(open == n && close == n)
        {
            vec.push_back(str);
            return;
        }
        if(close < open)
        {
            rec(open, close + 1, str + ')', n);
        }
        rec(open + 1, close, str + '(', n);
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        rec(0, 0, str, n);
        return vec;
    }
};
