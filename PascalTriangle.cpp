#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<long long int> res;
  res.push_back(1);
  vector<vector<long long int>> ans;
  ans.push_back(res);
  res.clear();
  for(int i = 1; i < n; i++)
  {
      res.push_back(1);
      for(int j = 1; j < i; j++)
      {
          res.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
      }
      res.push_back(1);
      ans.push_back(res);
      res.clear();
  }
  return ans;
}
