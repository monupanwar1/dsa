#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateM(vector<vector<int>> &arr)
{
  int n = arr.size();
  int col = arr[0].size();

  vector<vector<int>> ans(col, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < col; j++)
    {
      ans[j][n - i - 1] = arr[i][j];
    }
  }

  return ans;
}

int main()

{
  vector<vector<int>> arr = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  vector<vector<int>> ans = rotateM(arr);
  for (auto row : ans)
  {
    for (auto it : row)
    {
      cout << it << " ";
    }
    cout << endl;
  }
}