bool ValidCorner(const vector<vector<int> >& matrix)
    {
        // Your code goes here
        // O(N^4)
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 1)
                {
                    for(int k = i + 1; k < row; k++) // going down in the same column where we found 1
                    {
                        if(matrix[k][j] == 1)
                        {
                            for(int l = j + 1; l < col; l++) // going forward in the same column where we got 1
                            {
                                if(matrix[k][l] == 1 && matrix[i][l] == 1)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
