class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row_top = 0, row_bottom = n - 1, col_left = 0, col_right = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cnt = 1;
        while(true)
        {
            for(int i = col_left; i <= col_right; i++)
            {
                ans[row_top][i] = cnt++;
            }
            row_top++;
            if (row_top > row_bottom || col_left > col_right) {
                break;
            }
            for(int i = row_top; i <= row_bottom; i++)
            {
                ans[i][col_right] = cnt++;
            }
            col_right--;
            if (row_top > row_bottom || col_left > col_right) {
                break;
            }
            for(int i = col_right; i >= col_left; i--)
            {
                ans[row_bottom][i] = cnt++;
            }
            row_bottom--;
            if (row_top > row_bottom || col_left > col_right) {
                break;
            }
            for(int i = row_bottom; i >= row_top; i--)
            {
                ans[i][col_left] = cnt++;
            }
            col_left++;
            if (row_top > row_bottom || col_left > col_right) {
                break;
            }
        }   
        return ans;
    }
};
