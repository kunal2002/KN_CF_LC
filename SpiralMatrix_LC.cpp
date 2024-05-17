class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int top = 1, bottom = n, left = 0, right = m;
        while(left < right)
        {
            while(j < right)
                ans.push_back(matrix[i][j++]);
            j--;
            right--;
            i++;
            if(top >= bottom)
                break;
            while(i < bottom)
                ans.push_back(matrix[i++][j]);
            i--;
            bottom--;
            j--;
            if(left >= right)
                break;
            while(j >= left)
                ans.push_back(matrix[i][j--]);
            j++;
            left++;
            i--;
            if(top >= bottom)
                break;
            while(i >= top)
                ans.push_back(matrix[i--][j]);
            i++;
            top++;
            j++;
        }
        return ans;
    }
};
