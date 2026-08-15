#include <iostream>
#include <vector>
using namespace std;

vector<int> sprialMatrix(vector<vector<int>> &matrix, int row, int col)
{

  vector<int> ans;
  int top = 0;
  int right = col - 1;
  int left = 0;
  int bottom = row - 1;

  while (top <= bottom && left <= right)
  {
    for (int i = left; i <= right; i++)
    {
      ans.push_back(matrix[top][i]);
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
      ans.push_back(matrix[i][right]);
    }
    right--;
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    // bottom -> top
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  return ans;
}

int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};

  int row = matrix.size();
  int col = matrix[0].size();

  vector<int> ans = sprialMatrix(matrix, row, col);

  for (auto it : ans)
  {
    cout << it << " ";
  }
}