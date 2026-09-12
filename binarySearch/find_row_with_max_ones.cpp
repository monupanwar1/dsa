#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix)
{
  // brute force
  int n = matrix.size();
  int m = matrix[0].size();

  int row = 0;
  int maxSum = 0;

  for (int i = 0; i < n; i++)
  {
    int rowSum = 0;
    for (int j = 0; j < m; j++)
    {
      rowSum += matrix[i][j];
    }
    if (rowSum > maxSum)
    {
      maxSum = rowSum;
      row = i;
    }
  }

  return row;
}

int rowWithMax1sBS(vector<vector<int>> &matrix)
{
  // BS
  int n = matrix.size();
  int m = matrix[0].size();

  int maxOnes = 0;
  int row = -1;

  int low = 0;
  int high = m - 1;

  for (int i = 0; i < n; i++)
  {
    int low = 0;
    int high = m - 1;
    int firstOne = m;

    while (low <= high)
    {
      int mid = low+(high - low) / 2;

      if (matrix[i][mid] == 1)
      {
        firstOne = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    int ones = m - firstOne;
    if (ones > maxOnes)
    {
      maxOnes = ones;
      row = i;
    }
  }
  return row;
}

int main()
{
  vector<vector<int>> matrix = {
      {0, 0, 1, 1},
      {0, 1, 1, 1},
      {0, 0, 0, 1},
      {0, 0, 0, 0}};

  cout << rowWithMax1s(matrix) << endl;
  cout << rowWithMax1sBS(matrix) << endl;

  return 0;
}