#include <iostream>
#include <vector>
using namespace std;

pair<int, int> searchElement2D(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == target)
      {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

pair<int, int> searchElement2DFlaten(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int low = 0;
  int high = n * m - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    int row = mid / m;
    int col = mid % m;

    if (matrix[row][col] == target)
    {
      return {row, col};
    }
    if (matrix[row][col] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return {-1, -1};
}

pair<int, int> searchElement2DBS(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++)
  {
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (matrix[i][mid] == target)
      {
        return {i, mid};
      }
      if (matrix[i][mid] > target)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
  }
  return {-1, -1};
}

int main()
{
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}};

  int target = 16;

  pair<int, int> ans = searchElement2D(matrix, target);
  cout << ans.first << " " << ans.second << endl;

  pair<int, int> ans1 = searchElement2DBS(matrix, target);
  cout << ans1.first << " " << ans1.second << endl;

  pair<int, int> ans2 = searchElement2DFlaten(matrix, target);
  cout << ans2.first << " " << ans2.second;

  return 0;
}