#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach
int median(vector<vector<int>> &matrix)
{
  vector<int> ans;

  int rows = matrix.size();
  int cols = matrix[0].size();

  // Flatten matrix
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      ans.push_back(matrix[i][j]);
    }
  }

  // Sort
  sort(ans.begin(), ans.end());

  // Median
  int n = ans.size();

  if (n % 2 == 1)
  {
    return ans[n / 2];
  }

  return (ans[n / 2 - 1] + ans[n / 2]) / 2;
}

// Count elements <= target in a sorted row
int countLessEqual(vector<int> &row, int target)
{
  int low = 0;
  int high = row.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (row[mid] <= target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return low;
}

// Binary Search Approach
int median2(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();

  int low = matrix[0][0];
  int high = matrix[rows - 1][cols - 1];

  int required = (rows * cols) / 2;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int count = 0;

    // Binary search in every row
    for (int i = 0; i < rows; i++)
    {
      count += countLessEqual(matrix[i], mid);
    }

    if (count <= required)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return low;
}


int main()
{
  vector<vector<int>> matrix = {
      {1, 3, 5},
      {2, 6, 9},
      {3, 6, 9}};

  cout << median(matrix) << endl;
  cout << median2(matrix) << endl;

  return 0;
}