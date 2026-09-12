#include <iostream>
#include <vector>
using namespace std;

int maxElementRow(vector<vector<int>> &matrix, int col)
{
  int n = matrix.size();
  int row = 0;

  for (int i = 1; i < n; i++)
  {
    if (matrix[i][col] > matrix[row][col])
    {
      row = i;
    }
  }
  return row;
}

pair<int, int> findPeakElement(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int low = 0;
  int high = m - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    int row = maxElementRow(matrix, mid);

    int left = (mid-1 >= 0) ? matrix[row][mid - 1] : -1;
    int right = (mid + 1 < m) ? matrix[row][mid + 1] : -1;

    if (matrix[row][mid] > left &&
        matrix[row][mid] > right)
    {
      return {row, mid};
    }

    if (left > matrix[row][mid])
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

int main()
{
  vector<vector<int>> matrix = {
      {10, 8, 10, 10},
      {14, 13, 12, 11},
      {15, 9, 11, 21},
      {16, 17, 19, 20}};

  pair<int, int> ans = findPeakElement(matrix);

  cout << "Peak at: (" << ans.first << ", "
       << ans.second << ")" << endl;

  cout << "Value: "
       << matrix[ans.first][ans.second] << endl;

  return 0;
}