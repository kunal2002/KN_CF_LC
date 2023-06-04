#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	vector<pair<int,int>> cell;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 0)
                    cell.push_back({i,j});
            }
        }
        set<int> r;
        set<int> c;
        for(auto x: cell)
        {
            r.insert(x.first);
            c.insert(x.second);
        }
        for(auto x: r)
        {
            for(int i = 0; i < col; i++)
                matrix[x][i] = 0;
        }
        for(auto x: c)
        {
            for(int i = 0; i < row; i++)
                matrix[i][x] = 0;
        }
}
